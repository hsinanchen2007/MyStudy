### 解题思路

这个题是解决栈类型常见的题型 
由于C没有STL库 故自己实现了一个栈
注意多了一个length参数 加上这个参数后 
在做default判断时 如果st->length长度大于s长度的1/2时肯定为false
少了很多判断

### 代码

```c
#include <stdio.h>
#include <malloc.h>

#define STACK_SIZE 30000

typedef char DataType;

typedef struct {
    DataType *base;
    DataType *top;
    int stack_size;
    int length;
} SeqStack, *PStack;

void Initial(SeqStack *s) {
    s->base = (DataType *) malloc(sizeof(DataType) * STACK_SIZE);
    s->top = s->base;
    s->stack_size = STACK_SIZE;
    s->length = 0;
}

int IsEmpty(PStack s) {
    return s->base == s->top;
}

int IsFull(PStack s) {
    return s->top - s->base == STACK_SIZE - 1;
}

void Push(PStack s, DataType x) {
    s->top++;
    s->length++;
    *(s->top) = x;
}

DataType Pop(PStack s) {
    s->length--;
    return *(s->top)--;
}

void ClearStack(PStack s) {
    s->length = 0;
    s->top = s->base;
}

int LengthStack(PStack s) {
    return s->length;
}

bool isValid(char *s) {
    int length = strlen(s);
    PStack *st;
    st = (PStack) malloc(sizeof(SeqStack));
    Initial(st);

    if (s[0] == '\0') {
        return true;
    }
    for (int i = 0; i < length; ++i) {
        switch (s[i]) {
            case '(':
                Push(st, ')');
                break;
            case '{':
                Push(st, '}');
                break;
            case '[':
                Push(st, ']');
                break;
            default:
                if (IsEmpty(st) || LengthStack(st) > length / 2) {
                    return false;
                }

                if (s[i] != Pop(st)) {
                    return false;
                }
        }
    }
    return IsEmpty(st);
}
```