```c
#define QUEUE_SIZE 10005

typedef struct QueueNode_t {
    int x;
    int y;
    int val;
} QueueNode;

typedef struct Queue_t {
    int front;
    int rear;
    int size;
    QueueNode arr[QUEUE_SIZE];
} Queue;

static inline void QueueClear(Queue* queue)
{
    memset(queue, 0, sizeof(Queue));
}

static inline void QueueInit(Queue* queue)
{
    QueueClear(queue);
}

static inline int QueueSize(Queue* queue)
{
    return queue->size;
}

static inline bool QueueIsEmpty(Queue* queue)
{
    return queue->size == 0;
}

static inline bool QueueIsFull(Queue* queue)
{
    return queue->size == QUEUE_SIZE;
}

static inline void QueuePush(Queue* queue, QueueNode* node)
{
    if (QueueIsFull(queue)) {
        exit(1);
    }
    queue->arr[queue->rear] = *node;
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    ++queue->size;
}

static inline QueueNode* QueuePop(Queue* queue)
{
    if (QueueIsEmpty(queue)) {
        exit(1);
    }
    QueueNode* ret = &queue->arr[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    --queue->size;
    return ret;
}

static inline QueueNode* QueueGetTop(Queue* queue)
{
    if (QueueIsEmpty(queue)) {
        exit(1);
    }
    return &queue->arr[queue->front];
}

Queue g_queue;
#define DIR_ROW 4
#define DIR_COL 2
const int g_dir[DIR_ROW][DIR_COL] = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1}
};
#define SIZE 105
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
bool g_vis[SIZE][SIZE];
bool g_flag = false;

int Bfs(int** grid, int x, int y, int row, int col)
{
    QueueInit(&g_queue);
    memset(g_vis, 0, sizeof(g_vis));
    QueueNode node = {x, y, 0};
    QueueNode* top = NULL;
    QueuePush(&g_queue, &node);
    int i;
    int count = 0;
    while (!QueueIsEmpty(&g_queue)) {
        ++count;
        top = QueuePop(&g_queue);
        if (top->x >= row || top->y >= col || top->x < 0 || top->y < 0 || g_vis[top->x][top->y]) {
            continue;
        }
        g_vis[top->x][top->y] = true;
        
        if (grid[top->x][top->y]) {
            return top->val;
        }
        for (i = 0; i < DIR_ROW; ++i) {
            node.x = top->x + g_dir[i][0];
            node.y = top->y + g_dir[i][1];
            node.val = top->val + 1;
            QueuePush(&g_queue, &node);
        }
    }
    if (count == row * row) {
        g_flag = true;
    }
    return -1;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || gridColSize[0] == 0) {
        return -1;
    }
    g_flag = false;
    int ret = -1;
    int i, j;
    for (i = 0; i < gridSize; ++i) {
        for (j = 0; j < gridColSize[i]; ++j) {
            if (!grid[i][j]) {
                ret = MAX(ret, Bfs(grid, i, j, gridSize, gridColSize[i]));
                if (ret == 2 * gridSize - 2) {
                    return ret;
                }
                if (g_flag) {
                    return -1;
                }
            }
        }
    }
    return ret;
}

```