#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <getopt.h>
#include <errno.h>
int main(int argc, char *argv[]) {
int process = 0;
int simulation = 0;
int iteration = 0;

int opt;
if(argc == 1 || argc > 10){
	printf("Bad Input! Program usage: ./oss -h for to list options.\n");
	return EXIT_FAILURE;
	}

while((opt = getopt(argc, argv, "hn:s:t:"))!= -1){
	switch (opt){
		case 'h':
			printf("\nProgram should be executed as follows:\n");
        		printf("\n./oss [-n proc] [-s simul] [-t iter]\n");
        		printf("\n[-n process] is  number of total children to launch\n");
	       		printf("\n[-s simulation] indicates how many children to allow to run simultaneously\n");
        		printf("\n[-t iteration] which is the number to pass to the worker process\n");
        		printf("\nprocess, simulation, iteration should all be integer values\n\n");
		case 'n':
			if(optarg!= NULL){
				process = atoi(optarg);
				break;
			}
		case 's':
			if(optarg!= NULL){
				simulation = atoi(optarg);
				break;
			}
		case 't':
			if(optarg!= NULL){
				iteration = atoi(optarg);
				break;
			}
		default:
			fprintf(stderr, "Usage: %s [-h] [-n proc] [-s simul] [-t iter]\n", argv[0]);
                	exit(EXIT_FAILURE);

	}
}
printf("From Parent:\n\nProc: %d\nSimul: %d\nIter: %d\n", process, simulation, iteration); 
for(int i = 1; i <= process;i++){
pid_t  childPid = fork();
if(childPid == -1){
	perror("Fork Failed");
	exit(1);
	}//childPidifclause
else if(childPid == 0){
	char *iterationarr = calloc(iteration,sizeof(char));//type casting the intteger to character array becuase exclp
 //function only accepts integer in character array form
	execlp("./user","./user", iterationarr, NULL);
	perror("Exec failed, terminating\n");
		exit(1);

	}//elseifclose
else{	
	if(i >= simulation){
		wait(NULL);
	}//ifsimulationclose
}//elseloopclose
}//forloopclose
return 0;
}
