// ackerman.cpp
#include <iostream>

int ackerman(int m, int n) {
	if (m == 0) return n+1;

	else if (n == 0) return ackerman(m-1, 1);
	
	else return ackerman(m-1, ackerman(n, m-1));
	
}

int main() {
	//std::cout << "1";
	int m = 1;
	int n = 3;
	std::cout << ackerman(m, n);
	return 0;
}
