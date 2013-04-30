#include <stdlib.h>
#include <assert.h>

typedef struct
{
	double *elements;
	size_t size; // number of actual elements in list
	size_t capacity; // number of possible elements in list
} list_t;

void append(list_t *l, double d)
{
	++l->size;
	if (l->size > l->capacity)
	{
		// TODO BEGIN: move initialisation to list initialiser
		if (l->capacity == 0)
			l->capacity = 1;
		// TODO END
		l->capacity *= 2;
		l->elements = realloc(l->elements, l->capacity * sizeof(double));
	}
	*(l->elements + l->size - 1) = d;
}

int main(void)
{
	list_t l = { .elements = NULL, .size = 0, .capacity = 0 };

	append(&l, 3.14);
	assert(l.size == 1);
	assert(l.capacity == 2);
	assert(l.elements[0] == 3.14);

	append(&l, 2.71);
	assert(l.size == 2);
	assert(l.capacity == 2);
	assert(l.elements[0] == 3.14);
	assert(l.elements[1] == 2.71);

	free(l.elements);
	l.elements = NULL;
	l.size = l.capacity = 0;

	return 0;
}
