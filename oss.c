#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <getopt.h>
int main(int argc, char *argv[]) {
int process = 0;
int simulation = 0;
int iteration = 0;

int opt;
while((opt = getopt(argc, argv, "hn:s:t:"))!= -1){
	switch (opt){
		case 'h':
			printf("\nProgram should be executed as follows:\n");
        		printf("\n./oss [-n proc] [-s simul] [-t iter]\n");
        		printf("\n[-n proc] parameter stands for number of total children to launch\n");
	       		printf("\n[-s simul] parameter indicates how many children to allow to run simultaneously\n");
        		printf("\n[-t iter] is the number to pass to the worker process\n");
        		printf("\nproc, simul, iter should all be integer values\n\n");
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
return 0;
}
