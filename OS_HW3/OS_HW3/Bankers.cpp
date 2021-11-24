
#include "Bankers.h"

Bankers::Bankers(Process* processPtr, int* availableArr, int num, int targetNum, int* requestArr)
	:
	available(availableArr),
	process(processPtr),
	request(requestArr),
	processNum(num),
	target(targetNum)
{	
}

Bankers::~Bankers()
{
	if (process)
		delete[] process;
	if (available)
		delete[] available;
	if (request)
		delete[] request;

	process = nullptr;
	available = nullptr;
	request = nullptr;
}

bool Bankers::run()
{
	if (target != -1 && !Request())
		return false;

	for (int i = 0; i < processNum; ++i)
	{
		for (int j = 0; j < processNum; ++j)
		{
			if (!process[j].GetDone() && IsPossible(j))
			{
				ReturnResource(j);
				break;
			}
		}
	}

	bool flag = true;
	for (int i = 0; i < processNum; ++i)
		flag = (flag && process[i].GetDone());

	return flag;
}

bool Bankers::IsPossible(int idx)
{
	for (int i = 0; i < Process::GetSize(); ++i)
		if (process[idx].GetNeed(i) - available[i] > 0)
			return false;

	return true;
}

void Bankers::ReturnResource(int idx)
{
	for (int i = 0; i < Process::GetSize(); ++i)
		available[i] += process[idx].GetAllocation(i);

	process[idx].SetDone(true);
}

bool Bankers::Request()
{
	for (int i = 0; i < Process::GetSize(); ++i)
	{
		if (request[i] - available[i] > 0)
			return false;
		available[i] -= request[i];
		process[target].SetAllocationIndex(process[target].GetAllocation(i) + request[i], i);
	}
	return true;
}
