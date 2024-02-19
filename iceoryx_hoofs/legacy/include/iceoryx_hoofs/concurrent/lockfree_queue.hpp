// Copyright (c) 2020 by Robert Bosch GmbH. All rights reserved.
// Copyright (c) 2020 - 2022 by Apex.AI Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef IOX_HOOFS_CONCURRENT_LOCKFREE_QUEUE_HPP
#define IOX_HOOFS_CONCURRENT_LOCKFREE_QUEUE_HPP

#include "iox/detail/deprecation_marker.hpp"
#include "iox/detail/mpmc_lockfree_queue.hpp"

IOX_DEPRECATED_HEADER_SINCE(3, "Please include 'iox/detail/lockfree_queue.hpp' instead.")

namespace iox
{
namespace concurrent
{
template <typename ElementType, uint64_t Capacity>
using LockFreeQueue
    IOX_DEPRECATED_SINCE(3,
                         "Please use 'iox::concurrent::MpmcLockFreeQueue' from "
                         "'iox/detail/lockfree_queue.hpp' instead.") = MpmcLockFreeQueue<ElementType, Capacity>;
}
} // namespace iox

#endif // IOX_HOOFS_CONCURRENT_LOCKFREE_QUEUE_HPP