
#pragma once

#include <iostream>
#include <fstream>
#include "Process.h"
#include "Bankers.h"

using namespace std;

void ProcessInit(ifstream& fin, Process* process, int numOfProcess, int size)
{

    for (int i = 0; i < numOfProcess; ++i)
    {
        int* maxArr = new int[size];
        int* allocationArr = new int[size];

        for (int j = 0; j < size; ++j)
            fin >> maxArr[j];
        for (int j = 0; j < size; ++j)
            fin >> allocationArr[j];

        process[i] = Process(maxArr, allocationArr);
    }
}

void BankersInit(ifstream& fin, int* available, int* request, int& target, int size)
{
    for (int i = 0; i < size; ++i)
        fin >> available[i];
    if (!fin.eof())
    {
        fin >> target;
        for (int i = 0; i < size; ++i)
            fin >> request[i];
    }
    else
    {
        for (int i = 0; i < size; ++i)
            request[i] = 0;
    }
}
