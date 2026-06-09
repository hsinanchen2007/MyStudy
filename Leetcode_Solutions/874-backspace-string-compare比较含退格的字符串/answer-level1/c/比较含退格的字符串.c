### 解题思路
用栈实现

### 代码

```c
typedef unsigned int uint;
typedef struct {
    uint top;
    uint size;
    char arr[200];
} Stack;

Stack stack1 = {0};
Stack stack2 = {0};

void push_(Stack *stackHead, char element) {
    if (stackHead->top > (stackHead->size - 1)) {
        return ;
    }

    if (element == '#') {
        // top 等于 0 表示空栈
        if (stackHead->top > 0) {
            stackHead->top--;
        }
    } else {
        stackHead->arr[stackHead->top] = element;  
        stackHead->top++;   
    }
}

char pop_(Stack *stackHead) {
    if (stackHead->top == 0) {
        return '@';
    }

    return stackHead->arr[--stackHead->top];
}

bool backspaceCompare(char * S, char * T){
    uint slen = strlen(S);
    uint tlen = strlen(T);
    stack1.size = 200;
    stack1.top = 0;
    stack2.size = 200;
    stack2.top = 0;

    uint i = 0;
    for (i = 0; i < slen; i++) {
        push_(&stack1, S[i]);
    }

    for (i = 0; i < tlen; i++) {
        push_(&stack2, T[i]);
    }

    if (stack1.top != stack2.top) {
        return false;
    }

    for (i = 0; i < stack1.top; i++) {
        if (pop_(&stack1) != pop_(&stack2)) {
            return false;
        }
    }

    return  true;
}
```