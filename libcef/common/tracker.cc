// Copyright (c) 2012 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "cef/libcef/common/tracker.h"

// CefTrackNode implementation.

CefTrackNode::CefTrackNode() = default;

CefTrackNode::~CefTrackNode() = default;

void CefTrackNode::InsertTrackPrev(CefTrackNode* object) {
  if (track_prev_) {
    track_prev_->SetTrackNext(object);
  }
  object->SetTrackNext(this);
  object->SetTrackPrev(track_prev_);
  track_prev_ = object;
}

void CefTrackNode::InsertTrackNext(CefTrackNode* object) {
  if (track_next_) {
    track_next_->SetTrackPrev(object);
  }
  object->SetTrackPrev(this);
  object->SetTrackNext(track_next_);
  track_next_ = object;
}

void CefTrackNode::RemoveTracking() {
  if (track_next_) {
    track_next_->SetTrackPrev(track_prev_);
  }
  if (track_prev_) {
    track_prev_->SetTrackNext(track_next_);
  }
  track_next_ = nullptr;
  track_prev_ = nullptr;
}

// CefTrackManager implementation.

CefTrackManager::CefTrackManager() = default;

CefTrackManager::~CefTrackManager() {
  DeleteAll();
}

void CefTrackManager::Add(CefTrackNode* object) {
  base::AutoLock lock_scope(lock_);
  if (!object->IsTracked()) {
    tracker_.InsertTrackNext(object);
    ++object_count_;
  }
}

bool CefTrackManager::Delete(CefTrackNode* object) {
  base::AutoLock lock_scope(lock_);
  if (object->IsTracked()) {
    object->RemoveTracking();
    delete object;
    --object_count_;
    return true;
  }
  return false;
}

void CefTrackManager::DeleteAll() {
  base::AutoLock lock_scope(lock_);
  CefTrackNode* next;
  do {
    next = tracker_.GetTrackNext();
    if (next) {
      next->RemoveTracking();
      delete next;
    }
  } while (next != nullptr);
  object_count_ = 0;
}
