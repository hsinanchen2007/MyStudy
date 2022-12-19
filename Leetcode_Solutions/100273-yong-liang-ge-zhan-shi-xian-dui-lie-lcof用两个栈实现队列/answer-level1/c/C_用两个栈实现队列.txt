### 解题思路
链表栈实现

### 代码

```c
//-------------------------------------------------------------链表栈
typedef struct Node
{
    int val;
    struct Node* next;
}Node;
Node* newNode(int Val)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->val=Val;
    n->next=0;
    return n;
}
void push(Node* Head,int Val)
{
    Node* n=newNode(Val);
    n->next=Head->next;
    Head->next=n;
}
int pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    int result=n->val;
    free(n);
    return result;
}
void del(Node* Head)
{
    while(Head!=0)
    {
        Node* n=Head;
        Head=Head->next;
        free(n);
    }
}
//-------------------------------------------------------------队列
typedef struct {
    Node* stackIn;
    Node* stackOut;
} CQueue;

CQueue* cQueueCreate() {
    CQueue* q=(CQueue*)malloc(sizeof(CQueue));
    q->stackIn=newNode(0);
    q->stackOut=newNode(0);
    return q;
}
void cQueueAppendTail(CQueue* obj, int value) {
    push(obj->stackIn,value);
}

int cQueueDeleteHead(CQueue* obj) {
    if(obj->stackOut->next==0&&obj->stackIn->next==0)
        return -1;
    if(obj->stackOut->next==0)
        while(obj->stackIn->next!=0)
            push(obj->stackOut,pop(obj->stackIn));
    return pop(obj->stackOut);
}

void cQueueFree(CQueue* obj) {
    del(obj->stackIn);
    del(obj->stackOut);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
```