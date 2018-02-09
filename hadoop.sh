#!/usr/bin/env bash

mapred pipes -D hadoop.pipes.java.recordreader=true -D hadoop.pipes.java.recordwriter=true -program /bin/pipes -input /testlog/input.data -output /testlog