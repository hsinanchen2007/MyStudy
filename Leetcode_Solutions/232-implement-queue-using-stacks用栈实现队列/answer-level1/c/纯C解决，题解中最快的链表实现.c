### 解题思路
创建两个栈，一个进入栈一个退出栈

代码非常清晰，不懂得欢迎留言~
### 代码

```c
struct node{
    int val;
    struct node *next;
};
typedef struct {
    struct node* stack_in;
    struct node* stack_out;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {//建立头结点
    MyQueue *Quenue=(MyQueue *)malloc(sizeof(MyQueue));
    Quenue->stack_in=(struct node* )malloc(sizeof(struct node));
    Quenue->stack_out=(struct node*)malloc(sizeof(struct node));
    Quenue->stack_in->next=0;
    Quenue->stack_in->val=-2147483647;
    Quenue->stack_out->next=0;
    Quenue->stack_out->val=-2147483647;
    return Quenue;
}   

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    struct node *Node=(struct node*)malloc(sizeof(struct node));
    Node->val=x;

    //插入
    struct node* q=obj->stack_in->next;
    obj->stack_in->next=Node;
    Node->next=q;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(!obj->stack_out->next&&!obj->stack_in->next)
    return obj->stack_in->val;
    struct node *q;
    if(obj->stack_out->next)//退出栈还有元素，直接退
    {
        int target=obj->stack_out->next->val;
        q=obj->stack_out->next;
        obj->stack_out->next=q->next;
        free(q);
        return target;
    }
    if(!obj->stack_out->next)//退出栈没有元素
    {
        while(obj->stack_in->next)//把进入栈的元素全部转入到退出栈中
        {
            q=obj->stack_in->next;
            obj->stack_in->next=q->next;
            q->next=obj->stack_out->next;
            obj->stack_out->next=q;       
        }
    }
    int target=obj->stack_out->next->val;
    q=obj->stack_out->next;
    obj->stack_out->next=q->next;
    free(q);
    return target;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
        if(!obj->stack_out->next&&!obj->stack_in->next)
    return obj->stack_out->val;
    if(obj->stack_out->next)
    return obj->stack_out->next->val;
    struct node *q=obj->stack_out->next;
    while(obj->stack_in->next)
    {
        q=obj->stack_in->next;
        obj->stack_in->next=q->next;
        q->next=obj->stack_out->next;
        obj->stack_out->next=q;
    }
    return obj->stack_out->next->val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->stack_in->next||obj->stack_out->next)
    return false;
    return true;
}

void myQueueFree(MyQueue* obj) {
    while(obj->stack_in->next)
    {
        struct node* q=obj->stack_in->next;
        obj->stack_in->next=q->next;
        free(q);
    }
    while(obj->stack_out->next)
    {
        struct node* q=obj->stack_out->next;
        obj->stack_out->next=q->next;
        free(q);
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