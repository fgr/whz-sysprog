#include "list.h"

#include <stdlib.h>

list_t* make_list(size_t initial_capacity, size_t elemsize)
{
	list_t *l = malloc(1 * sizeof(list_t));
	if (l == NULL )
		return NULL ;
	if ((l->elements = malloc(initial_capacity * elemsize)) == NULL )
	{
		free(l);
		return NULL ;
	}
	l->size = 0;
	l->capacity = initial_capacity;
	l->elemsize = elemsize;
	return l;
}

bool ensure_capacity(list_t *l, size_t capacity)
{
	if (l->capacity < capacity)
	{
		size_t newcap = l->capacity * 2;
		if (l->capacity == 0)
			newcap = 1;
		void* newelems = realloc(l->elements, newcap * l->elemsize);
		if (newelems == NULL )
			return false;
		l->capacity = newcap;
		l->elements = newelems;
		// sicherstellen, dass gewuenschte capacity mithilfe der
		// l->capacity-Erhoehungsstrategie eingehalten wird
		ensure_capacity(l, capacity);
	}
	return true;
}

bool append(list_t *l, const void* elem)
{
	if (!ensure_capacity(l, l->size + 1))
		return false;
	memcpy(l->elements + (l->size * l->elemsize), elem, l->elemsize);
	++l->size;
	return true;
}

bool append_list(list_t *l, list_t *otherl)
{
	for(size_t i = 0; i < otherl->size; ++i)
		if(!append(l, ((char*)otherl->elements)+(i*otherl->elemsize)))
			return false;
	return true;
}

bool insert(list_t *l, size_t pos, const void* elem)
{
	// Platz fuer ein weiteres Element sicherstellen
	if (!ensure_capacity(l, l->size + 1))
		return false;
	// Platz fuer neues Element schaffen, indem Elemente nach rechts verschoben werden
	double *from = l->elements + (pos * l->elemsize);
	double *to = l->elements + ((pos + 1) * l->elemsize);
	const size_t len = (l->size - pos) * l->elemsize;
	// memmove anstatt memcpy, da from und to ueberlappen
	memmove(to, from, len);
	// Element an freigewordene Luecke kopieren
	memcpy(from, elem, l->elemsize);
	l->size += 1;
	return true;
}

bool replace(list_t *l, size_t pos, const void* elem)
{
	if (pos >= l->size)
		// Index pos ungueltig
		return false;
	double *to = l->elements + (pos * l->elemsize);
	memcpy(to, elem, l->elemsize);
	return true;
}

void free_list(list_t* l)
{
	free(l->elements);
	free(l);
}

