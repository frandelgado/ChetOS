#ifndef LIB_H
#define LIB_H

#include <stdint.h>
#include <sys/types.h>

#define NULL ((void*)0)
void * memset(void * destination, int32_t character, uint64_t length);
void * memcpy(void * destination, const void * source, uint64_t length);
int memcmp(const char * destination, const char * source, uint8_t length);
int strcmp(const char* s1, const char* s2);
char *cpuVendor(char *result);

#endif
