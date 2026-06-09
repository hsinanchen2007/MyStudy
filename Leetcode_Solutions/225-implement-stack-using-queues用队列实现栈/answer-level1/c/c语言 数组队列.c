### 解题思路
队列的格式为数组类型 头插尾删 形成队列
其中只有pop需要更新处理 当栈pop时需要退出最近输入元素 而在队列中最近输入元素刚好在队头 则利用top获得队首元素之后再队尾元素向队首元素移动 完成对栈的元素的弹出

### 代码

```c
#define MAX_SIZE 1000
typedef struct {
    int queue[MAX_SIZE];
    int head;
    int tail;       //队列只允许头插尾删
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *a = (MyStack *)malloc(sizeof(MyStack));
    a->head = 0;
    a->tail = 0;
    return a;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->queue[obj->head++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top = myStackTop(obj);
    for (int i = 0; i < obj->head - obj->tail - 1; i++) {
        obj->queue[obj->head++] = obj->queue[obj->tail++];
    }
    obj->tail++;
    return top;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queue[obj->head-1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    bool flag;
    return flag = obj->head-obj->tail == 0 ?true : false;
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