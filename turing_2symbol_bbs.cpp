//c++ turing_2_2bb.cpp
/* 
 * A program to emulate a Turing machine with the maximum
 * number of steps until a halt with two states and two 
 * symbols
 * 
 * */

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

vector<int> turing_incrementor(vector<vector<string>> program, int state, int position, vector<int> input, int& counter){
	
	// initialize the result tape as a copy of the input tape
	vector<int> result;
	for (auto u: input) result.push_back(u);
	
	while (true) {
		counter++;
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
		if (step[step.size()-1] == 'H'){
			return result;
		}
		state = stoi(num_string);
		
		if (step[step.size()-2] == 'C' and step[step.size()-1] == '0') {
			return result;
		}
		
	}

}

//Turing machines translated from
// http://www.logique.jussieu.fr/~michel/ha.html#tm52
	
//  1RB 	1LB 	1LA 	1RH 	
// two states, two symbols, 6 steps
//{
		//{"PR2", "PL2"},
		//{"PL1", "PRH"}
		//};
		
// 1RB 	1RH 	1LB 	0RC 	1LC 	1LA  
// three states, two symbol, 21 steps
//{ 
		//{"PR2", "PRH"}, 
		//{"PL2", "ER3"},
		//{"PL3", "PL1"} 
		//};
		
// 1RB 	1LB 	1LA 	0LC 	1RH 	1LD 	1RD 	0RA
// four states, two symbols, 107 steps
//{ 
		//{"PR2", "PL2"}, 
		//{"PL1", "EL3"},
		//{"PRH", "PL4"},
		//{"PR4" ,"ER1"}
		//};
		
//1RB 	1LC 	1RC 	1RB 	1RD 	0LE 	1LA 	1LD 	1RH 	0LA
// five states, two symbols, 47176870 steps
//{ 
		//{"PR2", "PL3"}, 
		//{"PR3", "PR2"},
		//{"PR4", "EL5"},
		//{"PL1" ,"PL4"},
		//{"PRH", "EL1"}
		//};
		

int main(){
	//initialize program for incrementing integers
	vector<vector<string>> program { 
		{"PR2", "PL3"}, 
		{"PR3", "PR2"},
		{"PR4", "EL5"},
		{"PL1" ,"PL4"},
		{"PRH", "EL1"}
		};
		
	//initialize input tape
	vector<int> input;
	
	//specifiy input number 
	int initial_number = 20000;
	for (int i=0; i<2*initial_number + 10; i++) input.push_back(0);
	//cout << "Input:   ";
	//for (auto u:input) cout << u;
	//state initialization
	int state = 1;
	
	//counter initialization
	int counter = 0;
	
	int position = 20000;
	vector<int> result;
	
	result = turing_incrementor(program, state, position, input, counter);
	cout << endl;
	cout << "Steps: " << counter;
	cout << endl;
	//cout << "Output:  ";
	//for (auto u:result) cout << u;
	return 0;
}

