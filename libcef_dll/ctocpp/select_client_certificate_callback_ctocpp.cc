// Copyright (c) 2024 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=f2c75557e03ed0b788372f3e1b57e3a70e4ca736$
//

#include "libcef_dll/ctocpp/select_client_certificate_callback_ctocpp.h"

#include "libcef_dll/ctocpp/x509certificate_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void CefSelectClientCertificateCallbackCToCpp::Select(
    CefRefPtr<CefX509Certificate> cert) {
  shutdown_checker::AssertNotShutdown();

  cef_select_client_certificate_callback_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, select)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: cert

  // Execute
  _struct->select(_struct, CefX509CertificateCToCpp::Unwrap(cert));
}

// CONSTRUCTOR - Do not edit by hand.

CefSelectClientCertificateCallbackCToCpp::
    CefSelectClientCertificateCallbackCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefSelectClientCertificateCallbackCToCpp::
    ~CefSelectClientCertificateCallbackCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_select_client_certificate_callback_t*
CefCToCppRefCounted<CefSelectClientCertificateCallbackCToCpp,
                    CefSelectClientCertificateCallback,
                    cef_select_client_certificate_callback_t>::
    UnwrapDerived(CefWrapperType type, CefSelectClientCertificateCallback* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<
    CefSelectClientCertificateCallbackCToCpp,
    CefSelectClientCertificateCallback,
    cef_select_client_certificate_callback_t>::kWrapperType =
    WT_SELECT_CLIENT_CERTIFICATE_CALLBACK;
