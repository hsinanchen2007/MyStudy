### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int *data;
    int max_value;
    int head;
    int tail;
    int capacity;
} MaxQueue;

#define MAX_QUEUE_SIZE  10001
MaxQueue* maxQueueCreate() {
    MaxQueue *queue = (MaxQueue *)malloc(sizeof(MaxQueue));
    memset(queue, 0, sizeof(MaxQueue));
    queue->data = (int *)malloc(sizeof(int) * MAX_QUEUE_SIZE);
    memset(queue->data, 0, sizeof(int) * MAX_QUEUE_SIZE);
    queue->head = 0;
    queue->tail = 0;
    queue->max_value = -1;
    queue->capacity = MAX_QUEUE_SIZE;

    return queue;
}

bool isQueueFull(MaxQueue* obj)
{
    if ((obj->tail + 1) % obj->capacity == obj->head) {
        return true;
    }

    return false;
}

bool isQueueEmpty(MaxQueue* obj)
{
    return (obj->head == obj->tail);
}

int maxQueueMax_value(MaxQueue* obj) {
    return obj->max_value;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    if (isQueueFull(obj) == true) {
        return;
    }

    obj->data[obj->tail] = value;
    if (obj->max_value < value) {
        obj->max_value = value;
    }
    obj->tail = (obj->tail + 1) % obj->capacity;

    return;
}

int maxQueuePop_front(MaxQueue* obj) {
    if (isQueueEmpty(obj) == true) {
        obj->max_value = -1;
        return -1;
    }

    int ret = obj->data[obj->head];
    obj->head = (obj->head + 1) % obj->capacity;
    if (isQueueEmpty(obj) == true) {
        obj->max_value = -1;
        return ret;
    }

    obj->max_value = -1;
    for (int i = obj->head; (i + obj->capacity) % obj->capacity <= obj->tail; i++) {
        if (obj->data[i] > obj->max_value) {
            obj->max_value = obj->data[i];
        }
    }
    return ret;
}

void maxQueueFree(MaxQueue* obj) {
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
    return;
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