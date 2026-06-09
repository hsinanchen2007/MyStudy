![image.png](https://pic.leetcode-cn.com/5fff49df696c1e0e62cfefc8c9d79947c9dda1423bdff3d7f5c3ff723ad6032b-image.png)
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int *indegrees = (int *)calloc(numCourses+1, sizeof(int));
    int m = prerequisitesSize;
    int *rst = (int*)calloc(numCourses, sizeof(int));
    *returnSize = 0;
    //入度统计
    for (int i = 0; i < m; i++) {
        int inde = prerequisites[i][0];
        indegrees[inde]++;
    }
    //入度为0的入队列
    Queue *obj = QueueCreate(numCourses);
    for (int i = 0; i < numCourses; i++) {
        if (indegrees[i] == 0) {
            //printf("indegrees[%d]:%d\n",i,indegrees[i]);
            QueueEn(obj, i);
        }
    }
    //处理队列
    while (QueueIsEmpty(obj) != VOS_OK) {
        int pre = QueueFront(obj);
        numCourses--;
        QueueDe(obj);
        rst[*returnSize] = pre;
        (*returnSize)++;
        for (int i = 0; i < m; i++) {
            if (pre == prerequisites[i][1]) {
                if (--indegrees[prerequisites[i][0]] == 0) {
                    QueueEn(obj, prerequisites[i][0]);
                }
            }
        }
    }
    QueueFree(obj);
    free(indegrees);
    if (numCourses != 0) {
        *returnSize = 0;
    }
    return rst;
}
```
