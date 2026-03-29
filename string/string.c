// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i = 0;
	while (i <= len) {
		if (source[i] == '\0')
			break;
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i = 0, j = 0, k = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0')
		j++;
	while (k <= j) {
		destination[i + k] = source[k];
		k++;
	}
	destination[i + k] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t i = 0, j = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0' && j < len) {
		destination[i + j] = source[j];
		j++;
	}
	destination[i + j] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0') {
		i++;
	}
	return str1[i] - str2[i];
	//return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t i = 0;
	while (i < len) {
		if(str1[i] != str2[i])
			return str1[i] - str2[i];
		i++;
	}
	return 0;
	//return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	const char *str1 = str;
	while (*str1 != '\0') {
		if(*str1 == c)
			return (char *)str1;
		str1++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *str1 = str;
	while (*str1 != '\0')
		str1++;
	while (str1 != str) {
		if (*str1 == c)
			return (char *)str1;
		str1--;
	}
	if (*str1 == c)
		return (char *)str1;
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int i = strlen(needle);
	int j = strlen(haystack);
	int k = 0;
	const char *start = haystack;
	while(k <= j - i) {
		if (!strncmp(start, needle, i))
			return (char *)start;
		start++;
		k++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int i = strlen(needle);
	int j = strlen(haystack);
	int k = j - i;
	const char *start = haystack + k;
	while(k >= 0) {
		if (!strncmp(start, needle, i))
			return (char *)start;
		start--;
		k--;
	}
	return NULL;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *) destination;
	const char *src = (const char *) source;
	for (size_t i = 0; i < num; i++) {
		dest[i] = src[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *) destination;
	const char *src = (const char *) source;
    char aux[1000];
	for (size_t i = 0 ; i < num; i++) {
		aux[i] = src[i];
	}
	for (size_t i = 0 ; i < num; i++) {
		dest[i] = aux[i];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const char *p1 = (const char *)ptr1;
	const char *p2 = (const char *)ptr2;
	for (size_t i = 0; i < num; i++) {
        if (p1[i] != p2[i]) {
        	return (p1[i] - p2[i]);
        }
    }
	return 0;
	//return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;
	for(size_t i = 0 ; i < num; i++) {
		src[i] = (char)value;
	}
	return source;
}
