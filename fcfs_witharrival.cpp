#include <bits/stdc++.h>
using namespace std;
void findwaiting(int n, int tat[], int bt[], int wt[])
{
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
}
void findcompletion_time(int n, int ct[], int at[], int bt[])
{
    ct[0] = bt[0] + at[0];
    for (int i = 1; i < n; i++)
    {
        if (at[i] > ct[i - 1])
            ct[i] = at[i] - ct[i - 1];
        ct[i] += ct[i - 1] + bt[i];
    }
for (int i = 0; i < n; i++)
        cout << ct[i] <<" ";
}
void findtat(int n, int at[], int ct[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = ct[i] - at[i];
    // for (int i = 0; i < n; i++)
    //     cout << tat[i] <<" ";
}
void fcfs(int n, int burst_time[], int arrival_time[])
{
    int wt[n], tat[n];
    int ct[n] = {0};
    findcompletion_time(n, ct, arrival_time, burst_time);
    findtat(n, arrival_time, ct, tat);
    findwaiting(n, tat, burst_time, wt);
    double avgwt = 0.0, avgtat = 0.0;
    for (int i = 0; i < n; i++)
    {
        avgwt += wt[i];
        avgtat += tat[i];
    }
    cout<<"Average waiting time: "<<double(avgwt/n)<<endl;
    cout<<"Average turn around time: "<<double(avgtat/n)<<endl;
}
int main()
{
    int arrival_time[] = {0,1,5,6};
    int burst_time [] = {2,2,3,4};
    int n = 4;
    fcfs(n, burst_time, arrival_time);
}