#include<stdio.h>
#include<stdlib.h>
#define MIN_PID 300
#define MAX_PID 5000
#define n 4700

int *PID;	//Pointer for initialization of data structure
int flag = 1;	//Check if memory has already been allocated

//Creates and initializes a data structure for representing pids; -1 returns if unsuccessful, 1 if successful

int allocate_map(void)
{
	int buff[n+1];
	PID = buff;
	if(PID == NULL)
	{
		printf("Failed to allocate the memory\n");
		return -1;
	}
	if(flag == 0)
	{
		printf("Allocation of memory is already done\n");
		return -1;
	}
	for(int i = 0; i <= n; i++)
	{
		PID[i] = 0;
	}

	flag = 0;
	printf("Memory has been allocated\n");
	return 1;
}

//Allocates and returns a pid; returns -1 if unable to allocate a pid(all pids are in use)

int allocate_pid(void)
{
	if(PID == NULL)
	{
		printf("Failed to allocate the memory\n");
		return -1;
	}
	
	int start = -1, i;
	for(i = 0; i<=n; i++)	//Allocation of PID
	{
		if(PID[i] == 0)
		{
			PID[i] = 1;
			start = i + MIN_PID;
			break;
		}
	}
	if(start == -1)
	{
		printf("Failed to allocate the memory\n");
		return -1;
	}
	printf("Allocated PID = %d\n", start);
	return 1;
}

//Releases PID

int release_pid(int pid)
{
	if(PID == NULL)
	{
		printf("Uninitialized PID Manager\n");
		return -1;
	}

	if(pid < MIN_PID || pid > MAX_PID)
	{
		printf("Out of range\n");
		return -1;
	}
	int pid_num = pid - MIN_PID;

	if(PID[pid_num] == 0)
	{
		printf("PID %d is empty\n", pid);
		return -1;
	}

	printf("Released PID = %d \n", pid);
	PID[pid_num] = 0;
	return 1;
}

void main()
{
	int a;
	char k;
	while(1)	//Choose the desired key for PID Manager
	{
		printf("Input A to create and initialize a data structure for representing PID\n");
		printf("Input B to allocate and return a PID\n");
		printf("Input C to release PID\n");
		printf("Or input any choice to exit\n");
		printf("Choice:");
		scanf(" %c", &k);
		switch(k)
		{
			case 'A' : allocate_map();
				   break;
			case 'B' : allocate_pid();
				   break;
			case 'C' : printf("Input the number of pid to release\n");
				   scanf("%d", &a);
				   release_pid(a);
				   break;
			default :  printf("End of the Program\n");
				   exit(0);
		}
	}
}
