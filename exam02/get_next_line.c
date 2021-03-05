#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return(i);
}

char *ft_strchr(char *s,char c)
{
	char *str = s;
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return(0);
}

char *ft_strjoin(char *s1,char *s2)
{
	char *pstr;
	char *str;

	if (!s1 && !s2)
		return(0);
	str = malloc (1 + (s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0));
	pstr = str;
	if (s1)
		while (*s1)
		{
			*pstr++ = *s1++;
		}
	if (s2)
		while (*s2)
		{
			*pstr++ = *s2++;
		}
	*pstr = '\0';
	return (str);
}

void ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = 0;
	}
}

int get_next_line(char **line)
{
	static char *save;
	char *tmp;
	char *check;
	char buff[BUFFER_SIZE + 1];
	int len;

	while ((len = read(0,buff,BUFFER_SIZE)) > 0)
	{
		buff[len] = '\0';
		tmp = save;
		save = ft_strjoin(save,buff);
		ft_free(tmp);
		if (ft_strchr(save,'\n'))
			break;
	}
	if (len < 0)
		return (-1);
	if (len == 0 && save == 0)
	{
		*line = ft_strjoin("",0);
		ft_free(save);
		return(1);
	}
	if ((check = ft_strchr(save,'\n')))
	{
		tmp = save;
		*check = '\0';
		*line = ft_strjoin(save,"");
		check++;
		save = ft_strjoin(check,"");
		ft_free(tmp);
		return(1);
	}
	else
	{
		*line = ft_strjoin(save,"");
		free(save);
		return (0);
	}
}