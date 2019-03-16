#pragma once
#include <map>
#include <array>
using namespace std;

#include <experimental/string_view>
using namespace std::experimental;

#include "http_request.h"

class Stats {
  map<string_view, int> methodStats;
  map<string_view, int> uriStats;
public:
  Stats();
  void AddMethod(string_view method);
  void AddUri(string_view uri);
  const map<string_view, int> &GetMethodStats() const;
  const map<string_view, int> &GetUriStats() const;
};

HttpRequest ParseRequest(string_view line);








