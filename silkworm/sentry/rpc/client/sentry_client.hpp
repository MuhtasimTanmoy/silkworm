/*
   Copyright 2023 The Silkworm Authors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#pragma once

#include <memory>
#include <string>

#include <agrpc/detail/forward.hpp>

#include <silkworm/sentry/api/api_common/service.hpp>

namespace silkworm::sentry::rpc::client {

// TODO: move to a common place for all clients
struct ISentryClient {
    virtual ~ISentryClient() = default;

    virtual std::shared_ptr<api::api_common::Service> service() = 0;
};

class SentryClientImpl;

class SentryClient : public ISentryClient {
  public:
    explicit SentryClient(const std::string& address_uri, agrpc::GrpcContext& grpc_context);
    ~SentryClient() override;

    SentryClient(SentryClient&&) = default;
    SentryClient& operator=(SentryClient&&) = default;

    std::shared_ptr<api::api_common::Service> service() override;

  private:
    std::shared_ptr<SentryClientImpl> p_impl_;
};

}  // namespace silkworm::sentry::rpc::client