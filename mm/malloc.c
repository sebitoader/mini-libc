// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0) {
        return NULL;
    }
    void *allocated_memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (allocated_memory == MAP_FAILED) {
        return NULL;
    }
    if (mem_list_add(allocated_memory, size) < 0) {
        munmap(allocated_memory, size);
        return NULL;
    }
    return allocated_memory;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
    if (nmemb != 0 && total_size / nmemb != size) {
        return NULL;
    }
    void *memory = malloc(total_size);
    if (memory == NULL) {
        return NULL;
    }
    memset(memory, 0, total_size);
    return memory;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
    	return;
    }
    struct mem_list *zone = mem_list_find(ptr);
    if (zone == NULL) {
        return;
    }
    munmap(ptr, zone->len);
    mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	 if (ptr == NULL) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    struct mem_list *item = mem_list_find(ptr);
    if (item == NULL) {
        return NULL;
    }
    if (item->len == size) {
        return ptr;
    }
    void *new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }
    size_t copy_size = (item->len < size) ? item->len : size;
    memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total_size = nmemb * size;
    if (nmemb != 0 && total_size / nmemb != size) {
        return NULL;
    }
    return realloc(ptr, total_size);
	return NULL;
}
