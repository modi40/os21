#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
pid_t pid = fork();
if(pid < 0) {
perror("Fork failed");
exit(1);
}
if(pid == 0) {
printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
int val = nice(-5);
printf("Child Process: Higher priority assigned using nice(-5), return value = %d\n", val);
} else {
int val = nice(5);
printf("Parent Process: PID = %d, nice(5) called, return value = %d\n", getpid(), val);
wait(NULL);
printf("Parent Process: Child completed.\n");
}
return 0;
}
