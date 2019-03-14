#pragma once

#include <experimental/string_view>
using namespace std::experimental;

struct HttpRequest {
  string_view method;
  string_view uri;
  string_view protocol;
};

