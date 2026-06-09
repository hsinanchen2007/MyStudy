```
typedef struct {
    int head;
    int tail;
    int size;
    int *queue
} Queue;
#define INIT    (-1)
#define VOS_OK  0
#define VOS_NOK (-1)
Queue *QueueCreate(int k)
{
    Queue *p = (Queue *)malloc(sizeof(Queue));
    p->size = k;
    p->head = INIT;
    p->tail = INIT;
    p->queue = (int *)malloc(sizeof(int) * (k + 1));
    return p;
}
int QueueIsEmpty(Queue *obj)
{
    if (obj->head == INIT) {
        return VOS_OK;
    }
    return VOS_NOK;
}
int QueueIsFull(Queue *obj)
{
    if ((obj->tail + 1) % obj->size == obj->head) {
        return VOS_OK;
    }
    return VOS_NOK;
}
int QueueSize(Queue *obj)
{
    if (VOS_OK == QueueIsEmpty(obj)) {
        return 0;
    }
    if (VOS_OK == QueueIsFull(obj)) {
        return obj->size;
    }
    if (obj->head > obj->tail) {
        return obj->head - obj->tail - 1;
    } else {
        return obj->tail - obj->head + 1;
    }
}
int QueueEn(Queue *obj, int value)
{
    if (VOS_OK == QueueIsFull(obj)) {
        return VOS_NOK;
    }
    if (VOS_OK == QueueIsEmpty(obj)) {
        obj->head = 0;
    }
    obj->tail = (obj->tail + 1) % obj->size;
    obj->queue[obj->tail] = value;
    return VOS_OK;
}
int QueueDe(Queue *obj)
{
    if (VOS_OK == QueueIsEmpty(obj)) {
        return VOS_NOK;
    }
    if (obj->head == obj->tail) {
        obj->head = INIT;
        obj->tail = INIT;
        return VOS_OK;
    }
    obj->head = (obj->head + 1) % obj->size;
    return VOS_OK;
}
int QueueFront(Queue *obj)
{
    if (VOS_OK == QueueIsEmpty(obj)) {
        return -1;
    }
    return obj->queue[obj->head];
}
int QueueRear(Queue *obj)
{
    if (VOS_OK == QueueIsEmpty(obj)) {
        return -1;
    }
    return obj->queue[obj->tail];
}
void QueueFree(Queue *obj)
{
    if (obj == NULL) {
        return;
    }
    if (obj->queue != NULL) {
        free(obj->queue);
        obj->queue = NULL;
    }
    free(obj);
    obj = NULL;
}

int numSquares(int n){
    if (n == 1) return 1;
    //标记
    int *visied = (int *)malloc(sizeof(int) * (n+1));
    memset(visied, 0x0, sizeof(int) * (n+1));
    //初始化队列
    Queue *obj = QueueCreate(n);
    QueueEn(obj, 0);
    visied[0] = 1;
    
    int depth = 0;
    while (QueueIsEmpty != VOS_OK) {
        int qlen = QueueSize(obj);
        depth++;
        for (int i = 0; i < qlen; i++) {
            int tmp = QueueFront(obj);
            QueueDe(obj);
            //添加节点
            for (int k = 1; k*k+tmp <= n; k++) {
                int next = k*k + tmp;
                if (visied[next] == 1) continue;
                if (next == n) goto RETURN; //找到了直接退出
                QueueEn(obj, next);
                visied[next] = 1;
            }            
        }
    }
RETURN:
    QueueFree(obj);
    free(visied);
    return depth;
}
```
