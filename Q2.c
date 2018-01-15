//Author Peter Adamson

#include <stdio.h>
#include <stdlib.h>

void allocate();

int t;
size_t addr[100000];

int main()
{
	int loop = 1;
	int num;
	int i;
	int j;
	int t = 0;
	int diffSum = 0;
	int diffAvg;
	while(loop == 1)
	{
		printf("how many times would you like to loop? (0 to exit)");
		fscanf(stdin, "%d", &num);
		if(num == 0)
		{
			loop = 0;
		}
		else if(num > 0)
		{
			for(i = 0; i < num; i++)
			{
				allocate();
			}	
		}
		else
		{
			printf("please enter a valid number\n");
		}
		printf("completed looping %d times.  Lets go again.\n",num);
	}
	for(i = 0; i < 99999; i++)
	{
		diffSum = diffSum + (addr[i+1] - addr[i]);
	}
	diffAvg = diffSum / (100000);
	printf("average difference between calls to malloc: %d\n",diffAvg);
	printf("exiting\n");
}

void allocate()
{
	int bytes = 1024;
	int *i = (int*)malloc(bytes);
	addr[t] = (size_t)i;
	printf("address of i: %p\n",addr[t]);
	t = t + 1;
}

/*Upon looping 100000 times and getting the average of differences between addresses between calls to malloc, the average difference between calls was 1039.  This means that the memory allocation consistently allocated the same amount of memory between calls (expected behaviour) but that the allocated size of the memory was actually a bit larger than the 1024 specified.  This implies that there is some other data being stored along with the allocated size specified, e.g. memory location*/
