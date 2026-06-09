感觉就是写了个栈，跟队列没啥关系
```
#define MAXSIZE 1000

typedef struct {
    int nums[MAXSIZE];
    int front, rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *re = (MyStack*)calloc(1, sizeof(MyStack));
    re->front = 0;
    re->rear = -1;
    return re;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->nums[++(obj->rear)] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int x = obj->nums[(obj->rear)--];
    return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->nums[obj->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->rear == -1;
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
