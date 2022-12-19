### 解题思路
定义结构体头指针尾指针，长度，和value数组存储值
创建的时候初始化结构体，push时在尾指针加元素，pop将尾指针元素return

### 代码

```c
typedef struct {
    int rear;
    int front;
    int length;
    int *value;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* obj =(MyStack*) malloc(sizeof(MyStack) * 1000);
    if (obj == NULL) {
        return NULL;
    }
    obj->rear = 0;
    obj->front = 0;
    obj->length = 0;
    obj->value = (int*)malloc(sizeof(int) * 100);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->value[obj->rear] = x;
    (obj->rear)++;
    (obj->length)++;
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    (obj->rear)--;
    (obj->length)--;
    return obj->value[obj->rear];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int ele = obj->value[obj->rear - 1];
    return ele;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->length == 0) {
        return true;
    } else {
        return false;
    }
}

void myStackFree(MyStack* obj) {
    free(obj->value);
    obj->value = NULL;
    free(obj);
    obj = NULL;
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