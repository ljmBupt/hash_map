#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define HASH_SIZE 100

static unsigned int Hash(int key);
static void *init_hash_item();

void *init_hash_item()
{
	hash_link_t *p = malloc(sizeof(struct hash_link_s));
	assert(NULL != p);
	p->link = create_link();
	p->key = -1;
	return p;
}

unsigned int Hash(int key)
{
	return key % HASH_SIZE;
}

hash_t *create_hash()
{
	int i;
	hash_t *new = malloc(sizeof(struct hash_s));
	assert(NULL != new);
	new->hash = malloc(sizeof(void *) * HASH_SIZE);
	assert(NULL != new->hash);

	for (i = 0; i < HASH_SIZE; ++i) {
		new->hash[i] = init_hash_item();
	}

	return new;
}

void hash_insert(int key, int value, hash_t *p)
{
	unsigned int k = Hash(key);
	hash_link_t *t = p->hash[k];
	insert_item(key, value, t->link);
}

void hash_modify(int key, int value, hash_t *p)
{
	unsigned int k = Hash(key);
	hash_link_t *t = p->hash[k];
	modify_item(key, value, t->link);
}

void *hash_find(int key, hash_t *p)
{
	unsigned int k = Hash(key);
	hash_link_t *t = p->hash[k];
	return find_item(key, t->link);
}

void destroy_hash(hash_t *p)
{
	int i;
	for (i = 0; i < HASH_SIZE; ++i) {
		hash_link_t *tmp = p->hash[i];
		db_link_t *link = tmp->link;
		destroy_link(link);
		free(tmp);
		tmp = NULL;
	}
	free(p->hash);
	free(p);
}

void display(hash_t *p)
{
	int i;
	for (i = 0; i < HASH_SIZE; ++i) {
		hash_link_t *tmp = p->hash[i];
		db_link_t *link = tmp->link;
		link_t *cur = link->tail;
		while (NULL != cur) {
			printf("(key = %d, value = %d)\n", *(int *)cur->key, *(int *)cur->data);
			cur = cur->prev;
		}
	}
}
