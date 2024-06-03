cmake_minimum_required(VERSION 3.10)
project(CppSimpleWebServer)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(CppSimpleWebServer src/main.cpp)
target_include_directories(CppSimpleWebServer PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(CppSimpleWebServer PRIVATE Boost::system)
