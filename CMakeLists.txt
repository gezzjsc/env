cmake_minimum_required(VERSION 3.13)
project(env)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(
        "${PROJECT_SOURCE_DIR}/include"
)
file(GLOB NATIVES_SRC "src/*.cpp")
#link_directories(${PROJECT_SOURCE_DIR}/3rd)
add_library(env SHARED ${NATIVES_SRC})
add_subdirectory(test)