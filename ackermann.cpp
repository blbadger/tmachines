// ackermanb.cpp
// computes the value of the Ackermann
// function

#include <iostream>

int ackermann(int m, int n) {
	if (m == 0) return n+1;

	else if (n == 0) return ackermann(m-1, 1);
	
	else return ackermann(m-1, ackermann(m-1, n-1));
	
}

int main() {
	int m = 4;
	int n = 1;
	std::cout << ackermann(m, n);
	return 0;
}
