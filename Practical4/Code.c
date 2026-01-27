/*
------------------------------------------------------------
Practical No. 4
Aim:
To implement Predictive Parsing (LL(1)) in C.
------------------------------------------------------------

Grammar Used:
E  → T E'
E' → + T E' | ε
T  → i

Where:
i  → identifier
+  → operator
$  → end of input symbol
ε  → empty (epsilon)

------------------------------------------------------------

Concept:
Predictive parsing is a top-down parsing technique.
It uses:
- A stack
- An input buffer
- Grammar rules
- One lookahead symbol (LL(1))

The parser predicts which production to apply
without backtracking.

------------------------------------------------------------

Sample Input:
i+i$

Expected Output:
String Accepted!

------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

/* push into stack */
void push(char c) {
    stack[++top] = c;
}

/* pop from stack */
void pop() {
    top--;
}

int main() {
    char input[50];
    int i = 0;
    char x;
    int k;

    printf("Grammar:\n");
    printf("E -> T R\n");
    printf("R -> + T R | e\n");
    printf("T -> i\n\n");

    printf("Enter input string (end with $): ");
    scanf("%s", input);

    /* initialize stack */
    push('$');
    push('E');

    printf("\nStack\tInput\tAction\n");

    while (top >= 0) {
        x = stack[top];

        /* print stack */
        for (k = 0; k <= top; k++)
            printf("%c", stack[k]);

        printf("\t%s\t", &input[i]);

        /* terminal match */
        if (x == input[i]) {
            pop();
            i++;
            printf("Match %c\n", x);
        }

        /* E -> T R */
        else if (x == 'E') {
            pop();
            push('R');
            push('T');
            printf("E -> T R\n");
        }

        /* T -> i */
        else if (x == 'T' && input[i] == 'i') {
            pop();
            push('i');
            printf("T -> i\n");
        }

        /* R -> + T R */
        else if (x == 'R' && input[i] == '+') {
            pop();
            push('R');
            push('T');
            push('+');
            printf("R -> + T R\n");
        }

        /* R -> e */
        else if (x == 'R' && input[i] == '$') {
            pop();
            printf("R -> e\n");
        }

        else {
            printf("Error\n");
            return 0;
        }
    }

    if (top == -1 && input[i] == '\0')
    printf("\nString Accepted\n");
else
    printf("\nString Rejected\n");


    return 0;
}
