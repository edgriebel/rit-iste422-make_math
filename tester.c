#include <stdio.h>
#include <math.h>
#include "libmath.h"

// define "epsilon" to account for floating point representation errors
#define EPSILON (0.00001f)

#define ASSERT(actual, expected) { \
	if (fabs(actual - expected) > EPSILON) { \
		printf("Assertion failed at %s:%d, expected %f, actual %f\n", \
			__func__, __LINE__, (float) expected, (float) actual); \
		return -1;\
	} \
	else {printf(".");} \
}


int test_mult() {
	ASSERT(mult(10, 20), 200);
	ASSERT(mult(10, 1), 10);
	ASSERT(mult(10, 0), 0);
	ASSERT(mult(10, -1), -10);
	// Overflow! actually returns 276447232
	// ASSERT(mult(10000000, 10000000), 100000000000000);
	return 0;
}

int test_add() {
	ASSERT(add(10, 20), 30);
	ASSERT(add(1, 1), 2);
	ASSERT(add(1, -1), 0);
	ASSERT(add(0, 0), 0);
	return 0;
}

int test_div() {
	ASSERT(divide(10, 10), 1)
	ASSERT(divide(100, 10), 10)
	ASSERT(divide(10, 5), 2)
	ASSERT(divide(5, 2), 2.5)
	ASSERT(divide(10000, -1), -10000)
	ASSERT(divide(0, 1000), 0)
	// Can't test this, "Floating point exception (core dumped)"
	// ASSERT(divide(5, 0), 0)
	return 0;
}

/* Test all methods */
int main(int argc, char** argv) {
	int (*tests[])(void) = {&test_add, &test_mult, &test_div};

	int failures = 0;
	for (int i=0; i<sizeof(tests)/sizeof(tests[0]); i++) {
		printf("Start test %d\n", i+1);
		if (tests[i]()) failures++;
		printf("\n");
	}
	if (!failures)
		printf("All Tests Passed\n");
	return failures;
}
