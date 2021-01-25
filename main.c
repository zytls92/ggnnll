#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd;
	char *line;

	fd = open("txt",O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n",line);
		free(line);
	}
	printf("%s",line);
	free(line);
	//printf("%d\n",get_next_line(fd, &line));
}
