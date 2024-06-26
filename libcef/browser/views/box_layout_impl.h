// Copyright 2016 The Chromium Embedded Framework Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#ifndef CEF_LIBCEF_BROWSER_VIEWS_BOX_LAYOUT_IMPL_H_
#define CEF_LIBCEF_BROWSER_VIEWS_BOX_LAYOUT_IMPL_H_
#pragma once

#include "cef/include/views/cef_box_layout.h"
#include "cef/libcef/browser/views/layout_impl.h"
#include "ui/views/layout/box_layout.h"

class CefBoxLayoutImpl : public CefLayoutImpl<views::BoxLayout, CefBoxLayout> {
 public:
  // Necessary for the CEF_REQUIRE_VALID_*() macros to compile.
  using ParentClass = CefLayoutImpl<views::BoxLayout, CefBoxLayout>;

  CefBoxLayoutImpl(const CefBoxLayoutImpl&) = delete;
  CefBoxLayoutImpl& operator=(const CefBoxLayoutImpl&) = delete;

  // Create a new CefBoxLayout insance. |owner_view| must be non-nullptr.
  static CefRefPtr<CefBoxLayoutImpl> Create(
      const CefBoxLayoutSettings& settings,
      views::View* owner_view);

  // CefBoxLayout methods:
  void SetFlexForView(CefRefPtr<CefView> view, int flex) override;
  void ClearFlexForView(CefRefPtr<CefView> view) override;

  // CefLayout methods:
  CefRefPtr<CefBoxLayout> AsBoxLayout() override { return this; }

 private:
  explicit CefBoxLayoutImpl(const CefBoxLayoutSettings& settings);

  views::BoxLayout* CreateLayout() override;

  CefBoxLayoutSettings settings_;

  IMPLEMENT_REFCOUNTING_DELETE_ON_UIT(CefBoxLayoutImpl);
};

#endif  // CEF_LIBCEF_BROWSER_VIEWS_BOX_LAYOUT_IMPL_H_
