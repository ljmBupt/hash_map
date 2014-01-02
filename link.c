#include "link.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

db_link_t *create_link(void)
{
	db_link_t *new = malloc(sizeof(struct db_link_s));
	assert(NULL != new);
	
	new->head = NULL;
	new->tail = NULL;
	
	return new;
}

void insert_item(int key, int data, db_link_t *p)
{
	link_t *new = malloc(sizeof(struct link_s));
	assert(NULL != new);
	
	new->key = malloc(sizeof(int));
	assert(NULL != new->key);
	*(int *)(new->key) = key;

	new->data= malloc(sizeof(int));
	assert(NULL != new->data);
	*(int *)new->data = data;
	
	if (NULL == p->head) {
		p->head = new;
		p->tail = p->head;
		p->head->next = NULL;
		p->head->prev = NULL;
	} else {
		p->tail->next = new;
		new->prev = p->tail;
		new->next = NULL;
		p->tail = new;
	}
}

void * find_item(int key, db_link_t *h)
{
	link_t *p = h->head;
	
	while (NULL != p) {
		if (*(int *)(p->key) == key) {
			if (NULL == p->prev) {
				return p->data;
			}
			if (NULL == p->next) {
				h->tail = p->prev;
				h->tail->next = NULL;
				p->next = h->head;
				h->head->prev = p;
				h->head = p;
				h->head->prev = NULL;
				return p->data;
			}
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p->next = h->head;
			h->head->prev = p;
			h->head = p;
			h->head->prev = NULL;
			return p->data;
		}
		p = p->next;
	}
	return NULL;
}

void modify_item(int key, int data, db_link_t *h)
{
	link_t *p = h->head;

	while (NULL != p) {
		if (*(int *)p->key == key) {
			*(int *)p->data = data;
			if (NULL == p->prev) {
				return;
			}
			if (NULL == p->next) {
				h->tail = p->prev;
				h->tail->next = NULL;
				p->next = h->head;
				h->head->prev = p;
				h->head = p;
				h->head->prev = NULL;
				return;
			}
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p->next = h->head;
			h->head->prev = p;
			h->head = p;
			h->head->prev = NULL;
			return;
		}
		p = p->next;
	}
}

void destroy_link(db_link_t *h)
{
	link_t *p = h->head;

	while (NULL != p) {
		link_t *pCur = p;
		free(pCur->key);
		free(pCur->data);
		p = p->next;
		free(pCur);
	}
}
