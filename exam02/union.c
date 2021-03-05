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

    int s[255];
    int i;
    int j = 0;

    if (argc == 3)
    {
        i = 0;
        while (s[i])
        {
            s[i] = 0;
            i++;
        }
        i = 1;
        
        while ( i < 3)
        {
            while (argv[i][j])
            {
                if (!s[(unsigned char)argv[i][j]])
                {
                    ft_putchar(argv[i][j]);
                    s[(unsigned char)argv[i][j]] = 1;
                }
                j++;
            }
            j = 0;
            i++;
        }
        
        
    }
}