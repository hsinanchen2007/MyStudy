### 解题思路
这里用一个链表来实现栈，其中链表头仅起到辅助作用，栈顶为链表头的下一个元素。

### 代码

```c
typedef struct mystack{
    int val;
    struct mystack* next;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* mstack = (MyStack*)malloc(sizeof(MyStack));
    mstack->val = 0;
    mstack->next = NULL;
    return mstack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    MyStack* newstack = (MyStack*)malloc(sizeof(MyStack));
    newstack->val = x;
    newstack->next = obj->next;
    obj->next = newstack;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyStack* tmp = obj->next;
    obj->next = tmp->next;
    int res = tmp->val;
    free(tmp);
    return res;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return (obj->next)->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->next == NULL;
}

void myStackFree(MyStack* obj) {
    while(obj != NULL) {
        MyStack* tmp = obj;
        obj = obj->next;
        free(tmp);
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