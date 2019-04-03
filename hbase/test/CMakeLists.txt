add_executable(
    hbase_client_test
    HBaseClientTest.cpp
    $<TARGET_OBJECTS:hbase_client_obj>
    $<TARGET_OBJECTS:hbase_thrift_obj>
)
target_link_libraries(
    hbase_client_test
    ${APACHE_THRIFT_LIBRARIES}
    gtest
    -pthread
)
add_test(NAME hbase_client_test COMMAND hbase_client_test)

