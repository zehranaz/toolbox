#include <stdio.h>

typedef struct node {
  char l;
  struct node* next;
  struct node* left;
  struct node* right;
} node;

void print_node(node* head) {
  printf("%c: ", head->l);

  if (head->left != NULL)
    printf("L-> %c ", head->left->l);
  else 
    printf("L-> NULL ");

  if (head->right != NULL)
    printf("R-> %c ", head->right->l);
  else 
    printf("R-> NULL ");

  if (head->next != NULL)
    printf("N-> %c\n", head->next->l);
  else
    printf("N-> NULL\n");
}

typedef struct queue {
  node* head;
  node* tail;
} queue;

void enqueue(queue* q, node* new_node)
{
  if (new_node == NULL)
    return;

  if (q->head == NULL)
    q->head = new_node;
  else
    q->tail->next = new_node;

  q->tail = new_node;
}

node* dequeue(queue* q)
{
  node* result = q->head;
  
  // No elements
  if (result == NULL)
    return NULL;

  // One element
  if (result == q->tail || q->tail == NULL)
    q->head = NULL;

  // Two elements
  if (result == q->tail)
    q->tail = NULL;

  // Normal case
  q->head = result->next;
  result->next = NULL;

  return result;
}

void print_connections(node* parent)
{
  print_node(parent); 
  if (parent->right != NULL)
    print_connections(parent->right); 
  if (parent->left != NULL) 
    print_connections(parent->left);
}