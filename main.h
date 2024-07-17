#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
* struct fmt - Struct op
*
* @fmt: The format.
* @fn: The function associated.
*/
struct fmt
{
	char fmt;

	int (*fn)(va_list, char[], int, int, int, int);
};


/**
* typedef struct fmt fmt_t - Struct op
*
* @fmt: The format.
* @fm_t: The function associated.
*/
typedef struct fmt fmt_t;

int _printf(const char *format, ...);

int handle_print(const char *fmt, int *i,

va_list list, char buffer[], int flags, int width, int precision, int size);


/* Funtions to print chars and strings */
int print_charr(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int printt_string(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int printt_percent(va_list types, char buffer[],

	int flags, int width, int precision, int size);

/* Functions to print numbers */
int printt_int(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int printt_binary(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int printt_unsigned(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int printt_octal(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int printt_hexadecimal(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int printt_hexa_upper(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int printt_hexa(va_list types, char map_to[],

char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int printt_non_printable(va_list types, char buffer[],

	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int printt_pointer(va_list types, char buffer[],

	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);

int get_width(const char *format, int *i, va_list list);

int get_precision(const char *format, int *i, va_list list);

int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int printt_reverse(va_list types, char buffer[],

	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int printt_rot13string(va_list types, char buffer[],

	int flags, int width, int precision, int size);

/* width handler */
int handle_write_charr(char c, char buffer[],

	int flags, int width, int precision, int size);

int write_numberr(int is_positive, int ind, char buffer[],

	int flags, int width, int precision, int size);

int write_numm(int ind, char bff[], int flags, int width, int precision,

	int length, char padd, char extra_c);

int write_pointerr(char buffer[], int ind, int length,

	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgndd(int is_negative, int ind,

char buffer[],

	int flags, int width, int precision, int size);


/* UTILS */
int iss_printable(char);
int append_hexa_codee(char, char[], int);
int is_digitt(char);

long int convert_size_numberr(long int num, int size);

long int convert_size_unsgndd(unsigned long int num, int size);

#endif
