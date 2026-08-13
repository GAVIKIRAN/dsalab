#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int priority(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' || ch == '^');
}
void infixToPostfix(char infix[])
{
    char postfix[MAX];
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();
        }
        else if (isOperator(ch))
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   priority(stack[top]) >= priority(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main()
{
    char infix[MAX];
    printf("Enter Infix Expression: ");
    fgets(infix, MAX, stdin);
    infixToPostfix(infix);
    return 0;
}