// Author: AllinGo (tanhp@outlook.com)
//
// Hadoop MR using C++

#ifndef PIPES_COMMON_H
#define PIPES_COMMON_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "StringUtils.hh"

/**
 * split string using sep
 * @param str
 * @param sep
 * @return
 */
std::vector<std::string> stringSplit(std::string str, std::string sep);

/**
 * Map sort and convert to string
 * @param pathString
 * @return
 */
std::string pathString(std::multimap<int64_t, std::string> pathMap);

#endif
