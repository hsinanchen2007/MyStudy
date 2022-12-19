### 解题思路
在每次push数据时，使队列前端数据后置，确保队列的前端数据为栈的栈顶

### 代码

```c
typedef struct {
    int q[1000];
    int tail;
    int head;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* obj = malloc(sizeof(MyStack));
    obj->tail = 0;
    obj->head = 0;
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->q[obj->tail++] = x;
    for(int i = 0; i < obj->tail - obj->head - 1; i++){
        obj->q[obj->tail++] = obj->q[obj->head++];
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top = myStackTop(obj);
    obj->head++;
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->q[obj->head];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->tail == obj->head;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
```