//
// Created by liyu on 3/15/23.
//

#ifndef PIXELS_PIXELSREADEROPTION_H
#define PIXELS_PIXELSREADEROPTION_H

#include <iostream>
#include <string>
#include <vector>
#include "PixelsFilter.hpp"

class PixelsReaderOption {
public:
    PixelsReaderOption();
    void setIncludeCols(const std::vector<std::string> & columnNames);
    std::vector<std::string> getIncludedCols();
    void setFilters(const std::vector<PixelsFilter*> & filters);
    std::vector<PixelsFilter*> getFilters();
    void setSkipCorruptRecords(bool s);
    bool isSkipCorruptRecords();
    void setQueryId(long qId);
    void setBatchSize(int batchSize);
    void setEnabledFilterPushDown(bool enabledFilterPushDown);
    bool isEnabledFilterPushDown();
    long getQueryId();
    void setRGRange(int start, int len);
    int getRGStart();
    int getRGLen();
    int getBatchSize() const;
    void setTolerantSchemaEvolution(bool t);
    bool isTolerantSchemaEvolution();
    void setEnableEncodedColumnVector(bool enabled);
    bool isEnableEncodedColumnVector();
private:
    std::vector<std::string> includedCols;
    std::vector<PixelsFilter*> col_filters;
    bool skipCorruptRecords;
    bool tolerantSchemaEvolution;     // this may lead to column missing due to schema evolution
    bool enableEncodedColumnVector;   // whether read encoded column vectors directly when possible
    bool enableFilterPushDown;        // if filter pushDown is enabled
    long queryId;
    int batchSize;
    int rgStart;
    int rgLen;
};
#endif //PIXELS_PIXELSREADEROPTION_H
