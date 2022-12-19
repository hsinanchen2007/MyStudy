### 解题思路
对C语言而言,链表模拟栈优点是不用考虑是否存在溢出的问题.另外引入一个冗余头节点,简化了操作.

### 代码

```c
typedef struct node {
    int val;
    struct node* next;
} NODE;

typedef struct {
    struct node head;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    memset(st, 0, sizeof(MyStack));
    
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    NODE* tmp = (NODE*)malloc(sizeof(NODE));
    memset(tmp, 0, sizeof(MyStack));
    tmp->val = x;
    
    tmp->next = obj->head.next;
    obj->head.next = tmp;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    NODE* tmp = obj->head.next;
    int ret = tmp->val;
    obj->head.next = obj->head.next->next;
    free(tmp);
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->head.next->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->head.next == NULL;
}

void myStackFree(MyStack* obj) {
    NODE* tmp;
    NODE* head = obj->head.next;
    while(head) {
        tmp = head;
        head = head->next;
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