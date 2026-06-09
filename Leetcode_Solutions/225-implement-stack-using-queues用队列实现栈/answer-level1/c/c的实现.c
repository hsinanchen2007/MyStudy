### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_NUM 5000
typedef struct {
    int buf[MAX_NUM];
    int head;
    // int tail;
    int cnt;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* head = (MyStack*) malloc(sizeof(MyStack));
    memset(head, 0, sizeof(MyStack));
    return head;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj->head >= MAX_NUM) {
        return;
    }
    obj->buf[obj->head] = x;
    obj->head++;
    obj->cnt++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (obj->head <= 0) {
        return 0;
    }
    obj->head--;
    int val = obj->buf[obj->head];    
    obj->cnt--;
    return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj->head <= 0) {
        return 0;
    }
    int idx = obj->head - 1;
    return obj->buf[idx];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->cnt > 0 ? false : true;
}

void myStackFree(MyStack* obj) {
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