// Copyright (c) 2020 by Robert Bosch GmbH. All rights reserved.
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

#include "iceoryx_dds/dds/dds_types.hpp"
#include "iceoryx_dds/gateway/channel.hpp"
#include "iceoryx_posh/capro/service_description.hpp"

#include "test.hpp"

using namespace ::testing;
using ::testing::_;

// ======================================== Helpers ======================================== //
// We do not need real channel terminals to test the base class.
struct StubbedIceoryxTerminal
{
    StubbedIceoryxTerminal(iox::capro::ServiceDescription sd){};
};

struct StubbedDDSTerminal
{
    StubbedDDSTerminal(iox::dds::IdString sid, iox::dds::IdString iid, iox::dds::IdString eid){};
};

using TestChannel = iox::dds::Channel<StubbedIceoryxTerminal, StubbedDDSTerminal>;

// ======================================== Fixture ======================================== //
class ChannelTest : public Test
{
  public:
    void SetUp(){};
    void TearDown(){};
};

// ======================================== Tests ======================================== //
TEST_F(ChannelTest, ReturnsEmptyOptionalIfObjectPoolExhausted)
{
    auto channel = iox::dds::Channel<StubbedIceoryxTerminal, StubbedDDSTerminal>::create({"", "", ""});
}