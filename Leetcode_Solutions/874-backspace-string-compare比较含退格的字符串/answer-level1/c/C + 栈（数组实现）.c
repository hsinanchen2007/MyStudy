### 解题思路
主体思路：通过栈的数据结构实现解题
1、入栈：先将原字符串S\T入栈；入栈原则：若遇到字符“#”则需要执行一次出栈，仅下标收缩，元素弹出不保存；
2、出栈：每次弹出一个元素，直接比较是否相同；

注意：栈是一个表，任何实现表的方法都能实现栈。一般常用实现栈的方法有【栈的链表实现】和【栈的数组实现】；本题使用后者，栈的数组实现。所以缺点是 需要首先声明一个较大的数组空间来存放后续元素。

### 代码

```c
#define MAX_STACK_SIZE 200

typedef struct {
    int capacity;
    int topOfStack;
    char *Array;
}StackRecord;

int IsStackFull(StackRecord *stackTemp) {
    if (stackTemp->topOfStack > stackTemp->capacity - 1) {
        return true; // 栈已满
    }

    return false;
}

int IsStackEmpty(StackRecord *stackTemp) {
    if (stackTemp->topOfStack == -1) {
        return true; // 栈为空
    }

    return false;
}

void pushElement(StackRecord *stackTemp, const char *sTemp, int Len)
{
    if (IsStackFull(stackTemp)) {
        return 0;
    }

    for (int i = 0; i < Len; i++) {
        if (sTemp[i] == '#') {
            if (stackTemp->topOfStack > -1)
                stackTemp->topOfStack--;
        } else {
            stackTemp->Array[++stackTemp->topOfStack] = sTemp[i];
        }
    }
}

char popElement(StackRecord *stackTemp) {
    if (IsStackEmpty(stackTemp)) {
        return 0;
    }

    return stackTemp->Array[stackTemp->topOfStack--];
}

bool backspaceCompare(char * S, char * T){
    StackRecord stackTempS;
    StackRecord stackTempT;
    stackTempS.topOfStack = -1;
    stackTempS.capacity = MAX_STACK_SIZE;
    stackTempS.Array = (char*)calloc(MAX_STACK_SIZE + 1, sizeof(char));
    stackTempT.topOfStack = -1;
    stackTempT.capacity = MAX_STACK_SIZE;
    stackTempT.Array = (char*)calloc(MAX_STACK_SIZE + 1, sizeof(char));

    int sLen = strlen(S);
    int tLen = strlen(T);

    pushElement(&stackTempS, S, sLen);
    pushElement(&stackTempT, T, tLen);

    if (stackTempS.topOfStack != stackTempT.topOfStack) {
        return false;
    }

    while (stackTempS.topOfStack > -1) {
        if (popElement(&stackTempS) != popElement(&stackTempT)) {
            return false;
        }
    }

    return true;
}


```