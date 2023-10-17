#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int char_count = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format != '%')
        {
            putchar(*format);
            char_count++;
        }
        else
        {
            format++; // Move past '%'
            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    putchar(c);
                    char_count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    while (*str)
                    {
                        putchar(*str);
                        char_count++;
                        str++;
                    }
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    if (num < 0)
                    {
                        putchar('-');
                        char_count++;
                        num = -num;
                    }
                    int digit_count = 0;
                    int temp = num;
                    while (temp > 0)
                    {
                        temp /= 10;
                        digit_count++;
                    }
                    int divisor = 1;
                    for (int i = 1; i < digit_count; i++)
                        divisor *= 10;
                    while (divisor > 0)
                    {
                        char digit = (num / divisor) + '0';
                        putchar(digit);
                        char_count++;
                        num %= divisor;
                        divisor /= 10;
                    }
                    break;
                }
                case '%':
                {
                    putchar('%');
                    char_count++;
                    break;
                }
                default:
                {
                    putchar('%');
                    char_count++;
                    if (*format != '\0')
                    {
                        putchar(*format);
                        char_count++;
                    }
                }
            }
        }
        format++;
    }

    va_end(args);
    return char_count;
}
