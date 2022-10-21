TA responsible for HW2: Weijie Sun (wsunan@cse.ust.hk)

**Fall 2022 COMP 3511 Homework Assignment 2 (HW2)**

**Handout Date: October 10, 2022, Due Date: October 24, 2022**

| Name | Casper Kristiansson |
| --- | --- |
| Student ID | 20938643 |
| ITSC email | cok@connect.ust.hk |

**Please read the following instructions carefully before answering the questions:**

- You should finish the homework assignment **individually**.
- All programs should be executed in a CS Lab 2 machine.
- **Homework Submission**** : **submitted to** Homework #2 **on** Canvas**.
- TA responsible for HW2: Weijie Sun (wsunan@cse.ust.hk)

**1. [20 points] Multiple Choices.**

Please write down your answers in the boxes below:

| Q1 | Q2 | Q3 | Q4 | Q5 | Q6 | Q7 | Q8 | Q9 | Q10 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
|  D |  A |  C |  C |  A |  D |  B |  D |  A |  B |

1. Which of the following is the statement is TRUE during process termination?

1. All processes transition into _Zombie state_ before termination
2. The corresponding entry in the _Process Table_ or _Process List_ still exists after a process call exit() before its parent process call wait()
3. A process becomes an _orphan_ process when its parent process terminates without invoking wait().
4. All of the above.

1. Suppose that a host with IP address 150.55.66.77 wishes to access a Web server with IP address 202.28.15.123. Which of the following socket pair is valid for a connection between this pair of hosts?

A. 150.55.66.77:1600 and 202.28.15.123:80

B. 150.55.66.77:200 and 202.28.15.123:80

C. 150.55.66.77:80 and 202.28.15.123:80

D. 150.55.66.77:1500 and 202.28.15.123:150

1. Which of the following statements on pipe communication is TRUE?

1. Named pipes are automatically deleted after the communication ends.
2. Communications are uni-directional for named pipes
3. Ordinary pipes can be used for communications between parent and child processes
4. Ordinary pipes can be used by communicating processes on different machines.

1. Which of the following statements is TRUE for a multi-threaded process?

    1. The process state can be uniquely determined
    2. Threads of the same process share stack with each other
    3. Thread is the basic unit of CPU utilization
    4. Threads belonging to a process can exist independently of the process

1. CPU scheduling may take place in the following instances; which instance is considered to be _non-preemptive_?

    1. The completion of an I/O operation of a process (waiting to ready state)
    2. A running process request an I/O operation
    3. A running process is interrupted
    4. A new process joins the system (i.e., from new to ready state)

1. Which of the following scheme is an acceptable signal handling scheme for a multithreaded program?

A. Deliver the signal to the thread to which the signal applies.

B. Deliver the signal to every thread in the process.

C. Deliver the signal to only certain threads in the process.

D. All of the above

1. Which of the following mapping scheme from user threads to kernel threads does not require scheduling, i.e., process-contention scope or PCS?

    1. Many-to-One
    2. One-to-One
    3. Many-to-Many
    4. Two-level mapping model

1. Which of the following statement on MLFQ scheduling is TRUE?

    1. It is fair in the sense that all processes can make progress
    2. It does not have the _convey effect_
    3. Its performance resembles SJF scheduling without the need to estimate the next CPU burst time
    4. All of the above

1. Which of the following statement is TRUE for a _rate-monotonic_ scheduling algorithm?

    1. It only deals with periodic processes or tasks
    2. A process with a shorter period will have lower priority
    3. It is non-preemptive in nature
    4. It uses a dynamic priority policy

1. What is the inherent problem with priority scheduling algorithms?

    1. complexity
    2. Starvation
    3. How to determine the length of the next CPU burst
    4. How to determine the length of the time quantum

**2. [20 points] CPU Scheduling.**

Consider the following set of processes, with the length of the CPU burst time given in milliseconds:

| Process | Arrival Time | Burst Time |
| --- | --- | --- |
| P1 | 0 | 6 |
| P2 | 1 | 3 |
| P3 | 8 | 6 |
| P4 | 13 | 6 |
| P5P6 | 1620 | 32 |

Draw Gantt charts for the scheduling algorithms listed below and compute the average turnaround time and the average waiting time for each algorithm.

1. FCFS
2. SJF
3. SRTF
4. RR (time quantum = 3)

1)

![Picture1](https://user-images.githubusercontent.com/36133918/197171520-5f88d42a-b847-4706-aceb-7ab7a03e783a.png)

2)

![Picture2](https://user-images.githubusercontent.com/36133918/197171307-2e42b6e7-5a51-4831-99e0-6a7de0fee160.png)

3)

![Picture3](https://user-images.githubusercontent.com/36133918/197171329-43dbb619-ed50-4933-80ba-33e2a74cc3a8.png)

4)
![Picture4](https://user-images.githubusercontent.com/36133918/197171353-586e55f9-58e9-4223-b851-eafb92674926.png)


**3. [15 points] Priority Scheduling with Round Robin.**

Draw Gantt charts for priority scheduling with RR (time quantum = 3) and compute the average turnaround time and the average waiting time.

**Note** : (1) a smaller (larger) number indicates a higher (lower) priority. (2) When a low priority process is interrupted by a higher priority process, the low priority process is placed at the _ **head** _ of its RR queue; when it resumes execution on a CPU, it continues to run with the remaining quantum instead of getting a full (new) quantum.

| Process | Arrival Time | Burst Time | Priority |
| --- | --- | --- | --- |
| P1 | 0 | 8 | 5 |
| P2 | 1 | 3 | 5 |
| P3 | 8 | 7 | 1 |
| P4 | 11 | 6 | 2 |
| P5P6 | 1516 | 32 | 21 |

![Picture5](https://user-images.githubusercontent.com/36133918/197171389-e194840b-b75c-4992-92f9-6f5c63f4ddbd.png)

**4.**** [25 points] Multi-Level Feedback Queue**

Draw Gantt charts for a MLFQ scheduling and compute the average turnaround time and the average waiting time. The three queues are defined as follows.

1. Q0: RR with time quantum 3
2. Q1: RR with time quantum 6
3. Q2: FCFS

![Picture1](https://user-images.githubusercontent.com/36133918/197171419-f9ac2b60-bcd1-45a0-81da-e59158ef7ceb.png)

| Process | Arrival Time | Burst Time |
| --- | --- | --- |
| P1 | 0 | 6 |
| P2 | 1 | 3 |
| P3 | 8 | 6 |
| P4 | 13 | 6 |
| P5P6 | 1620 | 32 |

![Picture6](https://user-images.githubusercontent.com/36133918/197171460-d92c3c78-3b78-4cac-965b-3131fa8334ee.png)

**5. [20 points] Fork and Pipe Programming**

Consider the following C program:

```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    char msg[50] = "empty message";
    pid_t pid = fork();
    if ( pid > 0 ) {    // parent
        wait(0);        // wait for the child
        printf("The message in parent is %s\n", msg);
    } else {            // child
        strcpy(msg, "secret message");
        printf("The message in child is %s\n", msg);
    }
    return 0;
}
```

1. What is the output of the above program. Briefly explain the output of the program

**Output:**

The message in child is secret message

The message in parent is empty message

The program declares a msg char array. It then creates a child process using (pid\_t pid = fork();). The parent will then enter the first if statement because the pid is not equal to 0 and wait until the child is finished running. The child will then copy the "secret message" into the msg char array and print the result. The parent will then print the original message. This is because the information is not shared between the processes so even though the child updates the msg char array it won't affect the parents msg char array. The shared memory is not updated.

1. Fill in the missing blanks of the following program so that the output of the program becomes:

The message in child is secret message

The message in parent is secret message

```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char msg[50] = "empty message";
    const char secret_msg[] = "secret message"; 
    int secret_length = strlen(secret_msg);
    int pfds[2];
    
    __________________________ // Hint: invoke pipe() here
    pid_t pid = fork();
    if ( pid > 0 ) {           // parent
        wait(0);               // wait for the child

        ______________________ // Hint: invoke close() here
        
        ______________________ // Hint: invoke read here
        printf("The message in parent is %s\n", msg);
    } else { // child
        strcpy(msg, secret_msg);
        
        ______________________ // Hint: invoke close() here
        
        ______________________ // Hint: invoke write here
        printf("The message in child is %s\n", msg);
    }
    return 0;
}
```

| **Line** | **Code** |
| --- | --- |
| 1 | pipe(pfds); |
| 2 | close(0); |
| 3 | read(pfds[0], msg, secret\_length); |
| 4 | close(0); |
| 5 | write(pfds[1], secret\_msg, secret\_length); |
