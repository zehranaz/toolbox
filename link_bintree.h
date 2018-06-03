#include "queue.h"

node* advance_head(queue* q)
{
  node* head = q->head;
  if (head == q->tail)
    q->tail = NULL;
  q->head = q->head->next;
  return head;
}

node* advance_to_end(queue* q)
{
  node* head = q->head;
  q->head = NULL;
  q->tail = NULL;
  return head;
}

void link_bin_tree(node* tree_head)
{
  queue q;
  q.head = NULL;
  q.tail = NULL;
  node* head = tree_head;
  while (head != NULL)
  {
    do {
      enqueue(&q, head->left);
      enqueue(&q, head->right);
      head = head->next;
    }
    while (head != NULL);
    head = advance_to_end(&q);
  }
}