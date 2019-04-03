# apache thrift v0.12.0:
# https://github.com/apache/thrift/tree/v0.12.0
#
# hbase-1.4.9(thrift2/hbase.thrift):
# https://github.com/apache/hbase/blob/master/hbase-thrift/src/main/resources/org/apache/hadoop/hbase/thrift2/hbase.thrift

add_custom_command(
    OUTPUT
        gen-cpp/THBaseService.cpp
        gen-cpp/hbase_constants.cpp
        gen-cpp/hbase_types.cpp
    COMMAND "${CMAKE_HOME_DIRECTORY}/apache-thrift-install/bin/thrift" "--gen" "cpp:no_skeleton" "-o" "." "./hbase.thrift"
    DEPENDS hbase.thrift
)

add_library(
    hbase_thrift_obj OBJECT
    gen-cpp/THBaseService.cpp
    gen-cpp/hbase_constants.cpp
    gen-cpp/hbase_types.cpp
)

add_library(
    hbase_client_obj OBJECT
    HBaseClient.cpp
)

add_subdirectory(test)
