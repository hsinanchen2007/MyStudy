### 解题思路
时间换空间，用时就nmd离谱
执行用时 :316 ms, 在所有 C 提交中击败了20.83%的用户
内存消耗 :44.5 MB, 在所有 C 提交中击败了100.00%的用户

队列用链表实现，还用链表实现了一个有序的栈用来存之前的最大值和出现的次数，然后就是根据样例修修补补。。。
题目标签有sliding window，还没看其他题解，真想不出怎么滑

### 代码

```c
typedef struct MQ_NODE{
    int value;
    struct MQ_NODE *next;
}MQNode;

typedef struct MAX_STACK{
    int value;
    int cnt;
    struct MAX_STACK *next;
}MaxStack;

typedef struct {
    MQNode *front;
    MQNode *rear;
    MaxStack *maxstack;
    int max_value;
} MaxQueue;

void maxStackPop(MaxStack** obj)
{//printf("? \n");
    MaxStack *tmp;
    tmp=*obj;
    *obj=tmp->next;
   // int x=tmp->value;
    free(tmp);
   // return x;
  // printf("spop ");
}

void maxStackDelete(MaxStack *obj,MaxStack *prs)
{
    MaxStack *tmp;
    tmp=obj;
    prs->next=obj->next;
    free(tmp);
}

int maxStackTop(MaxStack* obj)
{
    return obj->value;
}

void maxStackPush(MaxStack **obj,int value)
{
    MaxStack *newNode;
    newNode=(MaxStack*)malloc(sizeof(MaxStack));
    newNode->value=value;
    newNode->cnt=1;
    newNode->next=*obj;
    *obj=newNode;
   // printf("spush:%d ",value);
}

void maxStackInsert(MaxStack *obj,MaxStack *prs,int value)
{
    MaxStack *newNode;
    newNode=(MaxStack*)malloc(sizeof(MaxStack));
    newNode->value=value;
    newNode->cnt=1;
    newNode->next=obj;
    prs->next=newNode;
   //  printf("sin:%d ",value);
}

bool is_maxstack_empty(MaxStack *obj)
{
    return obj==NULL;
}

MaxQueue* maxQueueCreate() {  //  printf("\nmqcreat");
    MaxQueue *mq;
    mq=(MaxQueue *)malloc(sizeof(MaxQueue));
    mq->front=NULL;
    mq->rear=NULL;
    mq->maxstack=NULL;
    mq->max_value=0;
    return mq;
}

int maxQueueMax_value(MaxQueue* obj) {  //  printf("\nMax_value=%d",obj->max_value);
    if(obj->front==NULL) return -1;
    return obj->max_value;
}

void maxQueuePush_back(MaxQueue* obj, int value) {  //  printf("\npushb");
    MQNode *newNode;
    newNode=(MQNode*)malloc(sizeof(MQNode));
    newNode->value=value;
    newNode->next=NULL;
    if(obj->rear==NULL)
    {
        obj->front=obj->rear=newNode;
    }
    else
    {
        obj->rear->next=newNode;
        obj->rear=newNode;
    }
   // printf("qpush:%d ",value);

    //更新maxstack
    if(value>obj->max_value)
    {
        maxStackPush(&obj->maxstack,value); //printf("msv=%d ",obj->maxstack->value);
        obj->max_value=value;
      //  printf("maxv=%d ",obj->max_value);
    }
    else
    {
        MaxStack *p,*prsp;
        p=obj->maxstack;
        while(p!=NULL && value<p->value)
        {
            prsp=p;
            p=p->next;
        }
        if(p==NULL || value>p->value)
        {
            maxStackInsert(p,prsp,value); //printf("psnext=%d ",prsp->next->value);
        }
        else //(value==p->value)
        {
            p->cnt+=1;
        }
    }
   
}

int maxQueuePop_front(MaxQueue* obj) { // printf("\npopf");
    if(obj->front==NULL)
    {
        return -1;
    }
    MQNode *tmp;
    tmp=obj->front;
    obj->front=obj->front->next;
    if(obj->front==NULL)
    {
        obj->rear=NULL;
    }
    int x=tmp->value;
    free(tmp);
   // printf("qpop:%d ",x);

    MaxStack *p,*prsp;
    p=obj->maxstack;
    
    if(x==obj->max_value)
    {
        
        p->cnt-=1;
        
        if(p->cnt==0)
        {
            maxStackPop(&p);
            obj->maxstack=p;
            if(p==NULL)
            {
                obj->max_value=INT_MIN; //printf("ms=Null ");
            }
            else
            {//printf("msv=%d ",obj->maxstack->value);printf("! ");
                obj->max_value=maxStackTop(p); 
            }
            
            //printf("maxv=%d ",obj->max_value);
        }
    }
    else
    {
        while(x!=p->value && p!=NULL)
        {
           prsp=p;
           p=p->next;
        } 
        p->cnt-=1;
        if(p->cnt==0)
        {
            maxStackDelete(p,prsp);
          //  printf("sdel:%d ",x);
        }        
    }

    return x;
}

void maxQueueFree(MaxQueue* obj) {   //printf("\nfree");
    while(obj->front!=NULL)
    {
        maxQueuePop_front(obj);
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