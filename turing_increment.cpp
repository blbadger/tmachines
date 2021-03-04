//c++ turing_increment.cpp
/* 
 * A program to emulate a Turing machine that increments an
 * integer by one. 
 * 
 * */

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

vector<int> turing_incrementor(vector<vector<string>> program, int state, int position, vector<int> input, int counter){
	
	// initialize the result tape as a copy of the input tape
	vector<int> result;
	for (auto u: input) result.push_back(u);
	
	while (true) {
		int square = result[position];
		string step;
		
		if (square == 1) {
			step = program[state-1][1];
		}
		else step = program[state-1][0];
		
		int index = 0;
		if (step[0] == 'E' or step[0] == 'P'){
			index = 1;
			if (step[0] == 'P') {
				result[position] = 1;
			}
			else result[position] = 0;
		}

		if (step[index] == 'R') position += 1;
		else if (step[index] == 'L') position -= 1;
		
		state = 0;
		string num_string = "";

		index++;
		while (index < step.size()) {
			num_string.push_back(step[index]);
			index++;
		}
		state = stoi(num_string);
		counter++;
		if (step[step.size()-2] == 'C' and step[step.size()-1] == '0') {
			return result;
		}
	}

}
	
int main(){
	//initialize program for incrementing integers
	vector<vector<string>> program { {"C0", "R2"}, {"R3", "R9"}, 
		{"PL4", "R3"}, {"L5", "L4"}, {"L5", "L6"}, {"R2", "R7"}, 
		{"R8", "ER7"}, {"R8", "R3"}, {"PR9", "L10"}, {"C0", "ER11"}, 
		{"PC0", "R11"} };
	
	//initialize input tape
	vector<int> input;
	
	//specifiy input number 
	int initial_number = 10000;
	for (int i=0; i<2*initial_number + 10; i++) input.push_back(0);
	for (int j=3; j<initial_number+3; j++) input[j] = 1;
	cout << "Input:   ";
	for (auto u:input) cout << u;
	//state initialization
	int state = 1;
	
	//counter initialization
	int counter = 0;
	
	int position = 3 + initial_number-1;
	vector<int> result;
	
	result = turing_incrementor(program, state, position, input, counter);
	cout << endl;
	cout << "Output:  ";
	for (auto u:result) cout << u;
	return 0;
}
