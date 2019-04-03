#include "HBaseClient.h"
#include "gen-cpp/THBaseService.h"
#include "gen-cpp/hbase_types.h"

#include <iostream>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

using namespace apache::hadoop::hbase::thrift2;

HBaseClient::HBaseClient() {
    socket_.reset(new apache::thrift::transport::TSocket("127.0.0.1", 9096));
    socket_->setConnTimeout(1000);
    transport_.reset(new apache::thrift::transport::TBufferedTransport(socket_));
    protocol_.reset(new apache::thrift::protocol::TBinaryProtocol(transport_));
    transport_->open();
    client_.reset(new apache::hadoop::hbase::thrift2::THBaseServiceClient(protocol_));
}

int HBaseClient::get(const std::string tableName, const std::string rowKey) {
    std::cout << "HBaseClient=========TEST=========TEST=========TEST=========TEST" << std::endl;
    TResult tResult;
    TGet tGet;
    tGet.__set_row(rowKey);
    try {
        if (client_->exists(tableName, tGet)) {
            std::cout << "The target table is exist..." << std::endl;
        }
        client_->get(tResult, tableName, tGet);
        std::vector<TColumnValue> list = tResult.columnValues;
        std::vector<TColumnValue>::const_iterator iter;
        for (iter = list.begin(); iter != list.end(); iter++) {
            std::cout << (*iter).family.c_str() << ", " << (*iter).qualifier.c_str()
                      << ", " << (*iter).value.c_str() << std::endl;
        }
    } catch (const apache::hadoop::hbase::thrift2::TIOError &ex) {
        std::cout << "TIOError: " << ex.message << std::endl;
        return 1;
    } catch (apache::thrift::transport::TTransportException& ex) {
        std::cout << "Transport Exception: " << ex.what() << std::endl;
        return 2;
    }
    std::cout << "HBaseClient=========TEST=========TEST=========TEST=========TEST" << std::endl;
    return 0;
}

HBaseClient::~HBaseClient() {
    if (transport_->isOpen()) {
        transport_->close();
    }
}

