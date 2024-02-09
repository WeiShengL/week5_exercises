#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "FileManager.h"

int factorial(int n)
{
    if(n<0)
    {
        std::string errorMessage = "No factorial for negative numbers";
        throw std::range_error(errorMessage);
    }
    return n == 0 ? 1 : n * factorial(n-1);
}

void printProcessedFile(std::string fileName)
{
    FileManager f(fileName);

    int n;
    while (f.getData(n) != EOF)
    {
        std::cout << n << "! = " << factorial(n) << std::endl;
    }
}

int main()
{
    try
    {
        printProcessedFile("testFile.txt");
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "We no longer have access to the file handle." << std::endl;
    }

    return 0;
}