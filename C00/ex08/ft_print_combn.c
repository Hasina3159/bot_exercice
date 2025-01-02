#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void ft_putlong(long nb)
{
    char c;

    c = nb % 10 + '0';
    if (nb > 9)
        ft_putlong(nb / 10);
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    long    n;

    n = nb;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    ft_putlong(n);
}

int ft_is_nb_croissant(int nb)
{
    int tmp;
    int was_in;

    tmp = INT_MAX;
    was_in = 0;
    while (nb)
    {
        if (tmp <= nb % 10)
            return (0);
        was_in = 1;
        tmp = nb % 10;
        nb = nb / 10;
    }
    if (was_in)
        return (1);
    return (0);
}

int ft_n_to_nb(int n)
{
    int x;

    x = 1;
    while (n)
    {
        x = x * 10;
        n--;
    }
    return (x);
}

void ft_print_combn(int n)
{
    int max;
    int i;

    max = ft_n_to_nb(n);
    i = 0;
    while (i < max)
    {
        if (ft_is_nb_croissant(i))
        {
            if (i < max / 100)
            {
                i++;
                continue;
            }
            if (i < max / 10)
                write(1, "0", 2);
            ft_putnbr(i);
            if ((i % 10 == 9) && (i / (max / 10) == 9 - n + 1))
                return;
            write(1, ", ", 2);
        }
        i++;
    }
}

int main (int argc, char **argv)
{
    if (argc != 2)
        return (0);
    ft_print_combn(atoi(argv[1]));
    return (0);
}