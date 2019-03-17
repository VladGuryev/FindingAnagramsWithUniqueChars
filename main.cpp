#include "test_runner.h"
#include "tests.cpp"

using namespace std;

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestGroupingABC);
  RUN_TEST(tr, TestGroupingReal);

  return 0;
}
