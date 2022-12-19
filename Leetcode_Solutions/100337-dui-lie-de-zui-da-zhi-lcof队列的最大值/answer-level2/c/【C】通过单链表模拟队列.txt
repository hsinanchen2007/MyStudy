### 解题思路
    好像在pop的时候做不到o(1),因为pop的时候要重新判断最大值元素，最坏情况下需要遍历整个链表

### 代码

```c
typedef struct Queue{
    int val;
    struct Queue *next;
    struct Queue *rear;
    int max;
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue* Head=(MaxQueue*)malloc(sizeof(MaxQueue));
    Head->next=NULL;
    Head->max=0;
    Head->rear=Head;
    return Head;
}

int maxQueueMax_value(MaxQueue* obj) {
    if(obj->max==0)
        return -1;
    else
        return obj->max;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    MaxQueue* p=(MaxQueue*)malloc(sizeof(MaxQueue));
    p->val=value;
    p->next=NULL;
    if(value>obj->max)
        obj->max=value;
    obj->rear->next=p;
    obj->rear=p;
    
}

int maxQueuePop_front(MaxQueue* obj) {
    MaxQueue *p;
    p=obj->next;
    if(!p)
        return -1;
    obj->next=p->next;
    if(p->val==obj->max)
    {
        if(obj->next!=NULL)
        {
            int max=obj->next->val;
            MaxQueue *q;
            q=obj->next;
            while(q)
            {
                if(q->val>max)
                    max=q->val;
                q=q->next;
            }
            obj->max=max;
        }
        else
            obj->max=0;
    }
    int res=p->val;
    if(p==obj->rear)
    {
        MaxQueue *q=obj;
        while(q->next!=NULL)
            q=q->next;
        obj->rear=q;
    }

    return res;
}

void maxQueueFree(MaxQueue* obj) {
    MaxQueue *q,*p;
    p=obj->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(obj);
}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/
```