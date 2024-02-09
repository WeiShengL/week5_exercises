#pragma once
#include <iostream>

class FileManager
{
public:
    FileManager(std::string fileName);
    ~FileManager();
    int getData(const int &entry);

private:
    FILE *f = nullptr;
};