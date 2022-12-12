#include<stdio.h>
int main() {
int time, burst_time[10], at[10], sum_burst_time = 0, smallest, n, i;
int sumt = 0, sumw = 0;
printf("Enter the no of processes : ");
scanf("%d", & n);
for (i = 0; i< n; i++) {
printf("The arrival time for process P%d : ", i + 1);
scanf("%d", & at[i]);
printf("The burst time for process P%d : ", i + 1);
scanf("%d", &burst_time[i]);
sum_burst_time += burst_time[i];
}
printf("Process\t|\tT.A.T\t|\tW.T\n");
burst_time[9] = 9999;   
for (time = 0; time <sum_burst_time;) {
smallest = 9;
for (i = 0; i< n; i++) {
if (at[i] <= time &&burst_time[i] > 0 &&burst_time[i] <burst_time[smallest])
smallest = i;
}
sumt += time + burst_time[smallest] - at[smallest];
sumw += time - at[smallest];
time += burst_time[smallest];
burst_time[smallest] = 0;
}
printf("\n\n average waiting time = %f", sumw * 1.0 / n);
printf("\n\n average turnaround time = %f", sumt * 1.0 / n);
return 0;
}