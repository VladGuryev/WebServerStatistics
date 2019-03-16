#include "test_runner.h"
#include "http_request.h"
#include "stats.h"
#include "tests.cpp"

#include <map>
#include <experimental/string_view>
//#include <string_view>
using namespace std;
using namespace std::experimental;

Stats ServeRequests(istream& input) {
  Stats result;
  for (string line; getline(input, line); ) {
    const HttpRequest req = ParseRequest(line);
    result.AddUri(req.uri);
    result.AddMethod(req.method);
  }
  return result;
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestBasic);
  RUN_TEST(tr, TestAbsentParts);
}
