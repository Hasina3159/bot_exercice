/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: petera <petera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:14:20 by petera            #+#    #+#             */
/*   Updated: 2025/01/02 13:41:10 by petera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_nb(int n, int fin)
{
    char    tmp;

    tmp = n + '0';
    write (1, &tmp, 1);
    if (fin != 0)
        write (1, ", ", 2);
}

void    ft_print_comb(void)
{
    int a;
    int b;
    int c;
    a = 0;
    while (a < 10)
    {
        b = 0;
        while (b < 10)
        {
            c = 0;
            while (c < 10)
            {
                if (a < b && b < c)
                {
                    ft_print_nb (a, 0);
                    ft_print_nb (b, 0);
                    if (a == 7 && b == 8 && c == 9)
                        ft_print_nb (c, 0);
                    else
                        ft_print_nb (c, 1);
                }
                c++;
            }
            b++;
        }
        a++;
    }
}
int main( void )
{
    ft_print_comb();
    return (0);
}
