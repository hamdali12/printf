#include "holberton.h"

/**
 * printf_s - Print a string
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int printf_s(va_list *args)
{
	char *str = va_arg(*args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

		while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}
