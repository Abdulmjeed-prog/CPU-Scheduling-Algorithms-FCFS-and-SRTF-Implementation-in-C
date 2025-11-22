# CPU-Scheduling-Algorithms-FCFS-and-SRTF-Implementation-in-C
This project implements two fundamental CPU scheduling algorithms in C:

First-Come, First-Served (FCFS): A non-preemptive scheduling algorithm that executes processes in the order of their arrival time.

Shortest Remaining Time First (SRTF): A preemptive scheduling algorithm that selects the process with the shortest burst time remaining at each time unit.

Features
Random generation of arrival times and burst times for 10 processes.

Calculation of waiting time, turnaround time, and completion time for both algorithms.

Comparison of average waiting time and turnaround time between FCFS and SRTF.

Clear console output of process details and performance metrics.

Dynamic seeding of random number generator based on current time for varied results each run.

How It Works
Process Initialization:

Arrival times are generated cumulatively with random gaps.

Burst times are randomly assigned within a specified range.

FCFS Scheduling:

Processes are executed strictly in order of arrival.

Completion, waiting, and turnaround times are calculated sequentially.

SRTF Scheduling:

At each time unit, the process with the shortest remaining burst time that has arrived is selected.

Supports preemption as new processes arrive.

Updates completion, waiting, and turnaround times accordingly.

Output:

Displays process ID, burst time, arrival time, waiting time, turnaround time, and completion time.

Shows average waiting and turnaround times for both algorithms.

Provides a conclusion on which algorithm performs better in terms of waiting and turnaround times for the given random processes.

Usage
Compile the C program with a standard compiler like gcc.

Run the executable to see the scheduling simulation results.

bash
gcc scheduling.c -o scheduling
./scheduling
Notes
The program uses the time() function to seed the random number generator, which helps in generating different inputs on each run.

The implementation assumes a fixed number of 10 processes.

Results will vary on each execution due to random input generation.

License
This project is open for educational and personal use. Feel free to contribute or suggest improvements.
