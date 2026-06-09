### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int value[1024];
    int head;
    int tail;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stack=(MyStack*)malloc(sizeof(MyStack));
    stack->head=0;
    stack->tail=-1;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->value[++(obj->tail)]=x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
   return obj->value[(obj->tail)--];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->value[obj->tail];

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->tail==-1;
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