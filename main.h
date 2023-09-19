#ifndef MAIN_H
#define MAIN_H
void printString(const char *str);
void printChar(int c);
int handleSpecifier(const char *format, va_list args);
int _printf(const char *format, ...);
#endif

