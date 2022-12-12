#include <iostream>
using namespace std;
int Seektime(int time[], int n, int head)
{
    int totaltime = 0;
    int seektime = head;
    for (int i = 0; i < n; i++)
    {
        totaltime = totaltime + abs(seektime - time[i]);
        seektime = time[i];
    }
    return totaltime;
}
int main()
{
    int time[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = 8;
    int head = 53;
    cout << Seektime(time, n, head);
    return 0;
}