#include "stats.h"
#include <iostream>
#include <algorithm>

Stats::Stats()
{
  methodTypes.resize(5);
  methodTypes = {
                  "GET",
                  "PUT",
                  "POST",
                  "DELETE",
                  "UNKNOWN"
                 };
  uriTypes.resize(6);
  uriTypes = {
                "/",
                "/order",
                "/product",
                "/basket",
                "/help",
                "unknown"
              };
  for(const auto& method : methodTypes){
    methodStats[method] = 0;
  }
  for(const auto& uri : uriTypes){
    methodStats[uri] = 0;
  }
}

HttpRequest ParseRequest(string_view line)
{
  vector<string_view> parts(3);
  string_view delimiter = " ";
  string_view token;
  size_t counter = 0;

 // auto pos = find_if(line.begin(), line.end(), bind1st(std::not_equal_to<char>(), ' '));
  //line = line.substr(0, );

  while(token != line){
    token = line.substr(0,line.find_first_of(delimiter));
    line = line.substr(line.find_first_of(delimiter) + 1);
    parts.push_back(token);
  }
  for(const auto& i : parts){
    static int j = 1;
    cout << i << endl;
    if(j++ % 3 == 0)
      cout << "---------------------------------" << endl;
  }
  HttpRequest request = {parts.at(0), parts.at(1), parts.at(2)};
  return request;
}


void Stats::AddMethod(string_view method)
{
  this->methodStats[method]++;
}

void Stats::AddUri(string_view uri)
{
  this->uriStats[uri]++;
}

const map<string_view, int> &Stats::GetMethodStats() const
{
  return  methodStats;
}

const map<string_view, int> &Stats::GetUriStats() const
{
  return  uriStats;
}
