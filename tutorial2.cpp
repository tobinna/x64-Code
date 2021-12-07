
#include "pch.h"
#include <iostream>
#include "sample.h"
#include <algorithm> // for using std::min and std::min_element
#include <stdlib.h> // For rand()
#include <time.h>	// For time()
#pragma warning(disable : 4996)


void check(const char* s, _int64 v, _int64 expected) {
	std::cout << s << " = " << v;
	if (v == expected) {
		std::cout << " OK";
	}
	else {
		std::cout << " ERROR: should be " << expected;
	}
	std::cout << "\n";
}

int main() {
	// Sum of array through assembly



	//std::cout<< gcd_recursion(35, 49) << "\n";
	check("gcd_recursion(35,49)", gcd_recursion(35, 49), 7);
	check("gcd_recursion(48,36)", gcd_recursion(48, 36), 12);
	check("gcd_recursion(104,96)", gcd_recursion(104, 96), 8);
	check("gcd_recursion(1044,2922)", gcd_recursion(1044, 2922), 6);

	//_int64 inp_int = 7;


	_int64 sum_scanf;
	_int64 sum_check;
	/* First check of use_scanf */
	const _int64 array_size1 = 5;
	_int64 array1[array_size1] = { 1,2,3,4,5 };
	sum_scanf = use_scanf(array_size1, array1);
	_int64 *min1 = std::max_element(std::begin(array1), std::end(array1));
	sum_check = *min1 + inp_int;
	check("use_scanf(array1)", sum_scanf, sum_check);
	std::cout << "\n";

	/* Second check of use_scanf */
	const _int64 array_size2 = 10;
	_int64 array2[array_size2] = { 3,4,2,3,4,2,0,10,39,-49 };
	sum_scanf = use_scanf(array_size2, array2);
	_int64* min2 = std::max_element(std::begin(array2), std::end(array2));
	sum_check = *min2 +inp_int;
	check("use_scanf(array2)", sum_scanf, sum_check);
	std::cout << "\n";
	/* Third check of use_scanf */
	const _int64 array_size3 = 100;
	_int64 array3[array_size3];
	srand(time(0));
	for (int i = 0; i < array_size3; ++i) {
		array3[i] = (long long)rand() % 1000;
	}
	sum_scanf = use_scanf(array_size3, array3);
	_int64* min3 = std::max_element(std::begin(array3), std::end(array3));
	sum_check = *min3 + inp_int;
	check("use_scanf(array3)", sum_scanf, sum_check);
	std::cout << "\n\n";


	std::cout << "Global variable (inp_int): " << inp_int << "\n";
	check("min5(1, 2, 3, 4)", min5(1, 2, 3, 4), std::min(std::min(std::min(std::min(inp_int, (long long)1), (long long)2), (long long)3), (long long)4));
	check("min5(3, 1, 2, 5)", min5(3, 1, 2, 5), std::min(std::min(std::min(std::min(inp_int, (long long)3), (long long)1), (long long)2), (long long)5));
	check("min5(2, 3, 1, -5)", min5(2, 3, 1, -5), std::min(std::min(std::min(std::min(inp_int, (long long)2), (long long)3), (long long)1), (long long)-5));
	check("min5(-1, -2, -3, -4)", min5(-1, -2, -3, -4), std::min(std::min(std::min(std::min(inp_int, (long long)-1), (long long)-2), (long long)-3), (long long)-4));
	check("min5(-3, -1, -2, 0)", min5(-3, -1, -2, 0), std::min(std::min(std::min(std::min(inp_int, (long long)-3), (long long)-1), (long long)-2), (long long)0));
	check("min5(-2, -3, -1, 3)", min5(-2, -3, -1, 3), std::min(std::min(std::min(std::min(inp_int, (long long)-2), (long long)-3), (long long)-1), (long long)3));
	check("min5(-1, 2, 3, 4)", min5(-1, 2, 3, 4), std::min(std::min(std::min(std::min(inp_int, (long long)-1), (long long)2), (long long)3), (long long)4));
	check("min5(3, -1, 2, 6)", min5(3, -1, 2, 6), std::min(std::min(std::min(std::min(inp_int, (long long)3), (long long)-1), (long long)2), (long long)6));
	check("min5(2, 3, -1, -5)", min5(2, 3, -1, -5), std::min(std::min(std::min(std::min(inp_int, (long long)2), (long long)3), (long long)-1), (long long)-5));




	std::cout << "\n";

	// Code to clear the newline from the buffer and having to wait before exiting
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
	if (c == EOF) {
		// input stream ended, do something about it, exit perhaps
	}
	else {
		printf("Type Enter to continue\n");
		getchar();
	}
	return 0;
}