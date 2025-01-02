#include <unistd.h>

void ft_print_double_nb(int n, int is_final)
{
	char arr[2];

	arr[0] = n / 10 + '0';
	arr[1] = n % 10 + '0';
	write(1, arr, 2);
	if (is_final != 0)
		write(1, ", ", 2);
}

void ft_print_combo2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 100)
	{
		b = 0;
		while (b < 100)
		{
			if (a < b)
			{
				ft_print_double_nb(a, 0);
				write(1, " ", 1);
				if (a == 98 && b == 99)
					ft_print_double_nb(b, 0);
				else
					ft_print_double_nb(b, 1);
			}
			b++;
		}
		a++;
	}
}

int main (void)
{
	ft_print_combo2();
	return (0);
}