#ifndef GUARD_LIST_H
#define GUARD_LIST_H

#include <string.h> // fuer size_t
#include <stdbool.h>

typedef struct list_t
{
	void *elements;
	size_t size;
	size_t capacity;
	size_t elemsize;
} list_t;

list_t* make_list(size_t initial_capacity, size_t elemsize);
void free_list(list_t*);

bool append(list_t*, const void*);
bool append_list(list_t*, list_t*);
bool append_all(list_t*, size_t numelems, ...);

bool insert(list_t *l, size_t pos, const void *elem);
bool insert_list(list_t*, size_t pos, list_t*);
bool insert_all(list_t*, size_t pos, size_t numelems, ...);

bool replace(list_t *l, size_t pos, const void* elem);

#endif /* GUARD_LIST_H */
