// Copyright (c) 2022 by Apex.AI Inc. All rights reserved.
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

#include "iceoryx_hoofs/posix_wrapper/scheduler.hpp"
#include "iceoryx_hoofs/internal/log/hoofs_logging.hpp"
#include "iceoryx_hoofs/posix_wrapper/posix_call.hpp"

namespace iox
{
namespace posix
{
int32_t getSchedulerPriorityMinimum(const Scheduler scheduler) noexcept
{
    auto result = posixCall(sched_get_priority_min)(static_cast<int>(scheduler)).failureReturnValue(-1).evaluate();
    if (result.has_error())
    {
        LogError() << "The \"sched_get_priority_min\" should never fail. This can only be caused by an internal logic "
                      "error or a non posix compliant system.";
        return -1;
    }
    return static_cast<int32_t>(result.value().value);
}

int32_t getSchedulerPriorityMaximum(const Scheduler scheduler) noexcept
{
    auto result = posixCall(sched_get_priority_max)(static_cast<int>(scheduler)).failureReturnValue(-1).evaluate();
    if (result.has_error())
    {
        LogError() << "The \"sched_get_priority_max\" should never fail. This can only be caused by an internal logic "
                      "error or a non posix compliant system.";
        return -1;
    }
    return static_cast<int32_t>(result.value().value);
}
} // namespace posix
} // namespace iox
