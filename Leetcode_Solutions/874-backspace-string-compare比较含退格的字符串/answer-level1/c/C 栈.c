### 解题思路
栈的使用，注意如果已经没有元素可以弹出了，不理会退格即可。

### 代码

```c
#define MAXLENGTH 200
#define OK 0
#define ERR 1

struct stack{
    char* array;
    char* top;
    char* bottom;
    int size;
    int cnt;
};

int push(struct stack* stack, char c) 
{
    *(stack->top) = c;
    stack->top++;
    stack->cnt++;
    return OK;
}

int pop(struct stack* stack) 
{
    //如果已经没有任何元素可以弹出，则不弹出。
    if(stack->top == stack->bottom) {
        return OK;
    }
    stack->top--;
    *(stack->top) = '\0';
    stack->cnt--;
    return OK;
}

bool backspaceCompare(char * S, char * T){
    if ((NULL == S) || (NULL == T)) {
        return true;
    }
    char* tmpChar = NULL;
    struct stack* stackS = (struct stack*)malloc(sizeof(struct stack));
    struct stack* stackT = (struct stack*)malloc(sizeof(struct stack));
    memset(stackS, 0, sizeof(struct stack));
    memset(stackT, 0, sizeof(struct stack));

    stackS->array = (char *)malloc(sizeof(char) * MAXLENGTH);
    memset(stackS->array, 0, sizeof(char) * MAXLENGTH);
    stackT->array = (char *)malloc(sizeof(char) * MAXLENGTH);
    memset(stackT->array, 0, sizeof(char) * MAXLENGTH);

    stackS->top = stackS->array;
    stackS->bottom = stackS->array;
    stackS->size = MAXLENGTH;

    stackT->top = stackT->array;
    stackT->bottom = stackT->array;
    stackT->size = MAXLENGTH;

    for (tmpChar = S; *tmpChar != 0; tmpChar++) {
        if ('#' == *tmpChar) {
            pop(stackS);
        } else {
            push(stackS, *tmpChar);
        }
    }

    for (tmpChar = T; *tmpChar != 0; tmpChar++) {
        if ('#' == *tmpChar) {
            pop(stackT);
        } else {
            push(stackT, *tmpChar);
        }
    }

    if (0 == strcmp(stackS->bottom, stackT->bottom)) {
        free( stackS->array);
        free( stackT->array);
        free( stackS);
        free( stackT);
        return true;
    }
    else {
        free( stackS->array);
        free( stackT->array);
        free( stackS);
        free( stackT);
        return false;
    }
}
```