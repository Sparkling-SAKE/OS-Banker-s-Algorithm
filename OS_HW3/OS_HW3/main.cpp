
#include "function.h"

/*
    ### input.txt ###

    Process 개수
    Max     Allocation
    Max     Allocation
    .
    // Process class의 size 값 만큼
    .
    Max     Allocation
    Available

    ==============================

    ### input2.txt ###

    Process 개수
    Max     Allocation
    Max     Allocation
    .
    // Process class의 size 값 만큼
    .
    Max     Allocation
    Available
    Request Target Process Number
    RequestResource
*/

int main()
{
    ifstream fin("input.txt");
    ifstream fin2("input2.txt");

    if (fin.fail() || fin2.fail())
    {
        cout << "파일을 읽을 수 없습니다." << endl;
        return 0;
    }

    // input.txt에 대한 init
    int numOfProcess;   fin >> numOfProcess;
    Process* process = new Process[numOfProcess];
    int*    available = new int[Process::GetSize()];
    int*    request = new int[Process::GetSize()];
    int     target = -1;

    ProcessInit(fin, process, numOfProcess, Process::GetSize());
    BankersInit(fin, available, request, target, Process::GetSize());

    Bankers bankers(process, available, numOfProcess, target, request);

    // input2.txt에 대한 init
    int numOfProcess2;   fin2 >> numOfProcess2;
    Process* process2 = new Process[numOfProcess2];
    int*    available2 = new int[Process::GetSize()];
    int*    request2 = new int[Process::GetSize()];
    int     target2 = -1;

    ProcessInit(fin2, process2, numOfProcess2, Process::GetSize());
    BankersInit(fin2, available2, request2, target2, Process::GetSize());

    Bankers bankers2(process2, available2, numOfProcess2, target2, request2);


    cout << "Result of input.txt : ";
    if (bankers.run())
        cout << "Safe" << endl;
    else
        cout << "UnSafe" << endl;

    cout << "Result of input2.txt : ";
    if (bankers2.run())
        cout << "Safe" << endl;
    else
        cout << "UnSafe" << endl;


    fin.close();
    fin2.close();

    return 0;
}
