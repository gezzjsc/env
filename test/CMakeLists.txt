cmake_minimum_required(VERSION 3.13)
project(env)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

include_directories(
        "${PROJECT_SOURCE_DIR}/include"
)
add_executable(env_test
               test.cpp
        )
target_link_libraries(env_test env)