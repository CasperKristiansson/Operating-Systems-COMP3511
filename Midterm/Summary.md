# Operating Systems Midterm

## Chapter 1: High-level description OS, basic components in computer systems including multi-processor systems, virtualization

### Learning Outcome

- What Operating Systems Do
- Computer System Organization and Architecture
- Multiprocessor and Parallel Systems
- Definition of Operating Systems
- Virtualization and Cloud Computing
- Free and Open-Source Operating Systems

### Notes

- Operating system
  - A operating system controls and coordinates the hardware among different applications among different users
  - Its task is to be an intermediate between the user and the computer hardware
  - OS is a **resource allocator**
  - OS is a **control program**
- Moore's law states that number of transistors of a circuit board double every 18 months
- Middleware
  - Services that provide software frameworks for additional application developers
- Kernel is the core part of the operating system which manages the system resources
  - **Processing unit** that contains ALU (arithmetic logic unit) and processor registers
  - **Control unit** that contains instruction register and program counter
  - **Memory** stores data and instructions
- Steps which a computer takes to execute an instruction

1. Fetch instruction
2. Decode instruction
3. Fetch data
4. Execute instruction
5. Write back if any

- Computer-system Operation – I/O
  - I/O devices and execute **concurrent** with CPU
  - Device controller
    - Charge of a particular device
    - Each has a local buffer
    - Responsible for moving data between peripheral devices that it controls and its local buffer
    - When it has finished its tasks, it notifies the CPU using an interrupt
      - Interrupt is used to handle asynchronous events
      - I/O triggers an interrupt by sending a signal to the CPU
      - CPU handles the interrupt and then returns to the interrupt instruction
  - CPU moves data back and forth from/to main memory to/from local buffers
- Interrupts continued…
  - All modern OS have an interrupt driven system
  - Interrupts supports a priority system
  - **Trap** or **exception** is an interrupt created by software when an error occurs
- Memory
  - Main memory
    - Large storage media that CPU can access directly
    - Volatile
  - Second storage
    - Nonvolatile memory
- Caching
  - Average Access time = (Hit Rate x Hit Time) + (Miss Rate x Miss Time)
  - Temporal
    - Keep the recently accessed
  - Spatial
    - Closely stored information
- I/O subsystem
  - An OS needs to handle a variety of different devices
  - OS enables I/O devices to be treated as standard uniform way
  - I/O system calls are encapsulated which can be accessed through standardized set of functions (interface)
  - A purpose of OS is to hide peculiarities of hardware devices from users
  - Responsible for:
    - Buffering
      - Storing data temporarily while it is being transferred
    - Caching
    - Spoofing
      - Overlapping output of one job to input to another
- DMA – Direct memory access
  - DMA controllers' purpose is to move data directly from a I/O device and main memory without involving the CPU
- Multiprocessing system
  - Asymmetric Multiprocessing
    - Master slave manner, master assign specific individual tasks to slave
  - Symmetric Multiprocessing
    - Each process performed all tasks
- NUMA – Non-Uniform Memory access
  - Adding more CPUs to a multiprocessor system isn't always scalable due to system bus being bottleneck
  - Solution to this is by providing each CPU with its own local memory
- Multiprogramming
  - Single user cannot keep CPU and I/O busy all the time
  - Multiprogramming organizes jobs
  - Subset of jobs is kept in the memory
- Timesharing
  - A logical solution where the CPU switches between jobs creating a interactive computing

## Chapter 2: OS services including APIs and system calls, and common OS design approaches (monolithic, layered, microkernel, modular)

- OS provides an environment to execute programs or services to programs and users
  - Example of OS services could be User interface, Program execution, I/O operations, File system manipulation, Communication, Error detection, Resource allocation, Logging, Protection, and security
- The OS have system calls (API)
  - Provide set functionalities which programmers can access
  - The reason to use API instead of directly accessing the system calls is because program portability
  - Hide complexity
- System programs
  - Services, programs, and utilities that the OS provide
- Linkers and loaders
  - When source code is compiled, they are compiled into an object file
  - Linker combines the object files to an executable
  - A Loader then will bring the executable file into memory from secondary storage
- OS Design and implementation
  - User and system friendly
    - Should be easy for the user to use
    - Should be easy to maintain
  - Implementation
    - Originally was written in Assembly
    - Now days C or C++
- OS structure
  - Monolithic
    - Single binary, single kernel
    - Runs on a single address space
    -

## Chapter 3: Process - concept of a process capturing a program execution, creating, and terminating a process, IPC

- Process
  - An OS executes variety of programs where each run on a process
  - A program becomes a process when it gets moved into main memory and get ready to execute
- Process control blocks
  - Process control block's purpose is to store all information about a specific process
  - Each block contains information like; the process state, program counters, CPU registers, I/O states
- Threads
  - The purpose of threads is to maximize the utilization of the CPU
- Scheduling process
  - The purpose of scheduling is to maximize the CPU
  - There are two different types of ques, short and long term
    - Long term is the queue in which jobs exists in the memory
    - Short term queue is the queue which is the tasks that the CPU is going to execute
- Context switch
  - When a CPU switches from different processes it will save the state of the old and load the saved state of the other process
- Dual-mode operation
  - User mode and kernel mode

## Chapter 4: Thread - concept of a thread and multi-threaded process for concurrent execution of a program

- Concurrency vs parallelism
  - Concurrency, single core spreads tasks out
  - Parallelism, multiple cores tasks are spread out on all of them
- Data parallelism
  - Data space is divided into the different cores
- Task parallelism
  - Data isn't divided but spread out on all the different cores
- Thread
  - A thread is executing when its residents in the registers
  - When a thread executes it moves between different states
    - New, ready, running, waiting, terminated
  - Thread cancellation
    - Asynchronization cancellation – terminates the thread immediately
    - Deferred cancellation – Checks if it should be terminated. Meaning that it won't terminate right away but rather terminated whenever it has a chance
  - A process contains two major units, a thread, and an address space
  -

## Chapter 5: CPU scheduling - CPU scheduling algorithms including realtime scheduling, and issues with multiprocessor scheduling and thread scheduling

## Objectives

- Describe various CPU scheduling algorithms
- Evaluate CPU scheduling algorithms based on scheduling criteria
- Explain the issues related to multiprocessor and multicore scheduling
- Describe real-time scheduling algorithms
- Apply modeling and simulations to evaluate CPU scheduling algorithms

- CPU schedular
  - Selects one process or one thread from the ready queue and allocates a CPU core to it

- Non primitive means that if a task has started executing it will finish it. Primitive means that if a short job comes in the CPU will switch

  -

## Chapter 6-7: Synchronization - critical section problem, synchronization tools (hardware and software), and synchronization examples
