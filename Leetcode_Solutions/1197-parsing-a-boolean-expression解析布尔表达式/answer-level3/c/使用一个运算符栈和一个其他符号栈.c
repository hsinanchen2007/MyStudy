使用了一个栈用来专门存放'|' '&' '!', 另外一个栈存放其他。流程比较自然。好像用一个栈也可以解决。
```
#define EMPTY -1
struct StackT {
    int top;
    int capacity;
    char* data;
};
typedef struct StackT* Stack;
Stack InitStack(int capacity)
{
    Stack stack = (Stack)malloc(sizeof(struct StackT));
    if (stack == NULL) {
        printf("Alloc Stack Error\n");
    }
    stack->top = EMPTY;
    stack->capacity = capacity;
    stack->data = (char*)malloc(capacity * sizeof(char));
    if (stack->data == NULL) {
        printf("Alloc Stack Data Error");
    }
    return stack;
}
void PushStack(Stack stack, char c)
{
    if (stack->top == stack->capacity) {
        printf("Stack Full\n");
    }
    stack->top++;
    stack->data[stack->top] = c;
}
char PopStack(Stack stack)
{
    if (stack->top == EMPTY) {
        printf("Stack Empty\n");
    }
    return stack->data[stack->top--];
}
char PeekStack(Stack stack)
{
    return stack->data[stack->top];
}
void Negative(Stack numStack, int left)
{
    char c = PopStack(numStack);
    char leftSym = PopStack(numStack);
    if (leftSym != left) {
        printf("Error match %c with %c\n", leftSym, left);
    }
    if (c == 't') {
        PushStack(numStack, 'f');
    } else {
        PushStack(numStack, 't');
    }    
}
void And(Stack numStack, int left)
{
    int i = 0;
    char res = 't';
    char c = PopStack(numStack);
    while (c != left) {
        if (c == 'f') {
            res = 'f';
        }
        i++;
        c = PopStack(numStack);
    }
    if (i == 0) {
        printf("Error NumStack\n");
    }

    PushStack(numStack, res);
}
void Or(Stack numStack, int left)
{
    int i = 0;
    char res = 'f';
    char c = PopStack(numStack);
    while (c != left) {
        if (c == 't') {
            res = 't';
        }
        i++;
        c = PopStack(numStack);
    }
    if (i == 0) {
        printf("Error NumStack\n");
    }

    PushStack(numStack, res);
}
void Compute(Stack numStack, char oper, char right)
{
    int left;
    if (right == ')') {
        left = '(';
    } else {
        left = '{';
    }
    if (oper == '!') {
        Negative(numStack, left);
    }
    if (oper == '&') {
        And(numStack, left);
    }
    if (oper == '|') {
        Or(numStack, left);
    }
}
bool parseBoolExpr(char * expression){
    int len = strlen(expression);
    if (expression == NULL || len == 0) {
        return false;
    }
    Stack operStack = InitStack(len);
    Stack numStack = InitStack(len);
    int i;
    char oper;
    for (i = 0; i < len; i++) {
        switch (expression[i]) {
            case '&':
            case '|':
            case '!':
            PushStack(operStack, expression[i]);
            break;
            case '(':
            case '{':
            case 't':
            case 'f':
            PushStack(numStack, expression[i]);
            break;
            case ',':
            break;
            case ')':
            case '}':
            oper = PopStack(operStack);
            Compute(numStack, oper, expression[i]);
            break;
            default:
            printf("Error char %c\n", expression[i]);
        }
    }
    char c = PopStack(numStack);
    if (c == 't') {
        return true;
    } else {
        return false;
    }
}
```
