
#pragma once

#include "Process.h"

class Bankers
{
private:
	int*	 available;
	Process* process;
	int*	 request;
	int		 processNum;
	int		 target;

public:
	Bankers(Process* processPtr, int* availableArr, int num, int targetNum, int* requestArr = nullptr);
	~Bankers();

public:
	bool run();

private:
	bool IsPossible(int idx);
	void ReturnResource(int idx);
	bool Request();
};

