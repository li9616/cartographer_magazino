/*
 * Copyright 2016 The Cartographer Authors
 *           2018 Magazino GmbH
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
 */

#include <string>
#include <vector>

#include "cartographer_ros/node_options.h"
#include "gtest/gtest.h"
#include "ros/package.h"

namespace cartographer_ros {
namespace {

class ConfigurationFilesTest : public ::testing::TestWithParam<const char*> {};

TEST_P(ConfigurationFilesTest, ValidateNodeOptions) {
  EXPECT_NO_FATAL_FAILURE({
    LoadOptions(
        ::ros::package::getPath("cartographer_toru") + "/configuration_files",
        GetParam());
  });
}

INSTANTIATE_TEST_CASE_P(ValidateAllNodeOptions, ConfigurationFilesTest,
                        ::testing::Values("toru.lua",
                                          "toru_simulation.lua",
                                          "toru_localization.lua"));

}  // namespace
}  // namespace cartographer_ros