#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Write a function that produces output according to a format.
 * @format: handle the first strigs in te function
 *
 * Return: 0 always on success
 */

int _printf(const char *format, ...)
{
	char *myString;
	int MyChar;
	int count;
	va_list args;

	count = 0;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
		if (*format == 'c')
		{
			MyChar = va_arg(args, int);
			putchar(MyChar);
			count++;
		}
		else if (*format == 's')
		{
			myString = va_arg(args, char *);
			while (*myString)
			{
				putchar(*myString);
				myString++;
				count++;
			}
		}
		else if (*format == '%')
		{
			putchar('%');
			count++;
		}
		else
		{
			putchar('%');
			putchar(*format);
			count += 2;
		}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
