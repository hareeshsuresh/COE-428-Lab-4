The program runs as intended. I assumed the user input would be
correct as it was not specified in lab manual. An issue I got
was a compilation error due to the GCC compilier not allowing
for loop variable initilization in the loop. For example
for (int i=0;i<length;i++) does not work on GCC whereas
int i; for(i=0;i<length;i++) does work. This was the main error
I encountered. 

***** The correct way to input is the same way as the lab manual
space and case sensitive.*****
	  EX. change input:c 1 D
	  EX. delete input:d A		or  :d
	  EX. switch state:0            or  :1
	  EX. print state:p


State diagram is attached as a pdf file in the lab 4 file. 
The starting state is A
and the state is described as
A F C
B H D
C B F
D A D
E C H
F E G
G D E
H G B

