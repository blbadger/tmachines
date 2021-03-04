#! python3
# turing_incrementor.py


import numpy as np
from matplotlib import pyplot as plt


def turing_incrementor(inp, program, state, position, counter):
	result = [i for i in inp] # copy input so as not to modify it 
	while True:
		square = result[position]
		if square == 1:
			step = program[state-1][1]
		else:
			step = program[state-1][0]

		i = 0
		if step[0] in ['E', 'P']:
			i = 1
			if step[0] == 'P':
				result[position] = 1
			else:
				result[position] = 0

		if step[i] == 'R':
			position += 1

		elif step[i] == 'L':
			position -= 1
			
		state = int(step[i+1:])
		counter += 1
		if [step[-2], step[-1]] == ['C', '0']:
			break

	return result, counter


program = [
['C0', 'R2'], 
['R3', 'R9'], 
['PL4', 'R3'], 
['L5', 'L4'], 
['L5', 'L6'], 
['R2', 'R7'], 
['R8', 'ER7'],
['R8', 'R3'], 
['PR9', 'L10'], 
['C0', 'ER11'], 
['PC0', 'R11']]

inp = [0,0,0,0,0,0,0]
counter = 0
state = 1
position = 3

# calculate the number of steps to increment input number in_x

in_x = 100

for i in range(2*in_x+10):
	inp.append(0)

for i in range(3, in_x+3):
	inp[i] = 1

while inp[position] == 1:
	position += 1
position -= 1

print (turing_incrementor(inp, program, state, position, counter)[1])


# to find O(n) of this turing machine
inp = [0,0,0,0,0,0,0,0]
x_ls = []
y_ls = []
for i in range(0, 100):
	counter = 0
	state = 1
	inp = [0] + inp
	inp.append(0)
	inp[3] = 1
	position = 3 + i
	x_ls.append(i)
	y_ls.append(turing_incrementor(inp, program, state, position, counter)[1])

print (turing_incrementor(inp, program, state, position, counter))

fig, ax = plt.subplots()
ax.plot(x_ls, y_ls, alpha=0.5)
plt.show()

