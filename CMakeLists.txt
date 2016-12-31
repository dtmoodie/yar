cmake_minimum_required(VERSION 2.8)

project(yar)

set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
find_package(Boost REQUIRED COMPONENTS log log_setup)
  ADD_DEFINITIONS(-DBOOST_ALL_DYN_LINK)
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIR_DEBUG})

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
file(GLOB_RECURSE hdr "include/*.hpp")
file(GLOB_RECURSE src "src/*.cpp")

add_library(yar SHARED ${hdr} ${src})
target_link_libraries(yar ${Boost_LIBRARIES})