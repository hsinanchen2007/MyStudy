### 解题思路
1. 双向链表, head, last
2. push: 分配新节点放在last->next, last更新到新节点
3. pop：返回last节点的值，last更新到last->prev
4. pop：返回last节点的值
5. empty：根据last节点是否为NULL判断
6. 假设所有操作有效，因此省了一些异常判断。

### 代码

```c
typedef struct myListNode {
    int val;
    struct myListNode *next;
    struct myListNode *prev;
} MyListNode;

typedef struct {
    MyListNode *head;
    MyListNode *last;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stk = (MyStack*)malloc(sizeof(MyStack));
    if (!stk) return NULL;
    (void)memset(stk, 0, sizeof(MyStack));
    return stk;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    MyListNode *node = (MyListNode*)malloc(sizeof(MyListNode));
    if (!node) return;

    (void)memset(node, 0, sizeof(MyListNode));
    node->val = x;
    if (obj->last == NULL) {
        obj->head = obj->last = node;
    } else {
        obj->last->next = node;
        node->prev = obj->last;
        obj->last = node;
    }
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyListNode *node = obj->last;
    int val = node->val;
    obj->last = node->prev;
    if (obj->last) obj->last->next = NULL;
    free(node);
    return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->last->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->last ? false : true;
}

void myStackFree(MyStack* obj) {
    MyListNode *node = obj->last;
    MyListNode *tmp;
    while (node) {
        tmp = node->prev;
        free(node);
        node = tmp;
    }
    free(obj);
    return;
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