// Copyright (c) 2024 by Mathias Kraus <elboberido@m-hias.de>. All rights reserved.
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

#include "iceoryx_posh/iceoryx_posh_types.hpp"

#include <atomic>

namespace iox
{

ResourcePrefix_t iceoryxResourcePrefix(const DomainId domainId, const ResourceType resourceType) noexcept
{
    static_assert(std::is_same_v<uint16_t, DomainId::value_type>,
                  "Please adjust 'MAX_UINT16_WIDTH' to the new fixed width type to have enough space for the "
                  "stringified Domain ID");
    constexpr auto MAX_UINT16_WIDTH{5};

    uint16_t usedDomainId = static_cast<DomainId::value_type>(domainId);
    if (!experimental::hasExperimentalPoshFeaturesEnabled())
    {
        usedDomainId = static_cast<DomainId::value_type>(DEFAULT_DOMAIN_ID);
    }
    iox::string<MAX_UINT16_WIDTH> uniqueDomainIdString{TruncateToCapacity,
                                                       iox::convert::toString(usedDomainId).c_str()};

    auto resourceTypeString{resourceType == ResourceType::ICEORYX_DEFINED ? iox::string<1>{"i"} : iox::string<1>{"u"}};
    return concatenate(ICEORYX_RESOURCE_PREFIX, "_", uniqueDomainIdString, "_", resourceTypeString, "_");
}

namespace experimental
{
bool hasExperimentalPoshFeaturesEnabled(const optional<bool>& newValue) noexcept
{
    static std::atomic<bool> experimentalEnabled{build::IOX_EXPERIMENTAL_POSH_FLAG};

    if (newValue.has_value())
    {
        experimentalEnabled.store(newValue.value(), std::memory_order_relaxed);
    }

    return experimentalEnabled.load(std::memory_order_relaxed);
}
} // namespace experimental
} // namespace iox
