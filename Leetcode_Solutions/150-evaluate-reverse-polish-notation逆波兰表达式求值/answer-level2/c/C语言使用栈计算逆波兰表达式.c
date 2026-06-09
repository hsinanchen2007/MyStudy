```c
int evalRPN(char ** tokens, int tokensSize){
    int stack[tokensSize];
    int top = -1;
    int a, b;
    for (int i = 0; i < tokensSize; ++i) {
        if (strcmp(tokens[i], "+") == 0) {
            a = stack[top--];
            b = stack[top--];
            stack[++top] = b + a;
        }
        else if (strcmp(tokens[i], "-") == 0) {
            a = stack[top--];
            b = stack[top--];
            stack[++top] = b - a;
        }
        else if (strcmp(tokens[i], "*") == 0) {
            a = stack[top--];
            b = stack[top--];
            stack[++top] = b * a;            
        }
        else if (strcmp(tokens[i], "/") == 0) {
            a = stack[top--];
            b = stack[top--];
            stack[++top] = b / a;            
        }
        else {
            stack[++top] = atoi(tokens[i]);
        }
    }
    return stack[top];
}
```
