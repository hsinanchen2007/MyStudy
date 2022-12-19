### 解题思路
1、用数组存储内容，用变量topIndex表示当前栈顶。
2、push时候topIndex + 1，pop时候topIndex - 1。
3、空栈时候进行操作要注意边界值。

### 代码

```c
#define MAXSIZE_SL1 80000
typedef struct {
    int data[MAXSIZE_SL1];
    int top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stack = malloc(sizeof(MyStack));
    (void)memset(stack, 0, sizeof(MyStack));
    stack->top = -1;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* stack, int x) {
    if (stack->top == MAXSIZE_SL1 - 1) {
        printf("PushL1 fail!\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* stack) {
    if(stack->top == -1) {
        printf("PopL1 fail!\n");
        return -1;
    }
    int topVal = stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top--;
    return topVal;
}

/** Get the top element. */
int myStackTop(MyStack* stack) {
    if (stack->top == -1) {
		printf("GetTopL1 fail!\n");
        return -1;
    }
	return (stack->data[stack->top]);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* stack) {
    return (stack->top == -1) ? (true) : (false);
}

void myStackFree(MyStack* stack) {
    free(stack);
    stack = NULL;
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