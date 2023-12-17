#include "get_next_line.h"

char *read_line(int fd, char *str)
{
	char *buff;
	int byte;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	byte = 1;
	while (!ft_strchr(str, '\n') && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char *get_next_line(int fd)
{
	char *line;
	static char *str;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = new_str(str);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *str;

// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	close(fd);
// 	return (0);
// }