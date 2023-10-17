#include "main.h"

/**
 * printf_i_d - Print an integer
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int printf_i_d(va_list *args)
{
	int n = va_arg(*args, int);

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	return (print_number(n));
}
