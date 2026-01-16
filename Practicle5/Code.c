/*
-------------------------------------------------
Practical No. 5
Aim: To implement Recursive Descent Parsing in C
-------------------------------------------------

Grammar:
E  -> i E'
E' -> + i E' | ε

Valid Strings:
i$
i+i$
i+i+i$

-------------------------------------------------
*/

#include <stdio.h>

/* Input string */
char input[20];

/* Pointer to current input symbol */
int pos = 0;

/* Error flag */
int invalid = 0;

/* Function declarations */
void E();
void Eprime();

int main() {
    printf("Enter input string (end with $): ");
    scanf("%s", input);

    /* Start parsing from start symbol */
    E();

    /* Final check */
    if (input[pos] == '$' && invalid == 0)
        printf("Valid String\n");
    else
        printf("Invalid String\n");

    return 0;
}

/* Implements grammar rule: E -> i E' */
void E() {
    if (input[pos] == 'i') {
        pos++;          // consume 'i'
        Eprime();       // call E'
    } else {
        invalid = 1;    // invalid start
    }
}

/* Implements grammar rule: E' -> + i E' | ε */
void Eprime() {
    if (input[pos] == '+') {
        pos++;          // consume '+'

        if (input[pos] == 'i') {
            pos++;      // consume 'i'
            Eprime();   // recursive call
        } else {
            invalid = 1;  // '+' not followed by 'i'
        }
    }
    /* else epsilon (do nothing) */
}