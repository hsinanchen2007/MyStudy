```
#define KEY_LENTH 4
#define QUEUE_LENTH 10000

typedef struct {
    char key[KEY_LENTH + 1];
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
int g_visited[QUEUE_LENTH];

int Str2Int(char* s, int len)
{
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret = ret * 10;
        ret = ret + s[i] - '0';
    }

    return ret;
}

bool IsTarget(char* this, char* target)
{
    return !strcmp(this, target);
}

void InitVisitDead(char** deadends, int deadendsSize)
{
    for (int i = 0; i < deadendsSize; i++) {
        int index = Str2Int(deadends[i], KEY_LENTH);
        g_visited[index] = 1;
    }
}

bool IsInDead(char* this, char** deadends, int deadendsSize)
{
    for (int i = 0; i < deadendsSize; i++) {
        if (IsTarget(this, deadends[i]) == true) {
            return true;
        }
    }

    return false;
}

void GetNextNodeEnQueue(CircularQueue* obj, char* this, char** deadends, int deadendsSize)
{
    /* 基于当前数字产生新的8位数字（各个位置前后旋转） */
    for (int i = 0; i < KEY_LENTH; i++) {
        for (int step = -1; step <= 1; step += 2) {
            char nextCode[KEY_LENTH + 1];
            strcpy(nextCode, this);
            nextCode[KEY_LENTH] = '\0';
            nextCode[i] = (nextCode[i] - '0' + step + 10) % 10 + '0';
            int index = Str2Int(nextCode, KEY_LENTH);

            if (IsInDead(nextCode, deadends, deadendsSize) == true || g_visited[index] == 1) {
                continue;
            }

            Node enNode;
            strcpy(enNode.key, nextCode);
            CircularQueueEnQueue(g_queue, enNode);
            g_visited[index] = 1;
        }
    }
}

int openLock(char** deadends, int deadendsSize, char* target)
{
    int steps = 0;

    if (IsInDead("0000", deadends, deadendsSize) == true) {
        return -1;
    }

    g_queue = CircularQueueCreate(QUEUE_LENTH);
    memset(g_visited, 0, QUEUE_LENTH * sizeof(int));
    InitVisitDead(deadends, deadendsSize);

    /* 将起点"0000"入队列 */
    Node enNode;
    strcpy(enNode.key, "0000");
    CircularQueueEnQueue(g_queue, enNode);
    g_visited[0] = 1;

    /* 遍历队列 */
    while (CircularQueueIsEmpty(g_queue) == false) {
        /* 旋转次数+1 */
        steps++;

        /* 遍历已在队列中的节点 */
        int queueSize = CircularQueueSize(g_queue);
        for (int i = 0; i < queueSize; i++) {
            Node deNode;
            /* 获取当前队列头 */
            deNode = CircularQueueFront(g_queue);
            CircularQueueDeQueue(g_queue);

            /* 获取当前值的邻接值，判断是否在黑名单中，如不在，入队列 */
            /* 基于当前数字产生新的8位数字（各个位置前后旋转） */
            for (int i = 0; i < KEY_LENTH; i++) {
                for (int step = -1; step <= 1; step += 2) {
                    char nextCode[KEY_LENTH + 1];
                    strcpy(nextCode, deNode.key);
                    nextCode[KEY_LENTH] = '\0';
                    nextCode[i] = (nextCode[i] - '0' + step + 10) % 10 + '0';
                    int index = Str2Int(nextCode, KEY_LENTH);

                    if (IsTarget(nextCode, target) == true) {
                        return steps;
                    }

                    if (g_visited[index] == 1) {
                        continue;
                    }

                    Node enNode;
                    strcpy(enNode.key, nextCode);
                    CircularQueueEnQueue(g_queue, enNode);
                    g_visited[index] = 1;
                }
            }
        }
    }

    CircularQueueFree(g_queue);

    return -1;
}
```
