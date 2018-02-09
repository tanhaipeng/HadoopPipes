// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: AllinGo (tanhp@outlook.com)
//
// Hadoop MR using C++

#include "common.h"

/**
 * string split
 * @param str
 * @param sep
 * @return
 */
std::vector<std::string> stringSplit(const std::string str, const std::string sep) {
    std::vector<std::string> ret;
    boost::split(ret, str, boost::is_any_of(sep));
    return ret;
}

/**
 * sort map
 * @param pathString
 * @return
 */
std::string pathString(std::multimap<int64_t, std::string> pathMap) {
    std::string ret = "";
    for (std::multimap<int64_t, std::string>::iterator it = pathMap.begin(); it != pathMap.end(); it++) {
        std::stringstream ss;
        ss << (*it).first;
        ret = ret + "|" + (*it).second + "_" + ss.str();
    }
    boost::trim_left_if(ret, boost::is_any_of("|"));
    return ret;
}