
#include "Process.h"

Process::Process()	:
	max(nullptr),
	allocation(nullptr),
	need(nullptr),
	done(false)
{
}

Process::Process(int* maxArr, int* allocationArr)
{
	max = maxArr;
	allocation = allocationArr;
	need = new int[size];
	done = false;

	SetNeed();
}

Process::Process(const Process& other)
{
	max = new int[size];
	allocation = new int[size];
	need = new int[size];
	done = other.done;

	for (int i = 0; i < size; ++i)
	{
		max[i] = other.max[i];
		allocation[i] = other.allocation[i];
		need[i] = other.need[i];
	}
}

Process::Process(Process&& other)	noexcept
{
	max = other.max;
	allocation = other.allocation;
	need = other.need;
	done = other.done;

	other.max = nullptr;
	other.allocation = nullptr;
	other.need = nullptr;
}

Process::~Process()
{
	if (max)
		delete[] max;
	if (allocation)
		delete[] allocation;
	if (need)
		delete[] need;

	max = nullptr;
	allocation = nullptr;
	need = nullptr;
}

Process& Process::operator=(Process&& other)	noexcept
{
	if (this == &other)
		return *this;

	if (max)
		delete[] max;
	if (allocation)
		delete[] allocation;
	if (need)
		delete[] need;

	max = other.max;
	allocation = other.allocation;
	need = other.need;
	done = other.done;

	other.max = nullptr;
	other.allocation = nullptr;
	other.need = nullptr;

	return *this;
}

void Process::SetMax(int* maxArr)
{
	for (int i = 0; i < size; ++i)
		max[i] = maxArr[i];
}

void Process::SetAllocation(int* allocationArr)
{
	for (int i = 0; i < size; ++i)
		allocation[i] = allocationArr[i];

	SetNeed();
}

void Process::SetDone(bool flag)
{
	done = flag;
}

void Process::SetMaxIndex(int value, int idx)
{
	max[idx] = value;
}

void Process::SetAllocationIndex(int value, int idx)
{
	allocation[idx] = value;

	SetNeedIndex(idx);
}

void Process::SetNeed()
{
	for (int i = 0; i < size; ++i)
		need[i] = max[i] - allocation[i];
}

void Process::SetNeedIndex(int idx)
{
	need[idx] = max[idx] - allocation[idx];
}

int Process::GetMax(int idx) const
{
	return max[idx];
}

int Process::GetAllocation(int idx) const
{
	return allocation[idx];
}

int Process::GetNeed(int idx) const
{
	return need[idx];
}

bool Process::GetDone() const
{
	return done;
}

int Process::GetSize()
{
	return size;
}
