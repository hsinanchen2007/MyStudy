### 解题思路
此处撰写解题思路

### 代码

```c
BFS, 尝试从原点开始，遍历所有能走到终点的可能性，同时记录到达每个点的花费。

#define MAX_NUMS 100000

typedef struct Node_ {
    int x;
    int y;
    int cost;
}Node;

typedef struct Queue_ {
    Node arr[MAX_NUMS];
    int front;
    int rear;
}Queue;

void QueueInit(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
}

bool Full(Queue* queue)
{
    if ((queue->rear + 1) % MAX_NUMS == queue->front) {
        return true;
    }
    return false;
}

bool Empty(Queue* queue)
{
    return queue->front == queue->rear;
}

void QueuePush(Queue* queue, Node node)
{
    if (!Full(queue)) {
        queue->arr[queue->rear] = node;
        queue->rear = (queue->rear + 1) % MAX_NUMS;
    }
}

void QueuePop(Queue* queue)
{
    if (!Empty(queue)) {
        queue->front = (queue->front + 1) % MAX_NUMS;
    }
}

void QueueClear(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
}

Node QueueTop(Queue* queue)
{
    return queue->arr[queue->front];
}

int QueueLength(Queue que)
{
    return (que.rear - que.front + MAX_NUMS) % MAX_NUMS;
}

bool insquare(int x, int y, int ASize, int aCol)
{
    if (x >= ASize || x < 0 || y >= aCol || y < 0) {
         return false;
    }
    return true;
}

#define MAXROW 100
#define MAXCOL 100

int g_pass[MAXROW][MAXROW] = {0};
void InitPass()
{
    for (int i = 0; i < MAXROW; i++) {
        for (int j = 0; j < MAXCOL; j++) {
            g_pass[i][j] = INT_MAX;
        }
    }
}

void ProCurPoint(int x, int y, int cost, int** grid, int gridSize, int gridCol, Queue *q, int *res, int flag)
{
    if (!insquare(x, y, gridSize, gridCol)) {
        return;
    }
    
    //很重要的剪枝，如果这条路的花费已经超过之前到达该点的花费，就停止这条路径的搜索
    int cur = flag ? cost : cost + 1;
    if (cur >= g_pass[x][y]) {
        return;
    }

    g_pass[x][y] = cur;
    if ((x == gridSize - 1) && (y == gridCol - 1)) {
        *res = *res < cur ? *res : cur;
    } else {
        Node temp = {x, y, cur};
        QueuePush(q, temp);
    }
}

int minCost(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 1 || gridSize == 0) {
        return 0;
    } 
    InitPass();
    Queue q;
    QueueInit(&q);
    int gridCol = *gridColSize;
    Node start = {0, 0, 0};
    QueuePush(&q, start);
    g_pass[0][0] = 0;
    int res = INT_MAX;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!Empty(&q)) {
        int curLen = QueueLength(q);
        for (int i = 0; i < curLen; i++) {
            Node first = QueueTop(&q);
            QueuePop(&q);
            for (int i = 0; i < 4; i++) {
                int flag;
                if (i + 1== grid[first.x][first.y]) {
                    flag = 1;
                } else{
                    flag = 0;
                }
                ProCurPoint(first.x + dir[i][0], first.y + dir[i][1], first.cost, grid, gridSize, gridCol, &q, &res, flag);
            }
        }
    }
    return res;
}
```