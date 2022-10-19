/*
    COMP3511 Fall 2022 
    PA1: Simplified Linux Shell (MyShell)

    Your name:              Casper Kristiansson
    Your ITSC email:        cok@connect.ust.hk 

    Declaration:

    I declare that I am not involved in plagiarism
    I understand that both parties (i.e., students providing the codes and students copying the codes) will receive 0 marks. 

*/

// Note: Necessary header files are included
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h> // For constants that are required in open/read/write/close syscalls
#include <sys/wait.h> // For wait() - suppress warning messages
#include <fcntl.h> // For open/read/write/close syscalls

// Assume that each command line has at most 256 characters (including NULL)
#define MAX_CMDLINE_LEN 256

// Assume that we have at most 8 arguments
#define MAX_ARGUMENTS 8

// Assume that we only need to support 2 types of space characters: 
// " " (space) and "\t" (tab)
#define SPACE_CHARS " \t"

// The pipe character
#define PIPE_CHAR "|"

// Assume that we only have at most 8 pipe segements, 
// and each segment has at most 256 characters
#define MAX_PIPE_SEGMENTS 8

// Assume that we have at most 8 arguments for each segment
//
// We also need to add an extra NULL item to be used in execvp
//
// Thus: 8 + 1 = 9
//
// Example: 
//   echo a1 a2 a3 a4 a5 a6 a7 
//
// execvp system call needs to store an extra NULL to represent the end of the parameter list
//
//   char *arguments[MAX_ARGUMENTS_PER_SEGMENT]; 
//
//   strings stored in the array: echo a1 a2 a3 a4 a5 a6 a7 NULL
//
#define MAX_ARGUMENTS_PER_SEGMENT 9

// Define the  Standard file descriptors here
#define STDIN_FILENO    0       // Standard input
#define STDOUT_FILENO   1       // Standard output 


 
// This function will be invoked by main()
void process_cmd(char *cmdline);

// read_tokens function is given
// This function helps you parse the command line
// Note: Before calling execvp, please remember to add NULL as the last item 
void read_tokens(char **argv, char *line, int *numTokens, char *token);

// Here is an example code that illustrates how to use the read_tokens function
// int main() {
//     char *pipe_segments[MAX_PIPE_SEGMENTS]; // character array buffer to store the pipe segements
//     int num_pipe_segments; // an output integer to store the number of pipe segment parsed by this function
//     char cmdline[MAX_CMDLINE_LEN]; // the input argument of the process_cmd function
//     int i, j;
//     char *arguments[MAX_ARGUMENTS_PER_SEGMENT] = {NULL}; 
//     int num_arguments;
//     strcpy(cmdline, "ls | sort -r | sort | sort -r | sort | sort -r | sort | sort -r");
//     read_tokens(pipe_segments, cmdline, &num_pipe_segments, PIPE_CHAR);
//     for (i=0; i< num_pipe_segments; i++) {
//         printf("%d : %s\n", i, pipe_segments[i] );    
//         read_tokens(arguments, pipe_segments[i], &num_arguments, SPACE_CHARS);
//         for (j=0; j<num_arguments; j++) {
//             printf("\t%d : %s\n", j, arguments[j]);
//         }
//     }
//     return 0;
// }


int main() {
    char cmdline[MAX_CMDLINE_LEN];
    fgets(cmdline, MAX_CMDLINE_LEN, stdin);
    process_cmd(cmdline);
    return 0;
}

void process_cmd(char *cmdline) {
    char *pipe_segments[MAX_PIPE_SEGMENTS];
    int num_pipe_segments;

    char *arguments[MAX_ARGUMENTS_PER_SEGMENT] = {NULL};
    int num_arguments;
    int pfds[2];

    // Split the command by the pipe character
    read_tokens(pipe_segments, cmdline, &num_pipe_segments, PIPE_CHAR);

    for (int i = 0; i < num_pipe_segments; i++) {
        // Split the command by the space character (get the arguments)
        read_tokens(arguments, pipe_segments[i], &num_arguments, SPACE_CHARS);
        arguments[num_arguments] = NULL;

        // If the command contains a redirection symbol (> or <)
        for (int j = 0; j < num_arguments; j++) {
            if (strcmp(arguments[j], "<") == 0) {
                int fd = open(arguments[j+1], O_RDONLY, S_IRUSR | S_IWUSR);
                dup2(fd, STDIN_FILENO);
                close(fd);

                arguments[j] = NULL;
            } else if (strcmp(arguments[j], ">") == 0) {
                int fd = open(arguments[j+1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
                dup2(fd, STDOUT_FILENO);
                close(fd);

                arguments[j] = NULL;
            }
        }

        // Check if the command is not the last command in the entire command line input
        if (i+1 != num_pipe_segments) {
            pipe(pfds);
            pid_t pid = fork();

            if (pid == 0) {
                close(STDOUT_FILENO);
                dup2(pfds[1], STDOUT_FILENO);
                close(pfds[0]);

                execvp(arguments[0], arguments);
            } else {
                close(STDIN_FILENO);
                dup2(pfds[0], 0);
                close(pfds[1]);

                wait(0);
            }
        } else {
            execvp(arguments[0], arguments);
        }
    }
}

void read_tokens(char **argv, char *line, int *numTokens, char *delimiter)
{
    int argc = 0;
    char *token = strtok(line, delimiter);
    while (token != NULL)
    {
        argv[argc++] = token;
        token = strtok(NULL, delimiter);
    }
    *numTokens = argc;
}
