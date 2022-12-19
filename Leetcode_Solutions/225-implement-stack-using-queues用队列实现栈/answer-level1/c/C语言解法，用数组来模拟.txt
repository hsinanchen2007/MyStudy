### 解题思路
此处撰写解题思路
思路就是采用数组来模拟队列，定义变量num标识栈当前的大小，定义top标识当前栈顶，当push入栈的时候，top++,num++;当出栈的时候，top--,num--。
很常规的解法
### 代码
#define MAX_SIZE 1000
typedef struct {
    int a[MAX_SIZE];
    int num;
    int top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* m_stack =malloc(sizeof(MyStack)); 
    m_stack->num = 0;
    m_stack->top = -1;
    return m_stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->top++;
    obj->a[obj->top] = x;
    obj->num++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(obj->num == 0)
        return -1;
    else
    {
        int res = obj->a[obj->top];
        obj->num--;
        obj->top--;
        return res;
    }
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(obj->num == 0)
        return -1;
    else
    {
        int res = obj->a[obj->top];
        return res;
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top == -1)
        return true;
    else 
        return false;
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