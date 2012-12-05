#include <stdio.h>
#include "linked_list.h"

int main(int argc, char** argv)
{
  print_list();
  add(9);
  print_list();
  add(1);
  add(2);
  add(3);
  add(5);
  add(6);
  print_list();
  delete(5);
  print_list();
}