### 解题思路
此处撰写解题思路
1.栈是先进后出，即栈顶元素先出，依次向栈底元素遍历；队列是先进先出，即从对头元素向队尾遍历。
2.出栈时要注意栈和队列的出栈和出队列呃顺序
### 代码

```c
#define QUEUE_MAX_SIZE 1000
typedef struct {
    int queue[QUEUE_MAX_SIZE];
    int head;
    int tail;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));
    stack->head = 0;
    stack->tail=0;
    return stack;

}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->queue[obj->tail++] = x;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queue[obj->tail - 1];
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top = myStackTop(obj);
    for( int i = 0; i < obj->tail - obj->head - 1; i++ ){
        obj->queue[obj->tail++] = obj->queue[obj->head++];
    }
    obj->head++;
    return top;
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