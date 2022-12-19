### 解题思路
定义head, 用来标记 push 和 pop 的位置

### 代码

```c
typedef struct {
    int value[1024];
    int head;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* head = NULL;

    head = (MyStack*)malloc(sizeof(MyStack));
    memset(head, 0, sizeof(MyStack));
    
    return head;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->value[obj->head++] = x;
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) { 
    int temp = obj->head != 0 ? (--obj->head) : 0;   
    return obj->value[temp];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int temp = obj->head != 0 ? (obj->head - 1) : 0; 
    return obj->value[temp];   
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->head == 0) {
        return true;
    }
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