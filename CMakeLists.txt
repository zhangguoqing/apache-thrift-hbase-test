cmake_minimum_required(VERSION 3.0.0)

project("HBase C++ Client(Apache Thrift)" C CXX)
enable_testing()
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "_build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "_build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "_build")

set(APACHE_THRIFT_HBASE_TEST_HOME ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DAPACHE_THRIFT_HBASE_TEST_HOME=${APACHE_THRIFT_HBASE_TEST_HOME})

add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-Wunused-parameter)
add_compile_options(-Wshadow)

include_directories(SYSTEM ${APACHE_THRIFT_HBASE_TEST_HOME}/hbase)
include_directories(SYSTEM ${APACHE_THRIFT_HBASE_TEST_HOME}/hbase/gen-cpp)
include_directories(SYSTEM ${APACHE_THRIFT_HBASE_TEST_HOME}/apache-thrift-install/include)

# apache thrift version is v0.12.0: https://github.com/apache/thrift/tree/v0.12.0
link_directories(
    ${APACHE_THRIFT_HBASE_TEST_HOME}/apache-thrift-install/lib
)
set(APACHE_THRIFT_LIBRARIES
    ${APACHE_THRIFT_HBASE_TEST_HOME}/apache-thrift-install/lib/libthrift.a
    ${APACHE_THRIFT_HBASE_TEST_HOME}/apache-thrift-install/lib/libthrift_c_glib.a
    ${APACHE_THRIFT_HBASE_TEST_HOME}/apache-thrift-install/lib/libthriftz.a
)

add_subdirectory(hbase)
add_custom_target(
    distclean
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND "rm" "-rf" "${APACHE_THRIFT_HBASE_TEST_HOME}/hbase/gen-cpp"
    COMMAND "find" "." "-name" "Testing" "|" "xargs" "rm" "-rf"
    COMMAND "find" "." "-name" "CMakeFiles" "|" "xargs" "rm" "-rf"
    COMMAND "find" "." "-name" "CMakeCache.txt" "|" "xargs" "rm" "-f"
    COMMAND "find" "." "-name" "cmake_install.cmake" "|" "xargs" "rm" "-f"
    COMMAND "find" "." "-name" "CTestTestfile.cmake" "|" "xargs" "rm" "-f"
    COMMAND "find" "." "-name" "Makefile" "|" "xargs" "rm" "-f"
)

