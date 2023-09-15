#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid; 
    int arrival_time;  
    int burst_time;  
};

int compare(const void *a, const void *b) {
    const struct Process *p1 = (const struct Process *)a;
    const struct Process *p2 = (const struct Process *)b;
    return p1->arrival_time - p2->arrival_time;
}
void sjf(struct Process *processes, int n) {

    qsort(processes, n, sizeof(struct Process), compare);

    int waiting_time[n];
    int turnaround_time[n];
    for (int i = 0; i < n; i++) {
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }

    int current_time = 0;
    for (int i = 0; i < n; i++) {

        waiting_time[i] = current_time - processes[i].arrival_time;

        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;

        current_time += processes[i].burst_time;
    }
    printf("Process ID  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time);
