```
#define EMPTY -1;
struct StackT {
    int size;
    int top;
    char* data;
};
typedef struct StackT* Stack;
Stack InitStack(int size)
{
    Stack stack = (Stack)malloc(sizeof(struct StackT));
    stack->size = size;
    stack->top = EMPTY;
    stack->data = (char*)malloc(size * sizeof(char));
    return stack;
}
void Push(Stack stack, char c)
{
    int top = ++stack->top;
    stack->data[top] = c;
}
char Pop(Stack stack)
{
    int top = stack->top--;
    return stack->data[top];
}
char Peek(Stack stack)
{
    return stack->data[stack->top];
}
bool IsEmpty(Stack stack)
{
    return stack->top == EMPTY;
}
bool CheckStack(Stack stack)
{
    if (IsEmpty(stack)) {
        return true;
    }
    int stars = 0;
    while (!IsEmpty(stack)) {
        char c = Pop(stack);
        if (c == '*') {
            stars++;
        } else {
            stars--;
        }
        if (stars < 0) {
            return false;
        }
    }
    return true;
}
bool checkValidString(char * s){
    int sLen = strlen(s);
    if (sLen == 0) {
        return true;
    }
    Stack stack = InitStack(sLen);
    int i = 0;
    int stars;
    while (i < sLen) {
        if (s[i] == '(' || s[i] == '*') {
            Push(stack, s[i]);
        } else {
            stars = 0;
            while (!IsEmpty(stack) && Peek(stack) != '(') {
                Pop(stack);
                stars++;
            }
            if (!IsEmpty(stack) && Peek(stack) == '(') {
                Pop(stack);
            } else if (IsEmpty(stack)) {
                if (stars > 0) {
                    stars--;
                } else {
                    return false;
                }
            }
            // Push stars back
            while (stars) {
                Push(stack, '*');
                stars--;
            }
        }
        i++;
    }
    return CheckStack(stack);
}
```
提供一个用一个栈的思路。其实星号和左括号用一个栈就可以了。
碰到右括号优先使用左括号匹配，不够情况下使用星号。
最后结束时弹栈，用星号做右括号匹配左括号。
