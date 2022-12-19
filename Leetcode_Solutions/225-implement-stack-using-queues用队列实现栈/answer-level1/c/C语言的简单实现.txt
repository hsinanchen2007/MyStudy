### 解题思路
栈是先进后出，队列是先进先出，插入方面两者差不多，在tail处插入，关于删除栈顶元素只需要将队列里的元素从tail处再次入列，即原来的head元素插入到tail处，在对head和tail依次自加，注意原来的尾元素即栈顶元素舍弃。

### 代码

```c
typedef struct {
    int queue[1000];
    int head;
    int tail;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *mystack = malloc(sizeof(MyStack));
    mystack->head=0;
    mystack->tail=0;
    return mystack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->queue[obj->tail++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top = myStackTop(obj);
    for(int i = 0;i<obj->tail - obj->head - 1;i++)
        obj->queue[obj->tail++] = obj->queue[obj->head++];
    obj->head++;
    return top;   
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queue[obj->tail-1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (obj->head == obj->tail);
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