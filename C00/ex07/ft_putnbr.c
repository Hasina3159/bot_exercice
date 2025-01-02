#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
int main(void)
{
    ft_putnbr(-2147483648);
    return (0);
}
