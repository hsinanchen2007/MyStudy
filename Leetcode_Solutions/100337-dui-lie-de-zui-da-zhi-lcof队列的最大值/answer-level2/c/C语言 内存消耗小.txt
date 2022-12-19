### 解题思路
效率稍低，原因是将max记在了队列本身，而且只有一个最大值
在pop和push操作需要更新max值时，采用了O(N)性能的算法

![image.png](https://pic.leetcode-cn.com/51a24029c3c3514ab54b38a1b28be4ebfa9d2cc9e7e2f92d37a64abccffdf187-image.png)

### 代码

```c
#define MY_BASE_SIZE 10000

typedef struct MyQ {
    int *queue;
    int size;
    int head;
    int tail;
    int cnt;
    int max;
} MyQ;

typedef struct {
    MyQ dq;
} MaxQueue;

void qFree(MyQ *q)
{
    if (q->queue != NULL) {
        free(q->queue);
        q->queue = NULL;
    }
    return;
}
int qInit(MyQ *q)
{
    q->size = MY_BASE_SIZE;
    q->queue = (int*)calloc(q->size, sizeof(int));
    if (q->queue == NULL) {
        return -1;
    }
    q->head = q->tail = 0;
    q->cnt = 0;
    q->max = -1;
    return 0;
}
int qPush(MyQ *q, int item)
{
    if (q->cnt == q->size) {
        printf("buffer is not enough\n");
        return -1;
    }
    q->queue[q->tail] = item;
    q->tail = (q->tail + 1) % q->size;
    q->cnt++;
    return 0; 
}
int qPop(MyQ *q)
{
    int item;
    if (q->cnt == 0) {
        return -1;
    }
    item = q->queue[q->head];
    q->head = (q->head + 1) % q->size;
    q->cnt--;
    return item;
}
int qPeekTail(MyQ *q)
{
    if (q->cnt == 0) {
        return -1;
    }
    return q->queue[(q->head + q->cnt - 1) % q->size];
}
void qMaxUpdate(MyQ *q)
{
    int i, cur;
    q->max = -1;
    if (q->cnt == 0) {
        return;
    }
    
    for (i = 0; i < q->cnt; i++) {
        cur = q->queue[(q->head + i) % q->size];
        q->max = q->max > cur ? q->max : cur;
    }
    return;
}
MaxQueue* maxQueueCreate() {
    int ret;
    MaxQueue *q = NULL;
    q = (MaxQueue*)calloc(1, sizeof(MaxQueue));
    if (q == NULL) {
        return NULL;
    }
    ret = qInit(&q->dq);
    if (ret != 0) {
        qFree(&q->dq);
        free(q);
        return NULL;
    }
    return q;
}

int maxQueueMax_value(MaxQueue* obj) {
    return obj->dq.max;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    int max;
    int ret;
    obj->dq.max = obj->dq.max > value ? obj->dq.max : value;
    ret = qPush(&obj->dq, value);
    if (ret != 0) {
        printf("maxQueuePush_back error\n");
    }
    return;
}

int maxQueuePop_front(MaxQueue* obj) {
    int item;
    item = qPop(&obj->dq);
    if (item == -1 || item == obj->dq.max) {
        qMaxUpdate(&obj->dq);
    }
    return item;
}

void maxQueueFree(MaxQueue* obj) {
    qFree(&obj->dq);
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