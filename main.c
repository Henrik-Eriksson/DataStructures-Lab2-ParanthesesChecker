#define MAX 10
#include "stdio.h"
#include "stdlib.h"

/*
PUSH FUNCTION
Adds a character to the stack
Parameter: 1. the stack, 2. top value reference, 3 char to be added to the stack
return value 1 if successful and -1 if the stack is full
*/
int push(char* stack, int* top, char c);

/*
This function removes the top element in the stack
Parameter: 1 The stack, 2 A reference to the top value
Returnvalue: 1 if successful, -1 if stack is full
*/

int pop(char* stack, int* top);

/*
Returns the latest that was added to the stack
Parameter: The stack, A reference to the top value
Returns
1 if succesful, -1 if if the stack is empty
*/
int peek(char* stack, int* top);

int main()
{
	char stack[MAX];
	int top = NULL;

	char input[100];
	printf("Enter an parentheses string: ");
	scanf("%s", input);

	char c;
	char topC = NULL;

	for (int i = 0; (c = input[i]) != '\0'; i++)
	{

		//If it's a opening bracket add it to the stack
		if (c == '(' || c == '[' || c == '{')
		{
			topC = peek(stack, &top);

			/*ADDITIONAL REQUIREMENTS*/
			if (topC != 0)
			{
				if (topC == '(' && (c == '[' || c == '{')) break;
				if (topC == '[' && c == '{') break;
			}
			/*----------------------*/

			if (!push(stack, &top, c)) return 1; //Stack overflow
		}

		//If it's a closing bracket check the stack if there's a matching opening bracket,
		//If there's a match remove the opening bracket from the stack & repeat
		else if (c == ')' || c == ']' || c == '}')
		{
			if ((topC = peek(stack, &top)) == 0) break; //If the stack is empty, A closing bracket was entered without a opening 

			if ((topC == '(' && c == ')') || (topC == '{' && c == '}') || (topC == '[' && c == ']'))
			{
				pop(stack, &top);
			}
		}
		else
		{
			puts("Invalid input");
			return 1;
		}
	}
	if (top == NULL && topC != NULL) puts("Balanced!"); //If the stack is empty and the stack had a opening parameter that was popped
	else puts("Not Balanced!");

}


int push(char* stack, int* top, char c)
{
	if (*top == MAX - 1) return -1;

	*top += 1;
	stack[*top] = c;
	return 1;
}

int pop(char* stack, int* top)
{
	if (*top == NULL) return -1;
	*top -= 1;
	return 1;
}

int peek(char* stack, int* top)
{
	if (*top == NULL) return -1;
	return stack[*top];
}
