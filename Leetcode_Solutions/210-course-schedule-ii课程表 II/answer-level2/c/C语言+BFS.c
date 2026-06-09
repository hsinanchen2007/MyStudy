```
#define QUEUE_LENTH 10000
typedef struct {
    int val;
} Node;

typedef struct {
    Node *data;
    int head;
    int tail;
    int capacity;
} CircularQueue;

/* * Initialize your data structure here. Set the size of the queue to be k. */
CircularQueue *CircularQueueCreate(int k)
{
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    if (queue == NULL) {
        return NULL;
    }
    queue->data = (Node *)malloc(sizeof(Node) * (k + 1));
    memset(queue->data, 0, sizeof(Node) * (k + 1));
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = k + 1;

    return queue;
}

/* * Checks whether the circular queue is empty or not. */
bool CircularQueueIsEmpty(CircularQueue *obj)
{
    if (obj->head == obj->tail) {
        return true;
    }

    return false;
}

/* * Checks whether the circular queue is full or not. */
bool CircularQueueIsFull(CircularQueue *obj)
{
    if ((obj->tail + 1) % obj->capacity == obj->head) {
        return true;
    }

    return false;
}

/* * Insert an element into the circular queue. Return true if the operation is successful. */
bool CircularQueueEnQueue(CircularQueue *obj, Node value)
{
    if (CircularQueueIsFull(obj) == true) {
        return false;
    }

    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    return true;
}

/* * Delete an element from the circular queue. Return true if the operation is successful. */
bool CircularQueueDeQueue(CircularQueue *obj)
{
    if (CircularQueueIsEmpty(obj) == true) {
        return false;
    }

    obj->head = (obj->head + 1) % obj->capacity;
    return true;
}

/* * Get the front item from the queue. */
Node *CircularQueueFront(CircularQueue *obj)
{
    if (CircularQueueIsEmpty(obj) == true) {
        return NULL;
    }

    return &(obj->data[obj->head]);
}

/* * Get the last item from the queue. */
Node *CircularQueueRear(CircularQueue *obj)
{
    if (CircularQueueIsEmpty(obj) == true) {
        return NULL;
    }
    return &(obj->data[(obj->tail - 1 + obj->capacity) % obj->capacity]);
}

int CircularQueueSize(CircularQueue *obj)
{
    if (obj->head > obj->tail) {
        return obj->tail + obj->capacity - obj->head;
    }
    return obj->tail - obj->head;
}

void CircularQueueFree(CircularQueue *obj)
{
    if (obj != NULL) {
        free(obj->data);
        obj->data = NULL;
        free(obj);
        obj = NULL;
    }
}

CircularQueue *g_queue;

void BFS(int **prerequisites, int prerequisitesSize, int *degree, int *ret, int *returnSize)
{
    *returnSize = 0;
    while (CircularQueueIsEmpty(g_queue) == false) {
        int queueSize = CircularQueueSize(g_queue);
        for (int i = 0; i < queueSize; i++) {
            Node *deNode = CircularQueueFront(g_queue);
            CircularQueueDeQueue(g_queue);
            ret[(*returnSize)++] = deNode->val;

            for (int j = 0; j < prerequisitesSize; j++) {
                if (deNode->val == prerequisites[j][1]) {
                    degree[prerequisites[j][0]]--;
                    if (degree[prerequisites[j][0]] == 0) {
                        Node enNode;
                        enNode.val = prerequisites[j][0];
                        CircularQueueEnQueue(g_queue, enNode);
                    }
                }
            }
        }
    }

    return;
}

int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize)
{
    if (numCourses == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int *degree = (int *)malloc(sizeof(int) * numCourses);
    memset(degree, 0, sizeof(int) * numCourses);
    g_queue = CircularQueueCreate(QUEUE_LENTH);

    int *ret = (int *)malloc(sizeof(int) * numCourses);
    memset(ret, 0, sizeof(int) * numCourses);

    for (int i = 0; i < prerequisitesSize; i++) {
        int idx = prerequisites[i][0];
        degree[idx] = degree[idx] + 1;
    }

    /* 初始化BFS，取度数为0的放入队列 */
    for (int i = 0; i < numCourses; i++) {
        if (degree[i] == 0) {
            Node enNode;
            enNode.val = i;
            CircularQueueEnQueue(g_queue, enNode);
        }
    }

    BFS(prerequisites, prerequisitesSize, degree, ret, returnSize);

    if (*returnSize != numCourses) {
        *returnSize = 0;
    }

    CircularQueueFree(g_queue);
    free(degree);

    return ret;
}
```
