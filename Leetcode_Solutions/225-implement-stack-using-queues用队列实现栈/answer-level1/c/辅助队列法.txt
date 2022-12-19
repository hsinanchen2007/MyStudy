### 解题思路
此处撰写解题思路
主要使用一个辅助队列，实现相关操作。
1. Push操作正常操作即可
2. Pop时，需要将队列中除队尾元素全部放入辅助队列。
3. 输出队尾。
4. 再将辅助队列中数据全部放回主队列即可。

### 代码

```c

typedef struct Node {
    int val;
    struct Node *next;
}Node;


typedef struct {
    struct Node *first;
    struct Node *last;
} MyQueue;

MyQueue *CreateQueue(void)
{
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->first = NULL;
    queue->last  = NULL;
    return queue;
}

bool IsEmpty(MyQueue *queue)
{
    return queue->first == NULL;
}

void EnQueue(MyQueue *queue, int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (IsEmpty(queue)) {
        queue->first = node;
    } else {
        queue->last->next = node;
    }
    queue->last = node;
    return;
}

bool DeQueue(MyQueue *queue, int *val)
{
    if (IsEmpty(queue)) {
        return false;
    }

    Node *node = queue->first;
    queue->first = node->next;
    *val = node->val;
    free(node);
    return true;
}

typedef struct {
    MyQueue *mainQueue;
    MyQueue *secondQueue;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->mainQueue = CreateQueue();
    stack->secondQueue = CreateQueue();
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    EnQueue(obj->mainQueue, x);
    return;
}

bool IsLastNode(MyQueue *queue)
{
    if (IsEmpty(queue)) {
        return false;
    }

    return queue->first->next == NULL;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int val, ret;
    while (!IsLastNode(obj->mainQueue)) {
        DeQueue(obj->mainQueue, &val);
        EnQueue(obj->secondQueue, val);
    }

    DeQueue(obj->mainQueue, &ret);

    while(!IsEmpty(obj->secondQueue)) {
        DeQueue(obj->secondQueue, &val);
        EnQueue(obj->mainQueue, val);
    }
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->mainQueue->last->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return IsEmpty(obj->mainQueue);
}

void myStackFree(MyStack* obj) {
    int val;
    while (!IsEmpty(obj->mainQueue)) {
        DeQueue(obj->mainQueue, &val);
    }

    free(obj->mainQueue);
    free(obj->secondQueue);
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