### 解题思路
为了打卡 ~_~

### 代码

```c
#define DEFAULT_LEN 64

typedef struct{
    int *data;
    int tear;
    int size;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->size = DEFAULT_LEN;
    stack->tear = 0;
    stack->data = (int *)malloc(sizeof(int) * stack->size);
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    int *temp = NULL;
    if (obj == NULL) {
        return;
    }
    if (obj->tear >= obj->size) {
        obj->size = obj->size * 3 / 2;
        temp = (int *)malloc(sizeof(int) * obj->size);
        memcpy(temp, obj->data, obj->tear);
        free(obj->data);
        obj->data = temp;
    }
    obj->data[obj->tear] = x;
    obj->tear++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (obj == NULL) {
        return 0;
    }
    if (obj->tear == 0) {
        return 0;
    }
    obj->tear--;
    return obj->data[obj->tear];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj == NULL) {
        return 0;
    }
    if (obj->tear == 0) {
        return 0;
    }
    return obj->data[obj->tear - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj == NULL) {
        return true;
    }

    return obj->tear == 0;
}

void myStackFree(MyStack* obj) {
    if (obj == NULL) {
        return;
    }

    if (obj->data != NULL) {
        free(obj->data);
    }
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