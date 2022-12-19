### 解题思路
先写链表节点，用链表做写栈，写完栈再写队列。
![image.png](https://pic.leetcode-cn.com/9567177759921b9c174fcfeeb62880248c54ae504ccbf843dbe2460901e8a0e0-image.png)

### 代码

```c
typedef struct Node{
    int data;
    struct Node* next;
}Node;
//新建节点
Node* newNode(int Data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=Data;
    n->next=0;
    return n;
}
//头插法入栈
void stackPush(Node* StackHead,int Data)
{
    Node* n=newNode(Data);
    n->next=StackHead->next;
    StackHead->next=n;
}
//从链表头出栈
int stackPop(Node* StackHead)
{
    int result=StackHead->next->data;
    Node* n=StackHead->next;
    StackHead->next=n->next;
    free(n);
    return result;
}
//释放栈内存
void stackFree(Node* StackHead)
{
    while(StackHead!=0)
    {
        Node* n=StackHead;
        StackHead=StackHead->next;
        free(n);
    }
}
//____________________________________________________以上是栈操作
typedef struct {
    Node* stackOut;
    Node* stackIn;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* queue=(MyQueue*)malloc(sizeof(MyQueue));
    queue->stackIn=newNode(0);
    queue->stackOut=newNode(0);
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->stackIn,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(obj->stackOut->next==0)
        while(obj->stackIn->next!=0)
            stackPush(obj->stackOut,stackPop(obj->stackIn));
    return stackPop(obj->stackOut);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(obj->stackOut->next==0)
        while(obj->stackIn->next!=0)
            stackPush(obj->stackOut,stackPop(obj->stackIn));
    return obj->stackOut->next->data;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->stackOut->next==0&&obj->stackIn->next==0;
}

void myQueueFree(MyQueue* obj) {
    stackFree(obj->stackIn);
    stackFree(obj->stackOut);
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