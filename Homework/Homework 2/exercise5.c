#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char msg[50] = "empty message";
    const char secret_msg[] = "secret message"; 
    int secret_length = strlen(secret_msg);
    int pfds[2];
    
    pipe(pfds);                                         // Hint: invoke pipe() here
    pid_t pid = fork();
    if ( pid > 0 ) {                                    // parent
        wait(0);                                        // wait for the child
        close(0);                                       // Hint: invoke close() here
        read(pfds[0], msg, secret_length);              // Hint: invoke read here
        printf("The message in parent is %s\n", msg);
    } else {                                            // child
        strcpy(msg, secret_msg);
        close(0);                                       // Hint: invoke close() here
        write(pfds[1], secret_msg, secret_length);      // Hint: invoke write here
        printf("The message in child is %s\n", msg);
    }
    return 0;
}
