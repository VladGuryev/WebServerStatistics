#include "stats.h"

Stats::Stats()
{
    methodStats = {
                    {"GET", 0},
                    {"PUT", 0},
                    {"POST", 0},
                    {"DELETE", 0},
                    {"UNKNOWN", 0},
                  };
    uriStats = {
                {"/", 0},
                {"/order", 0},
                {"/product", 0},
                {"/basket", 0},
                {"/help", 0},
                {"unknown", 0}
               };
}

HttpRequest ParseRequest(string_view line)
{
  const size_t protocol_parts_number = 3;
  array<string_view, protocol_parts_number> parts;

  string_view delimiter = " ";
  string_view token;

  auto leading_space_eraser = [](string_view& sv)
  {
    while (!sv.empty() && isspace(sv[0])) {
        sv.remove_prefix(1);
    }
  };

  leading_space_eraser(line);

  size_t idx = 0;
  while(token != line) {
    token = line.substr(0, line.find_first_of(delimiter));
    line = line.substr(line.find_first_of(delimiter) + 1);
    parts[idx++ % protocol_parts_number] = token;
  }

  return {parts.at(0), parts.at(1), parts.at(2)};
}


void Stats::AddMethod(string_view method)
{
  if(this->methodStats.count(method) > 0){
    this->methodStats[method]++;
  } else {
    this->methodStats["UNKNOWN"]++;
  }
}

void Stats::AddUri(string_view uri)
{
  if(this->uriStats.count(uri) > 0){
    this->uriStats[uri]++;
  } else {
    this->uriStats["unknown"]++;
  }
}

const map<string_view, int> &Stats::GetMethodStats() const
{
  return methodStats;
}

const map<string_view, int> &Stats::GetUriStats() const
{
  return uriStats;
}
