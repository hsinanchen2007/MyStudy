### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
int date[1000];
int front,rare;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
stack->front = stack->rare = 0;
return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
obj->date[++(obj->rare)] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
int m = obj->date[(obj->rare)--];
return m;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
return obj->date[obj->rare];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
return obj->front==obj->rare;

}

void myStackFree(MyStack* obj) {
obj->front = obj->rare = 0;
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