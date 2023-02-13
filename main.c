#include "libmath.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if (argc < 4) {
    printf("Usage: %s <number> <operation> <number>\n", argv[0]);
    return 1;
  }
  int n1 = atoi(argv[1]);
  int n2 = atoi(argv[3]);
  char op = argv[2][0];

  int (*func)(int, int) = 0;
  switch (op) {
  case '*':
  case 'x': 
	func = &mult;
	break;
  case '/': 
	func = &divide;
	break;
  case '+':
	func = &add;
	break;
  case '-':
	func = &sub;
	break;
  default:
	printf("ERROR: Unrecognized operator %c\n", op);
	return -1;
  }
	
  int result = func(n1, n2);
  printf("%d %s %d = %d\n", n1, argv[2], n2, result);
  return 0;
}