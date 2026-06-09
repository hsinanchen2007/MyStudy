### 解题思路
单向链表模拟堆栈，使用一个指针(top)始终指向栈顶，通过操作该指针完成堆栈各种操作。
压入-O(1)  弹出-O(1)

- ![a.bmp](https://pic.leetcode-cn.com/6a40d1cb4a41a9315a06191c49bbc673cd3f6676c2f84ceb7dbd14ce215f2797-a.bmp)


### 代码

```c
typedef struct tagLinkNode{
    struct tagLinkNode *next;
    int val;
}LinkNode;

typedef struct {
    LinkNode *top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stk = calloc(1, sizeof(MyStack));
    return stk;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    LinkNode *node = malloc(sizeof(LinkNode));
    node->val = x;
    node->next = obj->top;
    obj->top = node;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    LinkNode *node = obj->top;
    int val = node->val;
    obj->top = node->next;
    free(node);
    
    return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->top->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (obj->top == NULL);
}

void myStackFree(MyStack* obj) {
    while (obj->top != NULL) {
        LinkNode *node = obj->top;
        obj->top = obj->top->next;
        free(node);
    }
    free(obj);
}
```