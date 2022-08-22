cmake_minimum_required(VERSION 3.15)

project(boost-tcp-udp-examples)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

add_library(project_warnings INTERFACE)

include(cmake/Cache.cmake)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

include(cmake/Doxygen.cmake)
enable_doxygen()

include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)

find_package(Boost REQUIRED COMPONENTS system thread)

function(CompileExecutable name)
  add_executable(${name} src/${name}.cpp)
  target_include_directories(${name}
    PRIVATE
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
  )
  target_link_libraries(${name}
    PRIVATE
      ${Boost_LIBRARIES}
  )
  target_compile_features(${name} PRIVATE cxx_std_17)
endfunction()

CompileExecutable("simple_udp_sync_server")
CompileExecutable("simple_udp_sync_client")
CompileExecutable("simple_udp_async_server")
CompileExecutable("simple_tcp_sync_server")
CompileExecutable("simple_tcp_sync_client")
