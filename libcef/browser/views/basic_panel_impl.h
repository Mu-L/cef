// Copyright 2016 The Chromium Embedded Framework Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#ifndef CEF_LIBCEF_BROWSER_VIEWS_BASIC_PANEL_IMPL_H_
#define CEF_LIBCEF_BROWSER_VIEWS_BASIC_PANEL_IMPL_H_
#pragma once

#include "cef/include/views/cef_panel.h"
#include "cef/include/views/cef_panel_delegate.h"
#include "cef/libcef/browser/views/panel_impl.h"
#include "ui/views/view.h"

class CefBasicPanelImpl
    : public CefPanelImpl<views::View, CefPanel, CefPanelDelegate> {
 public:
  using ParentClass = CefPanelImpl<views::View, CefPanel, CefPanelDelegate>;

  CefBasicPanelImpl(const CefBasicPanelImpl&) = delete;
  CefBasicPanelImpl& operator=(const CefBasicPanelImpl&) = delete;

  // Create a new CefPanel instance. |delegate| may be nullptr.
  static CefRefPtr<CefBasicPanelImpl> Create(
      CefRefPtr<CefPanelDelegate> delegate);

  // CefViewAdapter methods:
  std::string GetDebugType() override { return "Panel"; }

 private:
  // Create a new implementation object.
  // Always call Initialize() after creation.
  // |delegate| may be nullptr.
  explicit CefBasicPanelImpl(CefRefPtr<CefPanelDelegate> delegate);

  // CefViewImpl methods:
  views::View* CreateRootView() override;
  void InitializeRootView() override;

  IMPLEMENT_REFCOUNTING_DELETE_ON_UIT(CefBasicPanelImpl);
};

#endif  // CEF_LIBCEF_BROWSER_VIEWS_BASIC_PANEL_IMPL_H_
