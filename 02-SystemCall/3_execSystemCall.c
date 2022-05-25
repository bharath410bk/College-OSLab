#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    pid_t pid;
    switch(pid = fork()){ 
        case -1:
            perror("Fork failed");
            exit(-1);
        case 0:
            printf("Child process\n");
            execl("/bin/date", "date", 0);
            exit(0);
        default:
            wait();
            printf("Child Terminated\n");
            exit(0);
    } 
    return 0;
}