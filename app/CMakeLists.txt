cmake_minimum_required(VERSION 3.29)

find_package(fmt CONFIG REQUIRED)
add_executable(mkproj main.cpp)
target_link_libraries(mkproj PRIVATE fmt::fmt)
