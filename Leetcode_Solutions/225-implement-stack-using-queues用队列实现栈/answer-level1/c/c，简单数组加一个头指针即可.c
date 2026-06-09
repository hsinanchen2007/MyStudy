### 解题思路
栈结构体包含两部分：
1、定义一个有指定大小的数组，用于存储栈里面的元素；
2、定义int型变量，充作栈的头(即栈顶)，它每次移动则代表栈里有增或删元素。

初始化栈顶为-1，元素入栈则栈顶先加一然后存入元素；
元素出栈，则先返回栈顶元素然后栈顶-1.

### 代码

```c
typedef struct {
    int data[1024];
    int top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *s;
    s = (MyStack *)malloc(sizeof(MyStack));
    s->top = -1;
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    (obj->top)++;
    obj->data[obj->top] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int res;
    res = obj->data[obj->top--];
    return res;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->data[obj->top];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top == -1){
        return 1;
    }
    return 0;
}

void myStackFree(MyStack* obj) {
    //obj->top == -1;
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