#include "hash.h"
#include <stdio.h>

int
main()
{
	hash_t *hash = create_hash();

	hash_insert(1, 10, hash);
	hash_insert(2, 20, hash);
	hash_insert(3, 30, hash);
	hash_insert(4, 40, hash);
	hash_insert(100 + 4, 100 + 40, hash);	//	HASH_SIZE = 100

	hash_find(3, hash);
	hash_find(1, hash);
	hash_modify(4, 400, hash);
	hash_modify(2, 200, hash);
	display(hash);
	destroy_hash(hash);
	return 0;
}
