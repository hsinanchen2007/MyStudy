### 解题思路
c木有队列呀。。。

### 代码

#define MAX 1024
# typedef struct {
    int start;
    int end;
    int queue[MAX];
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *st = (MyStack *)calloc(1, sizeof(MyStack));;
    st->start = 0;
    st->end = 0;
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->queue[(obj->end)++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return obj->queue[--(obj->end)];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queue[(obj->end) - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->start == obj->end;
}

void myStackFree(MyStack* obj) {
    free(obj);
}
