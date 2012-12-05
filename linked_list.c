#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node {
  struct node *next;
  int val;
};

struct node *head = NULL;
struct node *curr = NULL;

struct node* create_list(int val)
{
  struct node *new = malloc(sizeof(struct node));

  if(NULL == new) {
    printf("List creation failed\n");
    return NULL;
  }

  new->val = val;
  new->next = NULL;
  head = new;
  curr = new;
}

void add(int val)
{
  printf("Adding [%d] to the list\n", val);

  if(head == NULL) {
    create_list(val);
  } else {
    struct node *new = malloc(sizeof(struct node));

    if(NULL == new) {
      printf("Adding node failed\n");
      return;
    }

    new->val = val;
    new->next = NULL;

    curr->next = new;
    curr = new;
  }
}

int delete(int val)
{ 
  printf("Deleting [%d] from the list\n", val);

  struct node *prev = head;
  struct node *ptr = head;
  struct node *del = NULL;

  while(ptr != NULL) {
    if(ptr->val == val) {
      if(ptr == head) {
        head = ptr->next;
      }

      del = ptr;
      prev->next = ptr->next;
    } else {
      prev = ptr;
    }

    ptr = ptr->next;
    free(del);
    del = NULL;
  }
}

void print_list()
{
  printf("\n----- Printing List-----");

  struct node *ptr = head;

  if(ptr == NULL) {
    printf("\nList is empty");
    printf("\n----- End Printing List --\n\n");
    return;
  }

  while(ptr != NULL) {
    printf("\n");
    printf("[%d]", ptr->val);
    ptr = ptr->next;
  }

  printf("\n----- End Printing List --\n\n");
}
