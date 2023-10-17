#include "holberton.h"

/**
 * printf_c - Print a character
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int printf_c(va_list *args)
{
	char c = va_arg(*args, int);

	_putchar(c);
	return (1);
}
