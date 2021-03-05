#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SZ 256
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

int	get_next_line(char **line);

#endif

