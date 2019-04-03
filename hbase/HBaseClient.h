/* Copyright (c) 2018 - present, VE Software Inc. All rights reserved
 *
 * This source code is licensed under Apache 2.0 License
 *  (found in the LICENSE.Apache file in the root directory)
 */

#ifndef HBASECLIENT_H_
#define HBASECLIENT_H_

#include "gen-cpp/THBaseService.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>


class HBaseClient final {
public:
    explicit HBaseClient();
    ~HBaseClient();

    /*
     * Just an example: FYI.THBaseService.h
     * You can implement other HBase APIs according to your needs.
     *
     * exists, existsAll, get, getMultiple, put, checkAndPut, putMultiple,
     * deleteSingle, deleteMultiple, checkAndDelete, increment, append,
     * openScanner, getScannerRows, closeScanner, mutateRow, getScannerResults,
     * getRegionLocation, getAllRegionLocations, checkAndMutate
    */
    int get(const std::string tableName, const std::string rowKey);

private:
    std::shared_ptr<apache::thrift::transport::TSocket> socket_;
    std::shared_ptr<apache::thrift::transport::TTransport> transport_;
    std::shared_ptr<apache::thrift::protocol::TProtocol> protocol_;
    std::shared_ptr<apache::hadoop::hbase::thrift2::THBaseServiceClient> client_;
};

#endif  // HBASECLIENT_H_

