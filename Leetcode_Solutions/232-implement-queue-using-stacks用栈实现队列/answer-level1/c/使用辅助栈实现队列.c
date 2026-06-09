使用双栈模拟队列的push操作，队列的pop和peek操作和栈的pop、peek操作一致，直接弹出栈顶元素即可；而队列的push操作对于栈来说分为两个过程：

- 弹出栈1的元素
- 将弹出的元素入栈到栈2

循环上述过程直到栈1位空，再使用栈的push操作往栈1写入待添加的元素，最后再弹出栈2每个元素并入栈到栈1

由于C没有原生栈实现，因此用单向链表模拟栈，组织结构为栈指针永远指向栈顶，栈元素从顶到底用next指针连接，栈底（队列首部）的next为空

执行用时 :
0 ms
, 在所有C提交中击败了
100.00%
的用户
内存消耗 :
7.1 MB
, 在所有C提交中击败了
100.00%
的用户

```

typedef struct myStack {
    int val;
    struct myStack *next;
} MyStack;

typedef struct {
    MyStack *s1;
    int cnt;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *Q = (MyQueue *)malloc(sizeof(MyQueue));
    memset(Q, 0, sizeof(MyQueue));
    return Q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    MyStack *n = (MyStack *)malloc(sizeof(MyStack));
    MyStack *q = NULL, *t = NULL;
    n->val = x;
    n->next = NULL;
/* 从栈1出栈并往栈2（q）入栈 */
    while (obj->s1) {
        t = obj->s1;
        obj->s1 = obj->s1->next;
        t->next = q;
        q = t;
    }
/* 栈1push */
    obj->s1 = n;
/* 从栈2出栈并往栈1入栈 */
    while (q) {
        t = q;
        q = q->next;
        t->next = obj->s1;
        obj->s1 = t;
    }
    obj->cnt++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int res;
    MyStack *p = obj->s1;
    obj->s1 = p->next;
    obj->cnt--;
    res = p->val;
    free(p);
    return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->s1->val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return !obj->cnt;
}

void myQueueFree(MyQueue* obj) {
    MyStack *p = obj->s1, *t;
    while (p) {
        t = p;
        p = p->next;
        free(t);
    }
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
```