// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: AllinGo (tanhp@outlook.com)
//
// Hadoop MR using C++

#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include "Pipes.hh"
#include "TemplateFactory.hh"
#include "StringUtils.hh"
#include "common.h"

/**
 * Pipes Mapper
 */
class PIPESMapper : public HadoopPipes::Mapper {
public:
    PIPESMapper(HadoopPipes::TaskContext &context) {

    }

    void map(HadoopPipes::MapContext &context) {
        std::string line = context.getInputValue();
        std::vector<std::string> split = HadoopUtils::splitString(line, "\t");
        if (split.size() == 8) {
            context.emit(split[3], split[2] + "_" + split[5]);
        }
    }
};

/**
 * Pipes Reducer
 */
class PIPESReducer : public HadoopPipes::Reducer {
public:
    PIPESReducer(HadoopPipes::TaskContext &context) {

    }

    void reduce(HadoopPipes::ReduceContext &context) {
        std::multimap<int64_t, std::string> pathMap;
        while (context.nextValue()) {
            std::vector<std::string> split = HadoopUtils::splitString(context.getInputValue(), "_");
            if (split.size() == 2) {
                pathMap.insert(std::pair<int64_t, std::string>(boost::lexical_cast<uint64_t>(split[1]), split[0]));
            }
        }
        if (pathMap.size() > 0) {
            context.emit(context.getInputKey(), pathString(pathMap));
        }
    }
};

int main(int argc, char *argv[]) {
    // run task
    return HadoopPipes::runTask(HadoopPipes::TemplateFactory<PIPESMapper, PIPESReducer>());
}