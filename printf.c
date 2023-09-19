#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <string.h>


/**
 * printChar - Print single characters
 * @c: single character values handler
 *
 * Return: nothing
 */

void printChar(int c)
{
	putchar(c);
}

/**
 * printString - function that handles string characters
 * @str: string value
 *
 * Return: nothing
 */
void printString(const char *str)
{
	while (*str)
	{
		putchar(*str);
		str++;
	}
}

/**
 *  handleSpecifier - handle the specifiers
 *  @format: handle the first string in the function
 *  @args: arguement 1
 *
 *  Return: 0 always on success
 */

int handleSpecifier(const char *format, va_list args)
{
	int num;
	int count;
	int MyChar;
	char *MyString;

	count = 0;

	switch (*format)
	{
		case 'c':
			{
				MyChar = va_arg(args, int);
				printChar(MyChar);
				count++;
				break;
			}
		case 's':
			{
				MyString = va_arg(args, char *);
				printString(MyString);
				count += strlen(MyString);
				break;
			}
		case '%':
				printChar('%');
				count++;
				break;
		default:
				printChar('%');
				printChar(*format);
				count += 2;
	}
	return (count);
}

/**
 * _printf - Write a function that produces output according to a format.
 * @format: handles the first string characters
 *
 * Return: 0 always on success
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	count = 0;
	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				va_end(args);
				return (-1);
			}
			count += handleSpecifier(format, args);
		}
		else
		{
			printChar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

