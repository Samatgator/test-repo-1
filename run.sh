#!/bin/bash

mkdir build
cd build

cmake -DENABLE_COVERAGE=true .. && make
./testproj && make coverage
open coverage/index.html
