### 解题思路
原先用头插法的思想是错误的，不符合队列的性质，所以就导致了返回最大值的函数O(n)

### 代码

```c
typedef struct MaxQueueNode{
    int val;
    int presentMaxValue;
    struct MaxQueueNode *next;
}MaxQueueNode;

typedef struct MaxQueue{
    MaxQueueNode *front;
    MaxQueueNode *rear;
    int maxVal;
} MaxQueue;//作为头节点


MaxQueue* maxQueueCreate() {
    MaxQueue *queue = (MaxQueue * ) malloc ( sizeof(MaxQueue));
    queue->maxVal = -1;
    queue->rear = queue->front = NULL;
    return queue;
}

int maxQueueMax_value(MaxQueue* obj) {
    if(obj->front == NULL) return -1;
    MaxQueueNode* p = obj->front;
    int max = p->val;
    while(p){
        if( p->val > max)
            max = p->val;
        p = p->next;
    }
    return max;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    MaxQueueNode *p = (MaxQueueNode *) malloc ( sizeof( MaxQueueNode));
    p->val = value;
    p->next = NULL;
    if( obj->front == NULL){
        obj->front = p;
        obj->rear = p;
    }
    else{
        obj->rear->next = p;
        obj->rear = p;
    }
}  

int maxQueuePop_front(MaxQueue* obj) {
    if(obj->front == NULL) return -1;
    MaxQueueNode* p = obj->front;
    int retVal = p->val;
    obj->front = obj->front->next;
    p->next = NULL;
    free(p);
    return retVal;
}

void maxQueueFree(MaxQueue* obj) {
    MaxQueueNode *p = obj->front;
    while(p){
        obj->front = obj->front->next;
        p->next = NULL;
        free(p);
        p=obj->front;
    }
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