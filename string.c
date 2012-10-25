#include "string.h"
#include "vtxprintf.h"
#include "serial.h"

void *
memcpy(void *dst, const void *src, size_t count)
{
    const uint8_t *s = (const uint8_t *)src;
    uint8_t *d = (uint8_t *)dst;
    for (; count != 0; count--)
        *d++ = *s++;

    return dst;
}

void *
memset(void *dst, int c, size_t count) 
{
    char *p = (char *)dst;

    for (; count != 0; count--)
        *p++ = c;

    return dst;
}

void *
wmemset(void *dst, int c, size_t count)
{
    unsigned short *tmp = (unsigned short *)dst;

    for (; count != 0; count--)
        *tmp++ = c;

    return dst;
}

size_t 
strlen(const char *str)
{
    size_t ret;

    for (ret = 0; *str != '\0'; str++)
        ret++;

    return ret;
}

size_t 
strnlen(const char *str, size_t max)
{
    size_t ret;
    for (ret = 0; *str != '\0' && ret < max; str++)
        ret++;

    return ret;
}

int 
strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
        s1++, s2++;
    
    return *s1 - *s2;
}

static char *str_buf;
static void str_tx_byte(unsigned char byte)
{
	*str_buf = byte;
	str_buf++;
}

int 
vsprintf(char *buf, const char *fmt, va_list args)
{
	int i;

	str_buf = buf;
	i = vtxprintf(str_tx_byte, fmt, args);
	*str_buf = '\0';

	return i;
}

int 
sprintf(char *buf, const char *fmt, ...)
{
	va_list args;
	int i;
	va_start(args, fmt);
	i = vsprintf(buf, fmt, args);
	va_end(args);

	return i;
}

