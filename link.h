#ifndef __LINK_H_
#define __LINK_H_

typedef struct link_s link_t;
typedef struct db_link_s db_link_t;

struct link_s {
	void *key;
	void *data;
	link_t *prev;
	link_t *next;
};

struct db_link_s {
	link_t *head;
	link_t *tail;
};

db_link_t *create_link();
void insert_item(int key, int data, db_link_t *h);
void modify_item(int key, int data, db_link_t *h);
void *find_item(int key, db_link_t *h);
void destroy_link(db_link_t *h);

#endif // _LINK_H_
