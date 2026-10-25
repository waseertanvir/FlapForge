cmake_minimum_required(VERSION 3.16)
project(flappy-clone CXX)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
   FetchContent_Declare(raylib
     URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz)
FetchContent_MakeAvailable(raylib)

add_executable(flappy-clone main.cpp)

target_link_libraries(flappy-clone raylib)
