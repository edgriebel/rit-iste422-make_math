#include "libmath.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if (argc < 4) {
    printf("Usage: %s <number> <operation> <number>\n", argv[0]);
    return 1;
  }
  float n1 = atof(argv[1]);
  float n2 = atof(argv[3]);
  char op = argv[2][0];

  float (*func)(float, float) = 0;
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
	
  float result = func(n1, n2);
  printf("%-8.4f %s %-8.4f = %-8.4f\n", n1, argv[2], n2, result);
  return 0;
}
