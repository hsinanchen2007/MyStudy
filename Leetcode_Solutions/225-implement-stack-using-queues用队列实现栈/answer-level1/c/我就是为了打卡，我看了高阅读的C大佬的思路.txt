### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_SIZE 1000
typedef struct {
    int queue[MAX_SIZE];//创建MyStack时在此结构体内创建了一个队列；
    int head;//用来标记队列queue的头指针；
    int tail;//用来标记队列queue的尾指针；
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stack=(MyStack*)malloc(sizeof(MyStack));
    stack->head=0;
    stack->tail=0;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->queue[obj->tail++]=x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int top_obj;
    top_obj=obj->queue[obj->tail-1];
    return top_obj;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top_obj=myStackTop(obj);
    for(int i=0;i<obj->tail-obj->head-1;i++)
       obj->queue[obj->tail++]=obj->queue[obj->head++];
    obj->head++;
    return top_obj;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->head==obj->tail;
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