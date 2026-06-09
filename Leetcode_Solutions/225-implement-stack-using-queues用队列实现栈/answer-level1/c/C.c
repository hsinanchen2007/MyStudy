### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int *a;
    int *b;
    int **pointer;
    int size;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    stack->a = (int*)malloc(sizeof(int) * 200);
    stack->b = (int*)malloc(sizeof(int) * 200);
    stack->pointer = &(stack->a);
    stack->size = 0;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    (*(obj->pointer))[(obj->size)++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int **another, i;
    another = (*(obj->pointer) == obj->a) ? &(obj->b) : &(obj->a);
    for(i = 0; i < obj->size - 1; i++){
        (*another)[i] = (*(obj->pointer))[i];
    }
    i = (*(obj->pointer))[--(obj->size)];
    obj->pointer = another;
    return i;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int **another, i;
    another = (*(obj->pointer) == obj->a) ? &(obj->b) : &(obj->a);
    for(i = 0; i < obj->size; i++){
        (*another)[i] = (*(obj->pointer))[i];
    }
    i = (*(obj->pointer))[obj->size - 1];
    obj->pointer = another;
    return i;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (0 == obj->size);
}

void myStackFree(MyStack* obj) {
    free(obj->a);
    free(obj->b);
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