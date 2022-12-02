#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>

/*
A, X = Draw (1 + 3) -> Lose Z (3 + 0)
A, Y = Win (2 + 6) -> Draw X (1 + 3)
A, Z = Lose (3 + 0) -> Win Y (2 + 6)

B, X = Lose (1 + 0) -> Lose
B, Y = Draw (2 + 3) -> Draw
B, Z = Win (3 + 6) -> Win

C, X = Win (1 + 6) -> Lose Y (2 + 0)
C, Y = Lose (2 + 0) -> Draw Z (3 + 3)
C, Z = Draw (3 + 3) -> Win X (1 + 6)
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
					count_r += 3;
				else if (a[2] == 'Y')
				{
					count_r += 4;
				}
				else if (a[2] == 'Z')
					count_r += 8;
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
				{
					printf ("start here, adding 9 ");
					count_r += 9;
				}
				//printf("%d\n", count_r);
			}
			else if (a[0] == 'C')
			{
				//printf("in\n");
				if (a[2] == 'X')
					count_r += 2;
				else if (a[2] == 'Y')
					count_r += 6;
				else if (a[2] == 'Z')
					count_r += 7;
			}
		}
		printf("total %d\n", count_r);
	}
	free(a);
	return (0);
}