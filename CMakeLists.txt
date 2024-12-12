cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

set(SOURCES main.cpp src/candle.h src/candle.cpp tests/test.h tests/test.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
