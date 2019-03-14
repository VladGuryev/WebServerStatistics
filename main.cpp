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
  //TestRunner tr;
  //RUN_TEST(tr, TestBasic);
  //RUN_TEST(tr, TestAbsentParts);
  const string input =
    R"(GET / HTTP/1.1
    POST /order HTTP/1.1
    POST /product HTTP/1.1
    POST /product HTTP/1.1
    POST /product HTTP/1.1
    GET /order HTTP/1.1
    PUT /product HTTP/1.1
    GET /basket HTTP/1.1
    DELETE /product HTTP/1.1
    GET / HTTP/1.1
    GET / HTTP/1.1
    GET /help HTTP/1.1
    GET /upyachka HTTP/1.1
    GET /unexpected HTTP/1.1
    HEAD / HTTP/1.1)";
  string in = " POST /order HTTP/1.1";
  ParseRequest(in);
  //cout <<  ParseRequest(in).method  << endl ;
//           ParseRequest(in).uri  <<  endl <<
//           ParseRequest(in).protocol << endl;

}
