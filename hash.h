#ifndef __DATA_HASH_H_
#define __DATA_HASH_H_

#include "link.h"

typedef struct hash_s hash_t;
typedef struct hash_link_s hash_link_t;

struct hash_s {
	void **hash;
};

struct hash_link_s {
	unsigned int key;
	db_link_t *link;
};

hash_t *create_hash();
void hash_insert(int key, int value, hash_t *p);
void hash_modify(int key, int value, hash_t *p);
void *hash_find(int key, hash_t *p);
void destroy_hash(hash_t *p);
void display(hash_t *p);

#endif // _HASH_H_
