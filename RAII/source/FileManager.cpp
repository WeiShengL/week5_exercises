#include "FileManager.h"
#include <string>
#include <iostream>


FileManager::FileManager(std::string fileName)
{
    f = std::fopen(fileName.c_str(), "rw");
    if (!f)
    {
        std::string errorMessage = "Failed to open file";
        throw std::logic_error(errorMessage);
    }
    else
    {
        std::cout << "File opened." << std::endl;
    }
};

FileManager::~FileManager()
{
    if (f)
    {
        std::fclose(f);
        std::cout << "File closed." << std::endl;
    }
};

int FileManager::getData(const int &entry)
{
    return std::fscanf(f, "%d", &entry);
};

// void FileManager::printProcessedFile()
// {
//     int n;
//     while (std::fscanf(f, "%d", &n) != EOF)
//     {
//         // try
//         // {
//         //     std::cout << n << "! = " << factorial(n) << std::endl;
//         // }
//         // catch(const std::exception &e)
//         // {
//         //     // std::cerr << e.what() << '\n';
//         //     std::cerr << "Exception caught: " << e.what() << std::endl;
//         // }
//         std::cout << n << "! = " << factorial(n) << std::endl;
//     }
// }