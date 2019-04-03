# apache-thrift-hbase-test

## Build the apache thrift

`rm -rf /path/apache-thrift-hbase-test/apache-thrift-install/*`

`wget https://codeload.github.com/apache/thrift/zip/v0.12.0`

`unzip thrift-0.12.0.zip`

`cd thrift-0.12.0`

`./bootstrap.sh`

`./configure --prefix=/path/apache-thrift-hbase-test/apache-thrift-install/`

`make && make install`


## Run

`cd /path/apache-thrift-hbase-test/`

`cmake3 .`

`make`

`./test/_build/hbase_client_test`

> [==========] Running 1 test from 1 test case.
> [----------] Global test environment set-up.
> [----------] 1 test from HbaseClientTest
> [ RUN      ] HbaseClientTest.SimpleTest
> HBaseClient=========TEST=========TEST=========TEST=========TEST
> The target table is exist...
> account, idcard, 42012319861234561230
> account, name, zhangsan
> account, password, 123456
> address, city, shengzhen
> address, province, guangdong
> info, age, 29
> info, sex, A
> userid, id, 001
> HBaseClient=========TEST=========TEST=========TEST=========TEST
> [       OK ] HbaseClientTest.SimpleTest (52 ms)
> [----------] 1 test from HbaseClientTest (52 ms total)
> 
> [----------] Global test environment tear-down
> [==========] 1 test from 1 test case ran. (53 ms total)
> [  PASSED  ] 1 test.

