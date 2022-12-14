#ifndef xor_list_H
#define xor_list_H

#include <stddef.h>

struct ListNode
{
    int m_data;
    struct ListNode* m_diff;
};

typedef struct ListNode ListNode;

typedef struct
{
    ListNode* m_head;
    ListNode* m_tail;
    size_t m_length;
} XORList;

void init_xor_list(XORList* xor_list);

XORList* get_new_xor_list(void);

void insert_at_head(XORList* xor_list, int data);

void insert_after_tail(XORList* xor_list, int data);

void insert_at(XORList* xor_list, size_t index, int data);

void print_xor_list(XORList* xor_list);

void delete_head(XORList* xor_list);

void delete_tail(XORList* xor_list);

void delete_at(XORList* xor_list, size_t index);

void clear_xor_list(XORList* xor_list);

#endif
