# include <unistd.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putstr(char *s)
{
    while (*s)
        ft_putchar(*s++);
}

int main(int argc, char **argv)
{
    char *s1;
    char *s2;
    int i = 0;
    int j = 0;

    if (argc == 3)
    {
        s1 = argv[1];
        s2 = argv[2];
        while (s1[i])
        {
            while (s2[j])
            {
                if (s1[i] == s2[j])
                {
                    ft_putchar(s1[i]);
                    break;
                }
                j++;
            }
            j = 0;
            i++;
        }
        
    }
}