#include <queue.h>

void test_linked_queue(void) {
  printf("Creating tree: \n");
  
  node a, b, c, d, e, f, g, h;
  a.l = 'a';
  b.l = 'b';
  c.l = 'c';
  d.l = 'd';
  e.l = 'e';
  f.l = 'f';
  g.l = 'g';
  h.l = 'h';
  
  a.left = &b;
  a.right = &c;
  a.next = NULL;

  b.left = &d;
  b.right = NULL;
  b.next = NULL;

  c.left = &e;
  c.right = &f;
  c.next = NULL;

  d.left = &g;
  d.right = NULL;
  d.next = NULL;

  e.right = &h;
  e.left = NULL;
  e.next = NULL;

  f.right = NULL;
  f.left = NULL;
  f.next = NULL;

  g.right = NULL;
  g.left = NULL;
  g.next = NULL;

  h.right = NULL;
  h.left = NULL;
  h.next = NULL; 

  print_connections(&a);

  printf("\nConnecting next pointers: \n");
  link_bin_tree(&a);

  print_connections(&a);

}