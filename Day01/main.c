#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>

int main()
{
	int fd = open("./input", O_RDONLY);
	char *a = get_next_line(fd);
	int prsint = 0;
	int sum = 0;
	int maxim = 0;

	while(a != NULL)
	{
		free(a);
		a = get_next_line(fd);
		if (*a != '\n')
		{
			prsint = atoi(a);
			sum += prsint;
		}
		else{
			if (maxim < sum)
				maxim = sum;
			sum = 0;
			printf ("%d\n", maxim);
		}
	}
	free(a);
	return (0);
}