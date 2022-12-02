#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>

/*
A, X = Draw (1 + 3)
A, Y = Win (2 + 6)
A, Z = Lose (3 + 0)

B, X = Lose (1 + 0)
B, Y = Draw (2 + 3)
B, Z = Win (3 + 6)

C, X = Win (1 + 6)
C, Y = Lose (2 + 0)
C, Z = Draw (3 + 3)
*/

int main()
{
	int fd = open("./input.txt", O_RDONLY);
	char *a = get_next_line(fd);
	int count_r = 0;
	
	while(a != NULL)
	{
		free(a);
		a = get_next_line(fd);
		//printf("%s", a);
		if (*a != '\n')
		{
			if (a[0] == 'A')
			{
				//printf("in\n");
				if (a[2] == 'X')
					count_r += 4;
				else if (a[2] == 'Y')
				{
					count_r += 8;
					printf ("finish ");
				}
				else if (a[2] == 'Z')
					count_r += 3;
				//printf("%d\n", count_r);
			}
			else if (a[0] == 'B')
			{
				//printf("in\n");
				if (a[2] == 'X')
					count_r += 1;
				else if (a[2] == 'Y')
					count_r += 5;
				else if (a[2] == 'Z')
					count_r += 9;
				//printf("%d\n", count_r);
			}
			else if (a[0] == 'C')
			{
				//printf("in\n");
				if (a[2] == 'X')
				{
					
					count_r += 7;
				}
				else if (a[2] == 'Y')
					count_r += 2;
				else if (a[2] == 'Z')
				{
					printf ("start here, adding 6");
					count_r += 6;
				}
				//printf("%d\n", count_r);
			}
		}
		printf("total %d\n", count_r);
	}
	free(a);
	return (0);
}