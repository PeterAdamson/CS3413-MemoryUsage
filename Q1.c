//Author Peter Adamson

#include <stdio.h>
#include <stdlib.h>

void allocate();

int main()
{
	while(1)
	{
		int num;
		int i = 0;
		printf("how many times would you like to loop? ");
		fscanf(stdin, "%d", &num);
		if(num > 0)
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
}

void allocate()
{
	int bytes = 1024;
	int *i = (int*)malloc(bytes);
	printf("allocated 1 K\n");
}

/*With respect to memory utilization, the amount of used memory steadily increased while the amount of free memory correspondingly decreased during the running of this program compared to before the program was run.  This consumed memory was a result of repeatedly allocating 1 KB of memory without ever deallocating it.  Upon completion of the program, all the allocated memory was freed and the amount of used memory decreased while free memory increased proportionally.*/
