
/*

This program is written as a solution of Gokturk Ucoluk's homework, 
titled as "NONSENSE STACK MACHINE" in his book "C Homework Collection, 2009". 
Created by Erkin Yildirim.

*/

#include <stdio.h>
#include <stdlib.h>

long int counter = 0;

long int *temp_stack = NULL; //the *temp_stack and

long int *stack = NULL; // the *stack variables are declared and defined as NULL for hinder them become dangling pointers. *temp_stack shall hold the block of memory, allocated by realloc function. if it is not NULL, it may safely be assigned to *stack.

void push(int pushed); //the push(i) operation accepts i as an item and adds it to the top of the stack.

long int pop(); //operation pop() removes the top element and returns it.

long int empty(); // operation empty() checks if stack is empty or not, if stack is empty, empty() returns 1. if stack is not empty, empty() returns 0.

void stacktop(); // stacktop reads the item on the top of the stack and prints the value of item. no returns shall take place.

int main() {
	
	long int input; // input variable holds the input that have come from user. 
	
	scanf("%ld", &input); // scanf reads a integer from standard input (stdin) and assigns it to the variable input.
	
	while(input != EOF){ // this conditional loop checks if the read data is EOF or not. EOF may change by implementation.
		push(input); // if the condition is met, the read data from user (variable input) is pushed to the stack.
		scanf("%ld", &input); // program expects another value to be entered by user.
	}
	
	stacktop(); // if user enters EOF, the while loop, which is above, ends. stacktop() operation prints the top of the stack.
	
	return 0;
}

void push(int pushed){ // push(i) operation accepts an item, i. push(i) operation does either push the item, i, or change it to a different value and push it to the top of the stack.
	
	long int loop1, loop2, is_prime, sum, popped1, popped2; // loop1 and loop2 are loop variables. is_prime becomes 0 if the item i is not a prime number, and becomes 1 if the item is a prime number.
	
	is_prime = 1; // is_prime variable gets set 1 by default, it will get changed by loop2 and a conditional statement, if item i is not a prime number. 
	
	for(loop1=1; loop1<pushed; loop1++){ // this loop1 loop controls if item i is a square number.
		
		if((loop1*loop1)==pushed){ // if item i is a square number:
			
			pushed=loop1; // ...its square root is replaced with itself.
			temp_stack = realloc(stack, (counter+1)*sizeof(int)); // stack creating or expanding attempt. void *realloc(void *ptr, size_t size) function makes a new block of memory over, if *ptr = NULL and size > 0. it changes the block of memory, if *ptr != NULL and size > 0. at first call, realloc shall make over a new memory block, and other calls, realloc will expand or reduce the memory block.
			if(temp_stack!=NULL){ // if the memory block (stack) has successfully be allocated by realloc,
				stack = temp_stack; // the program can safely assign the address of block of memory, being held by temp_stack, to stack.
				push(pushed); // as indicated in homework sheet, if item i is a square number, its square root is replaced with itself and the push operation shall be called with this value (value as item i).
				return;
			}
			else{
				return;
			}
			
			
			
		}
	}
	
	
	for(loop2=2; loop2<pushed; loop2++){ //this loop2 loop controls if item i (variable pushed) is a prime number or not.
		if((pushed%loop2)==0){ // if pushed variable is divided by any numbers held by loop2 variable before loop2 variable is equal to push:
			is_prime = 0; //...item i (variable pushed) is no longer a prime number.
			
			temp_stack = realloc(stack, (counter+1)*sizeof(int));
			
			if(temp_stack!=NULL){ // if reallocation above succeeded:
				stack = temp_stack; // ...stack variable may safely hold the address of block of memory.
				*(stack+counter) = pushed; // value held by pushed variable gets written onto top of the stack.
				counter++; //counter increments by 1 as it shall point to the top of the stack.
				return;
			}
			else{
				return;
			}
			
			
		}
	}
	
	if(pushed == 1){ // a special condition to check if item i is 1. as every number, including prime numbers, can get divided by 1, this case needs an exceptional condition.
		is_prime = 0; // 1 is not a prime number.
		
		temp_stack = realloc(stack, (counter+1)*sizeof(int));
			
			if(temp_stack!=NULL){ // if the reallocation above succeeded:
				stack = temp_stack; // ...stack variable may safely hold the address of block of memory.
				*(stack+counter) = pushed; // value held by pushed variable gets written onto top of the stack.
				counter++; // counter increments by 1 as it shall point to the top of the stack.
				return;
			}
			else{
				return;
			}
	}
	
	
	
	if(is_prime){ //this conditional statement checks if item i (variable pushed) is a prime number.
		
		temp_stack = realloc(stack, (counter+1)*sizeof(int));
			
			if(temp_stack!=NULL){ // if the reallocation above succeeded:
				stack = temp_stack; // ...stack variable may safely hold the address of block of memory.
				*(stack+counter) = pushed; // value held by pushed variable gets written onto top of the stack.
			}
			else{
				return;
			}
		
	}
	
	/*above and bottom conditional statements both work or neither of them work.*/
	
	if(is_prime){ //this conditional statement checks if item i (variable pushed) is a prime number.
		if((pushed%3)==1){ //if item i (variable pushed) is 1 after modulo 3 is applied:
			
			if(counter>=2){ //this conditional statement checks if there are more than 3 items in stack. if so:
				pop(); //the prime number which is on the top of the stack is popped.
				
				sum = pop() * pop(); //two more items are popped from the top of the stack and their multiplications are assigned to the sum variable.
				counter++; // counter increments by 1 as it shall point to the top of the stack.
				push(sum); //as indicated in homework sheet, if item i is a prime number and is 1 after modulo 3 operation, push operation shall be called with sum value (value as item i).
				return;
			}
			else{
				return;
			}
			
		}
		
		else if((pushed%3)==2){ //if item i (variable pushed) is 2 after modulo 3 is applied:
			
			if(counter>=3){ //this conditional statement checks if there are more than 3 items in stack. if so:
				pop(); //the prime number which is on the top of the stack is popped.
				
				sum = pop() + pop(); //two more items are popped from the top of the stack and their sums are assigned to the sum variable.
				counter++; // counter increments by 1 as it shall point to the top of the stack.
				push(sum); //as indicated in homework sheet, if item i is a prime number and is 2 after modulo 3 operation, push operation shall be called with sum value (value as item i).
								
				return;
			}
			else{
				*(stack+counter) = pushed;
				counter++;
				return;
			}
			
		}
		
		else if((pushed%3)==0){ //if item i (variable pushed) is 0 after modulo 3 is applied:
			
			if(counter>=3){ //this conditional statement checks if there are more than 3 items in stack. if so:
				pop(); //the prime number which is on the top of the stack is popped.
				
				popped1 = pop(); //the item that is on the top of the stack is popped. its value gets assigned to popped1.
				
				popped2 = pop(); //the item that is on the top of the stack is popped. its value gets assigned to popped2.
				
				//the conditional statements below is to find the big number and subtract the small number from it as it has to hinder negative values, and assign the result to the sum variable:
				
				if(popped1>popped2){
					sum = popped1-popped2;
				}
				else if(popped2>popped1){
					sum = popped2-popped1;
				}
				else if(popped2==popped1){
					sum = 0;
				}
				counter++; // counter increments by 1 as it shall point to the top of the stack.
				push(sum); //as indicated in homework sheet, if item i is a prime number and is 0 after modulo 3 operation, push operation shall be called with sum value (value as item i).
				return;
			}
			else{
				return;
			}
			
		}
	}
	
}

long int pop(){ //pop() operation pops the item, which is on the top of the stack, change the stack size and returns the popped value:
	
	long int holder; // holder variable holds value of popped item.
	
	if(!empty()){ // this conditional statement checks if the stack is empty. if so, it shall print an "error" message as indicated in the homework sheet:
		holder = *(stack+counter); // value of the item, which is on the top of the stack, is assigned to the holder variable.
		
		temp_stack = realloc(stack, (counter+1)*sizeof(int));
		
		if(temp_stack!=NULL){ // if the reallocation above succeeded:
			stack = temp_stack; // ...stack variable may safely hold the address of block of memory.
			counter--; // counter decreases 1 as it shall point to the top of the stack.
			return holder; //pop() operation returns the value of holder variable.
		}
		else{
			printf("error");
		}
	}
	
}

long int empty(){ // this empty() operation checks if the stack is empty or not. if the stack is empty, it shall return 1, and 0 otherwise.
	
	if(stack==NULL){
		return 1;
	}
	else{
		return 0;
	}
	
}

void stacktop(){ // this stacktop() operation prints the item on the top of the stack.
	
	printf("%ld\n", *(stack+counter-1));
	
}
