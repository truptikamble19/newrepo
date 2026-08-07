#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;
    char ch;
    int op1, op2, result;

    while ((ch = exp[i]) != '\0') {

        if (isdigit(ch)) {
            push(ch - '0');   // Convert character to integer
        } else {
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                default:
                    printf("Invalid Operator\n");
                    return -1;
            }

            push(result);
        }
        i++;
    }

    return pop();
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}