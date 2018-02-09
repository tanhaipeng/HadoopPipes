#!/usr/bin/env bash

#debug
#cmake CMakeLists.txt

#release
cmake -DCMAKE_BUILD_TYPE=Release
make
