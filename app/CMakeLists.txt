cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 23)


find_package(fmt CONFIG REQUIRED)
add_executable(mkproj main.cpp)
target_link_libraries(mkproj PRIVATE fmt::fmt)
