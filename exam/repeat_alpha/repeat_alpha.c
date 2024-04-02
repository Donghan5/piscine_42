#include <unistd.h>
// this one is not correct !
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int index_alpha(char c)
{
    int res;

    res = 0;
    if (c >= 'A' && c <= 'Z')
        res = (c - 'A') + 1;
    if (c >= 'a' && c <= 'z')
        res = (c - 'a') + 1;
    else
        res = 1;
    return (res);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    
    if (argc != 2)
    {
        ft_putchar('\n');
    }
    if (argc == 2)
    {
        i = 0;
        while (argv[1][i] != '\0')
        {
            j = index_alpha(argv[1][i]);
            while(j > 0)
            {
                ft_putchar(argv[1][i]);
                j--;
            }
            i++;
        }
        ft_putchar('\n');
    }
    return (0);
}