/*
 *  Copyright (c) 2015, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

namespace facebook { namespace memcache {

class McReply;
class McRequest;

namespace mcrouter {

class proxy_t;

class ProxyRequestLogger {
 public:
  explicit ProxyRequestLogger(proxy_t* proxy)
    : proxy_(proxy) {
  }

  template <class Operation>
  void log(const McRequest& request,
           const McReply& reply,
           const int64_t startTimeUs,
           const int64_t endTimeUs,
           Operation);

 protected:
  proxy_t* proxy_;

  inline void logError(const McReply& reply);
};

}}}  // facebook::memcache::mcrouter

#include "ProxyRequestLogger-inl.h"
