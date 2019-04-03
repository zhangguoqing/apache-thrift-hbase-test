#include <gtest/gtest.h>
#include "HBaseClient.h"
#include "gen-cpp/THBaseService.h"
#include <iostream>


using namespace apache::hadoop::hbase::thrift2;  // NOLINT

TEST(HbaseClientTest, SimpleTest) {
    auto hbaseclient = std::make_unique<HBaseClient>();
    hbaseclient->get("user", "zhangsan");
    std::string val = "val";
    EXPECT_EQ(val, "val");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
