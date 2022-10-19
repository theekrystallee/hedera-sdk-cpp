/*-
 *
 * Hedera C++ SDK
 *
 * Copyright (C) 2020 - 2022 Hedera Hashgraph, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include "Node.h"

#include <proto/crypto_service.grpc.pb.h>

namespace Hedera
{
//-----
Node::Node(const std::string& url, const Hedera::AccountId& accountId)
  : mAccountId(accountId)
  , mAddress(NodeAddress::fromString(url))
  , mChannel(url)
{
}

//-----
std::pair<proto::Response, grpc::Status> Node::submitRequest(const proto::Query& request,
                                                             const std::chrono::duration<double>& timeout)
{
  return mChannel.submitRequest(request, timeout);
}

//-----
// std::pair<proto::TransactionResponse, grpc::Status> Node::submitRequest(const proto::Transaction& request,
//                                                                        const std::chrono::duration<double>& timeout)
//{
//  return mChannel.submitRequest(request, timeout);
//}

//-----
void Node::shutdown()
{
  mChannel.shutdown();
}

} // namespace Hedera