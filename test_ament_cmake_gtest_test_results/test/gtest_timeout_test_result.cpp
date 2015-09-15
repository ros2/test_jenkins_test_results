// Copyright 2015 Open Source Robotics Foundation, Inc.
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

#include <chrono>
#include <thread>

#include <gtest/gtest.h>

// if the test is aborted due to a timeout the result file is not
// generated by gtest but by the wrapping run_test.py script
TEST(test_class, test_function_timeout) {
  // flushing stdout ensures that the message is actually printed
  // even when being aborted due to a timeout later
  printf("normal message\n");
  fflush(stdout);
  // the not flushed message will be lost
  printf("normal message #2\n");
  // stderr is implicitly being flushed on newlines
  fprintf(stderr, "error message\n");
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  // the following lines are never reached since the test times out before
  printf("normal message after sleep\n");
  fprintf(stderr, "error message after sleep\n");
}