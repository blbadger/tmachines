// ackerman.cpp
#include <iostream>

int ackerman(int m, int n) {
	if (m == 0) return n+1;

	else if (n == 0) return ackerman(m-1, 1);
	
	else return ackerman(m-1, ackerman(m, n-1));
	
}

int main() {
	int m = 4;
	int n = 1;
	std::cout << ackerman(m, n);
	return 0;
}
