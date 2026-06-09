### 解题思路

代码写的很清晰，广度搜索，关键是找到当前点的下一个扩展点：

### 代码

```c
#define QUEUE_LEN 10000
#define DIR_NUM 4
const int g_row[DIR_NUM] = {-1, 0, 0, 1};
const int g_colum[DIR_NUM] = {0, -1, 1, 0};

typedef struct tagQueueNode{
    int x;
    int y;
}QueueNode;

typedef struct tagQueue{
    QueueNode node[QUEUE_LEN];
    int front;
    int fear;
}Queue;

Queue *QueueCreate()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->fear = 0;
    return queue;
}

int QueueGetSize(Queue *queue)
{
    return (queue->fear + QUEUE_LEN - queue->front) % QUEUE_LEN;
}

int QueueIsFull(Queue *queue)
{
    return ((queue->fear + 1) % QUEUE_LEN == queue->front);
}

int QueueIsEmpty(Queue *queue)
{
    return (queue->front == queue->fear);
}

void QueueEnque(Queue *queue, QueueNode *node)
{
    if (QueueIsFull(queue)) {
        return;
    }

    queue->node[queue->fear] = *node;
    queue->fear = (queue->fear + 1) % QUEUE_LEN;
}

void QueueDeque(Queue *queue, QueueNode *node)
{
    if (QueueIsEmpty(queue)) {
        return;
    }

    *node = queue->node[queue->front];
    queue->front = (queue->front + 1) % QUEUE_LEN;
}

bool PachCheck(int** maze, int x, int y, int row, int colum)
{
    if (x < 0 || x >= row || y < 0 || y >= colum || maze[x][y] == 1) {
        return false;
    }

    return true;
}

void PathFind(int** maze, int row, int colum, QueueNode node, Queue *queue)
{
    int i;
    int x, y;
    QueueNode temp;

    for (i = 0; i < DIR_NUM; i++) {
        x = node.x + g_row[i];
        y = node.y + g_colum[i];

        while (PachCheck(maze, x, y, row, colum)) {
            x += g_row[i];
            y += g_colum[i];
        }

        x -= g_row[i];
        y -= g_colum[i];

        if (maze[x][y] == 0) {
            temp.x = x;
            temp.y = y;
            maze[x][y] = 2;
            QueueEnque(queue, &temp);
        }
    }
}

bool hasPath(int** maze, int mazeSize, int* mazeColSize, int* start, int startSize, int* destination, int destinationSize){
    int i, j, queueSize;
    QueueNode node, temp;
    Queue *queue = QueueCreate();

    node.x = start[0];
    node.y = start[1];
    QueueEnque(queue, &node);
    maze[node.x][node.y] = 2;

    while (!QueueIsEmpty(queue)) {
        queueSize = QueueGetSize(queue);

        for (i = 0; i < queueSize; i++) {
            QueueDeque(queue, &node);

            if (node.x == destination[0] && node.y == destination[1]) {
                return true;
            }
  
            PathFind(maze, mazeSize, *mazeColSize, node, queue);
        }
    }

    return false;
}
```