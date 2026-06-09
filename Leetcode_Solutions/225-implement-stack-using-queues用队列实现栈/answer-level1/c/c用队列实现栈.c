### 解题思路

首先需要用队列来实现栈，队列是先进先出，栈则是永远从栈顶出，初始化就不说了，入栈我们只需要在队列的最后面加入数据就行了，栈顶元素就是最后加进来的元素也就是栈顶指针tail-1，出栈我们需要吧栈前面的值全部一到栈顶元素后面的值，就这个思路，队列头和尾相等说明时空的。

### 代码

```c
typedef struct a{
    int queey[100];
    int head,tail; 
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack * abc = (MyStack * )malloc(sizeof(MyStack));
    abc->head = 0;
    abc->tail = 0;
    return abc;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->queey[obj->tail++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top = obj->queey[obj->tail-1];
    for(int i=0;i<obj->tail-obj->head-1;i++){
        obj->queey[obj->tail++] = obj->queey[obj->head++];
    }
    obj->head++;
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queey[obj->tail-1];
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