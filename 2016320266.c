#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
	
int main(void)
{
	pid_t pid1,pid2,pid3;
	int status;

	pid1=fork();
	if(pid1==0)

	{
		pid2=fork();
		if(pid2==0)
		{

			printf("5 My PID : %d My Parents PID %d\n",getpid(),getppid());
			exit(1);
		}
		pid3=fork();
		if(pid3==0)
		{
			printf("6 My PID : %d My Parents PID %d\n", getpid(),getppid());
			exit(1);
		}
		wait(&status);
		wait(&status);
		printf("2 My PID : %d My Parents PID %d\n", getpid(),getppid());
		exit(1);
	}
	pid2=fork();
	if(pid2==0)
	{
		printf("3 My PID : %d My Parents PID %d\n", getpid(),getppid());
		exit(1);
	}
	pid3=fork();
	if(pid3==0)
	{
		printf("4 My PID : %d My Parents PID %d\n", getpid(),getppid());
		exit(1);
	}
	wait(&status);
	wait(&status);
	wait(&status);
	printf("1 My PID : %d\n",getpid());
}
