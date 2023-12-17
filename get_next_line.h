#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

size_t ft_strlen(char *s);
char *ft_strchr(char *str, int character);
char *ft_strjoin(char *left_str, char *buff);
char *ft_line(char *str);
char *new_str(char *str);
char *read_line(int fd, char *str);
char *get_next_line(int fd);

#endif