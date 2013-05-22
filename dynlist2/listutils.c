#include "listutils.h"

list_t* make_double_list(size_t initial_capacity)
{
	return make_list(initial_capacity, sizeof(double));
}

list_t* make_int_list(size_t initial_capacity)
{
	return make_list(initial_capacity, sizeof(int));
}
