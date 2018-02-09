cmake_minimum_required(VERSION 3.2)
project(pipes)

include_directories(/home/work/hadoop/hadoop-2.7.4/include /usr/local/include)
link_directories(/home/work/hadoop/hadoop-2.7.4/lib/native)

set(SOURCE_FILES pipes.cpp common.h common.cpp)
add_executable(pipes ${SOURCE_FILES})
target_link_libraries(pipes hadooppipes crypto hadooputils pthread)