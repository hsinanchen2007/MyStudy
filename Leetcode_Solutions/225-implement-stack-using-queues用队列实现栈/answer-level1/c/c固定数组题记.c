### 解题思路
采用头尾指针，题目涉及的数据量很小，所以数组设置固定大小，

### 代码

```c
typedef struct {
    int data[100];
    int head;
    int tail;
    
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));
    stack->head =0;
    stack->tail=0;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->data[obj->tail++]=x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top = obj->data[obj->tail-1];
    for (int i = 0; i < obj->tail - obj->head - 1; i++) {
        obj->data[obj->tail++] = obj->data[obj->head++];
    }
    obj->head++;
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
return obj->data[obj->tail-1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
return obj->head == obj->tail;
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