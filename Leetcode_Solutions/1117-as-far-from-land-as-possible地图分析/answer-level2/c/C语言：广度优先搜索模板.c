```
#define QUEUE_LENTH 10000
typedef struct {
    int x;
    int y;
    int val;
    int step;
} Node;

typedef struct {
    Node* data;
    int head;
    int tail;
    int capacity;
} CircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
CircularQueue* CircularQueueCreate(int k)
{
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    if (queue == NULL) {
        return NULL;
    }
    queue->data = (Node*)malloc(sizeof(Node) * (k + 1));
    memset(queue->data, 0, sizeof(Node) * (k + 1));
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = k + 1;

    return queue;
}

/** Checks whether the circular queue is empty or not. */
bool CircularQueueIsEmpty(CircularQueue* obj)
{
    if (obj->head == obj->tail) {
        return true;
    }

    return false;
}

/** Checks whether the circular queue is full or not. */
bool CircularQueueIsFull(CircularQueue* obj)
{
    if ((obj->tail + 1) % obj->capacity == obj->head) {
        return true;
    }

    return false;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool CircularQueueEnQueue(CircularQueue* obj, Node value)
{
    if (CircularQueueIsFull(obj) == true) {
        return false;
    }

    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool CircularQueueDeQueue(CircularQueue* obj)
{
    if (CircularQueueIsEmpty(obj) == true) {
        return false;
    }

    obj->head = (obj->head + 1) % obj->capacity;
    return true;
}

/** Get the front item from the queue. */
Node CircularQueueFront(CircularQueue* obj)
{
    return obj->data[obj->head];
}

/** Get the last item from the queue. */
Node CircularQueueRear(CircularQueue* obj)
{
    return obj->data[(obj->tail - 1 + obj->capacity) % obj->capacity];
}

int CircularQueueSize(CircularQueue* obj)
{
    if (obj->head > obj->tail) {
        return obj->tail + obj->capacity - obj->head;
    }
    return obj->tail - obj->head;
}

void CircularQueueFree(CircularQueue* obj)
{
    if (obj != NULL) {
        free(obj->data);
        obj->data = NULL;
        free(obj);
        obj = NULL;
    }
}

CircularQueue* g_queue;

struct Direction
{
    int x;
    int y;
};

#define FOUR_DIRECTION  4
struct Direction DIR[FOUR_DIRECTION] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

bool isValidPos(int x, int y, int rowSize, int colSize)
{
    if (x >= 0 && x < rowSize && y >= 0 && y < colSize) {
        return true;
    }

    return false;
}

int maxDistance(int** grid, int gridSize, int* gridColSize)
{
    int ret = 0;
    g_queue = CircularQueueCreate(QUEUE_LENTH);

    /*遍历整个地图，求解每一个海洋区域的曼哈顿距离，保留最小值*/
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < *gridColSize; y++) {
            /* 所有陆地入队列 */
            if (grid[x][y] == 1) {
                Node enNode;
                enNode.x = x;
                enNode.y = y;
                CircularQueueEnQueue(g_queue, enNode);
            }
        }
    }

    int queueSize = CircularQueueSize(g_queue);
    if (queueSize == 0 || queueSize == gridSize * (*gridColSize)) {
        return -1;
    }

    int steps = 0;
    while (CircularQueueIsEmpty(g_queue) == false) {
        /* 深度+1 */
        steps++;
        int queueSize = CircularQueueSize(g_queue);
        for (int i = 0; i < queueSize; i++) {
            Node deNode;
            deNode = CircularQueueFront(g_queue);
            CircularQueueDeQueue(g_queue);

            /* 需要干几个事情：
            1、遍历和陆地相连接的海洋（四个方向），每遍历到一个，对应的海洋清成陆地，step采用当前step赋值
            2、将新的陆地（海洋变的）纳入到队列，遍历，直到队列为空
                */
            for (int i = 0; i < FOUR_DIRECTION; i++) {
                int x = deNode.x + DIR[i].x;
                int y = deNode.y + DIR[i].y;

                if (isValidPos(x, y, gridSize, *gridColSize) && grid[x][y] == 0) {
                    grid[x][y] = 1;
                    Node enNode;
                    enNode.x = deNode.x + DIR[i].x;
                    enNode.y = deNode.y + DIR[i].y;
                    CircularQueueEnQueue(g_queue, enNode);
                }
            }
        }
    }

    CircularQueueFree(g_queue);
    return steps - 1;
}
```
