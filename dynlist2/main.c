#include <stdio.h> // fuer printf
#include <assert.h>

#include "list.h"
#include "listutils.h"

int main(void)
{
	{
		list_t *dl = make_double_list(8);
		assert(dl->size == 0);
		assert(dl->elemsize == sizeof(double));

		double d = 1.00;
		append(dl, &d);
		assert(dl->size == 1);
		assert(((double* )dl->elements)[0] == d);

//		double d2 = 2.00;
//		assert(append_all(dl, 3, &d, &d, &d2));
//		assert(dl->size == 4);
//		assert(((double* )dl->elements)[0] == d);
//		assert(((double* )dl->elements)[1] == d);
//		assert(((double* )dl->elements)[2] == d);
//		assert(((double* )dl->elements)[3] == d2);

		free_list(dl);
	}

	{
		list_t *il = make_int_list(8);
		assert(il->size == 0);
		assert(il->elemsize == sizeof(int));

		int i1 = 42;
		append(il, &i1);
		assert(il->size == 1);
		assert(((int* )il->elements)[0] == i1);

		int i2 = 23;
		append(il, &i2);
		assert(il->size == 2);
		assert(((int* )il->elements)[0] == i1);
		assert(((int* )il->elements)[1] == i2);

		list_t *il2 = make_int_list(8);
		append(il2, &i2);
		append(il2, &i1);
		assert(il->size == 2);
		assert(((int* )il2->elements)[0] == i2);
		assert(((int* )il2->elements)[1] == i1);

		assert(append_list(il2, il));

		assert(il2->size == 4);
		assert(((int* )il2->elements)[0] == i2);
		assert(((int* )il2->elements)[1] == i1);
		assert(((int* )il2->elements)[2] == i1);
		assert(((int* )il2->elements)[3] == i2);

		free_list(il);
		free_list(il2);
	}
}
