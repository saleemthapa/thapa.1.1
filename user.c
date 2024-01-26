#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
// Handling segmentation fault
  if(argc < 2) {
    printf("\nInteger needs to be passed...aborting\n\n");
    
    return 0;
  }
int  useriter = 0;
useriter = atoi(argv[1]);
//user loop
for(int i = 1; i <= useriter; i++){
	printf("\nUSER PID: %d  PPID: %d  Iteration: %d  before sleeping\n", getpid(), getppid(), i);
    	sleep(1);
    	printf("USER PID: %d  PPID: %d  Iteration: %d  after sleeping\n\n", getpid(), getppid(), i);
}//forloopclose
return 0;
}
