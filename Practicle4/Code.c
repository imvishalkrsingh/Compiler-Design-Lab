#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int main() {
    char input[50];
    int i = 0;
    char x;

    printf("Grammar:\n");
    printf("E  -> T E'\n");
    printf("E' -> + T E' | ε\n");
    printf("T  -> i\n\n");

    printf("Enter input string (end with $): ");
    scanf("%s", input);

    push('$');
    push('E');

    printf("\nStack\tInput\tAction\n");

    while (top >= 0) {
        x = stack[top];

        printf("%s\t%s\t", stack, &input[i]);

        if (x == input[i]) {
            pop();
            i++;
            printf("Match %c\n", x);
        }
        else if (x == 'E') {
            pop();
            push('E');
            push('T');
            printf("E -> T E'\n");
        }
        else if (x == 'T' && input[i] == 'i') {
            pop();
            push('i');
            printf("T -> i\n");
        }
        else if (x == 'E' && input[i] == '+') {
            pop();
            push('E');
            push('T');
            push('+');
            printf("E' -> + T E'\n");
        }
        else if (x == 'E' && input[i] == '$') {
            pop();
            printf("E' -> ε\n");
        }
        else {
            printf("Error\n");
            return 0;
        }
    }

    if (input[i] == '$')
        printf("\nString Accepted!\n");
    else
        printf("\nString Rejected!\n");

    return 0;
}