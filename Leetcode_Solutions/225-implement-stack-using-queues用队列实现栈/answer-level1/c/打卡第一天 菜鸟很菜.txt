### 解题思路
* 使用队列实现栈。详细信息请见注释。借鉴了一位大佬的，菜鸟边写注释边再理解一遍了。

### 代码

```c
// 设置全局变量，为队列的最大值。
# define QUEUE_MAX_SIZE 1000
// 栈的结构体。其中queue[]为数组，存放真正的数据。head为栈底。tail为栈顶。
// 栈的概念里从tail一边进行压栈弹出操作。但队列操作，从head处出，从tail处进。
typedef struct {
    int queue[QUEUE_MAX_SIZE];
    int head;
    int tail;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate() {
    MyStack *stack=malloc(sizeof(MyStack));//申请空间
    stack->head=0;//初始化头
    stack->tail=0;//初始化尾
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->queue[obj->tail++]=x;//从尾部压栈。先压入再加加tail值。
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queue[obj->tail - 1];//tail一直指向第一个没有值的，所以求栈顶时，需要将tail值减一。
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top = myStackTop(obj);//获取当前栈顶。
    for (int i=0;i<obj->tail-obj->head-1;i++)
    {
        obj->queue[obj->tail++]=obj->queue[obj->head++];//将原来的数再次入队列
    }
    obj->head++;
    return top;
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