
#pragma once

class Process
{
private:
	int*	max;
	int*	allocation;
	int*	need;
	bool	done;

private:
	static const int	size = 4;

public:
	Process();
	Process(int* maxArr, int* allocationArr);
	Process(const Process& other);
	Process(Process&& other) noexcept;
	~Process();

public:
	Process& operator=(Process&& other)	noexcept;

public:
	void SetMax(int* maxArr);
	void SetAllocation(int* allocationArr);
	void SetDone(bool flag);
	void SetMaxIndex(int value, int idx);
	void SetAllocationIndex(int value, int idx);

private:
	void SetNeed();
	void SetNeedIndex(int idx);

public:
	int  GetMax(int idx)			const;
	int  GetAllocation(int idx)		const;
	int  GetNeed(int idx)			const;
	bool GetDone()					const;

public:
	static int	GetSize();
};

