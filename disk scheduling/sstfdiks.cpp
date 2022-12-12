#include <bits/stdc++.h>
using namespace std;
void calculatediff(int time[], int n, int head, int diff[][2])
{

    for (int i = 0; i < n; i++)
    {
        diff[i][0] = abs(head - time[i]);
    }
}
int findmini(int time[], int head, int diff[][2], int n)
{
    int index = -1;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (!diff[i][1] && mini > diff[i][0])
        {
            mini = diff[i][0];
            index = i;
        }
    }
    return index;
}
void sstf(int time[], int n, int head)
{
    if (n == 0)
        return;
    int diff[n][2] = {{0, 0}};
    int count = 0;
    int seekseq[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        seekseq[i] = head;
        calculatediff(time, n, head, diff);
        int index = findmini(time, head, diff, n);
        count += diff[index][0];
        diff[index][1] = 1;
        head = time[index];
    }
    seekseq[n] = head;
    cout << "Total seek operations: " << count;
}
int main()
{
    int time[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = 8;
    int head = 53;
    sstf(time, n, head);
    return 0;
}