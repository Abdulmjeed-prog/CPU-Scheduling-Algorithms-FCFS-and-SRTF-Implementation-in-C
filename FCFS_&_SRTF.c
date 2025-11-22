#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Include time.h to use the time() function

void main() {
    int i, current_time, n = 10, count = 0, end, smallest;
    int at[10], bt[10], x[10];
    int waiting[10], turnaround[10], completion[10];
    double avg_wait = 0, avg_turnaround = 0, avg = 0, tt = 0;

    // Seed the random number generator with the current time
    srand(time(0));

    // Randomly generate arrival times and burst times for 10 processes
    at[0] = rand() % 5 + 1;  // First process arrival time between 1 and 5
    for (i = 1; i < 10; i++) {
        at[i] = at[i - 1] + (rand() % 5 + 1);  // Subsequent arrival times
    }

    for (i = 0; i < 10; i++) {
        bt[i] = rand() % 5 + 1;  // Burst time between 1 and 5 for each process
    }

    // Copy burst times to x array
    for (i = 0; i < 10; i++) {
        x[i] = bt[i];
    }

    // Process scheduling for FCFS
    current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];
        }
        current_time += bt[i];
        completion[i] = current_time;
        turnaround[i] = completion[i] - at[i];
        waiting[i] = turnaround[i] - bt[i];
    }

    // Printing results for FCFS
    printf("FCFS Scheduling:\n");
    printf("pid\tburst\tarrival\twaiting\tturnaround\tcompletion\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t\t%d\n", i + 1, x[i], at[i], waiting[i], turnaround[i], completion[i]);
        avg_wait += waiting[i];
        avg_turnaround += turnaround[i];
    }
    printf("\nAverage waiting time for FCFS = %.2lf\n", avg_wait / n);
    printf("Average Turnaround time for FCFS = %.2lf\n", avg_turnaround / n);

    // Reset burst times for SRTF
    for (i = 0; i < n; i++) {
        bt[i] = x[i];
    }

    // Process scheduling for SRTF
    count = 0;
    for (current_time = 0; count != n; current_time++) {
        smallest = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && bt[i] > 0 && (smallest == -1 || bt[i] < bt[smallest])) {
                smallest = i;
            }
        }
        bt[smallest]--;

        if (bt[smallest] == 0) {
            count++;
            end = current_time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - at[smallest] - x[smallest];
            turnaround[smallest] = end - at[smallest];
        }
    }

    // Printing results for SRTF
    printf("\nSRTF Scheduling:\n");
    printf("pid\tburst\tarrival\twaiting\tturnaround\tcompletion\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t\t%d\n", i + 1, x[i], at[i], waiting[i], turnaround[i], completion[i]);
        avg += waiting[i];
        tt += turnaround[i];
    }
    printf("\nAverage waiting time for SRTF = %.2lf\n", avg / n);
    printf("Average Turnaround time for SRTF = %.2lf\n", tt / n);
    
    if(avg_wait/n < avg/n){
   
    printf("\nConclusion: FCFS %.2lf performs better in terms of waiting time.\n",avg_wait/n);
    
    } else {
    printf("\nConclusion: SRTF %.2lf performs better in terms of waiting time.\n",avg/n);
    }
    
    
      if(avg_turnaround / n < tt / n){
   
    printf("\nConclusion: FCFS %.2lf performs better in terms of turnaround time.\n",avg_turnaround / n);
    
    } else {
    printf("\nConclusion: SRTF %.2lf performs better in terms of turnaround time.\n",tt / n);
    }
}
