这个题目具有一定的识别度，我首先相当的是通过递归，原因是因为到达(m,n)，只能通过(m-1, n)或者(m, n-1)两个位置过来，这个是矩阵式搜索的典型套路。(m, n)是终点，只可能存在两条路劲，但对于任意的普通点来说，可能存在4个方向。即从上下左右分别过来。

参照动态规划的思路：首先定义：DP[i, j, K]是到达位置(i, j)消除障碍物K次后的路劲。
那么DP[i, j, K]，只可能是4个方向的某个方向的结果，以左边为例进行解释：
    如果 grid[i, j - 1] = 1，那么DP[i, j, k] 可能是 DP[i, j - 1, K - 1] + 1;
    如果 grid[i, j - 1] = 0，那么DP[i, j, k] 可能是 DP[i, j - 1, K] + 1;
    即： DP[i, j, k] = DP[i, j - 1, K - grid[i][j - 1]] + 1
最终的结果实际上就是4个方向的最小值。
    DP[i, j, k] = min(DP[i, j - 1, K - grid[i][j - 1]] + 1, DP[i, j + 1, k - grid[i][j + 1]],
                      DP[i - 1, j, K - grid[i - 1][j]] + 1, DP[i + 1, j, k - grid[i + 1][j]])
    其中需要保证k >= 0。

由于是最短路径，经过的节点肯定只会经过一次，因此需要保持一个状态。因此可以尝试通过DFS的方式遍历，找到目标点之后记录路径，然后根据回溯的方式找到所有可能的结果，只记录最小的结果。

DFS + 回溯：
```
int g_MaxSteps = INT_MAX;

int CheckParam(int** grid, int gridSize, int* gridColSize, int k)
{
    if (grid == NULL || gridSize <= 0 || gridColSize == NULL || k < 0) {
        return -1;
    }

    if (gridColSize[0] <= 0) {
        return -1;
    }

    return 0;
}

void DFS(int **grid, int gridSize, int *gridColSize, int k, int i, int j, char *mark, int step)
{
    if (step > g_MaxSteps) { //举例超过找到的最合适的值，返回
        return;
    }
    if (i == gridSize - 1 && j == gridColSize[0] - 1) { //找到目标
        if (step < g_MaxSteps) {
            g_MaxSteps = step; //记录最短的路劲
        }
        
        return;
    }

    if (mark[i*gridColSize[0] + j] == 1) {
        return;
    }

    int dirctions[4][2] = {
        { 1, 0 },
        { 0, 1 },
        { -1, 0 },
        { 0, -1 }
    };

    mark[i * gridColSize[0] + j] = 1; //记录当前值被访问
    for (int s = 0; s < 4; ++s) {
        int newX = dirctions[s][0] + i;
        int newY = dirctions[s][1] + j;

        if (newX < 0 || newX >= gridSize || newY < 0 || newY >= gridColSize[0]) {
            continue;
        }

        if (grid[newX][newY] == 1 && k <= 0) { //如果障碍物还有，则该路劲不满足
            continue;
        }

        if (mark[newX*gridColSize[0] + newY] == 0) { //没有访问过，则继续深度搜索
            DFS(grid, gridSize, gridColSize, k - grid[newX][newY], newX, newY, mark, step + 1);
        }
    }

    mark[i * gridColSize[0] + j] = 0; //回溯处理
}

int shortestPath(int** grid, int gridSize, int* gridColSize, int k)
{
    if (CheckParam(grid, gridSize, gridColSize, k)) {
        return -1;
    }

    g_MaxSteps = INT_MAX;
    char *mark = (char *)malloc(sizeof(char) * gridColSize[0] * gridSize);
    memset(mark, 0, sizeof(char) * gridColSize[0] * gridSize);
    if (k >= gridSize + gridColSize[0] - 3) {
        return gridSize + gridColSize[0] - 2; //该条件是当K足够大时，就是按照最短路径的方式返回，减少递归的次数，不然可能超时。
    }

    DFS(grid, gridSize, gridColSize, k, 0, 0, mark, 0);
    if (g_MaxSteps == INT_MAX) {
        return -1;
    }

    return g_MaxSteps;
}
```

其实在路劲的最短方面最合适的算法是BFS，因为BFS的搜索最先找到的肯定是最短的路劲。因此可以尝试通过BFS进行一次搜索。但是有个问题，因为BFS是广度搜索，对于一个节点而言，可能是移出障碍之前访问过，也可能是移出障碍之后再访问，一个简单的已访问标记无法表示该节点是否已经访问过。

比如[[0 1 0 0], [0 0 0 1]]的组合，要达到(0, 2)节点，在推开障碍物时可以通过(0, 0)--> (0, 1)--> (0, 2)--> (0, 3)，不推开障碍物的情况下只能通过(0, 0)-->(1, 0)-->(1, 1)--> (1, 2)-->(0, 2)--> (0, 3)。但如果用同一个mark[0][2]是否访问到时就会冲突。因此为了区分，将推开障碍物作为一个新的状态。如果需要推开超过一定数量的障碍物，那么没推开一个障碍物就要保存一次已经访问过得节点信息，因此定义mark[k][m][n]。其中k是指推开障碍物的次数，表示推开k个障碍物之后，这一轮搜索中是否被访问过。因此出现了一个状态是从二维到三维的转变。
```
#define DIRECTIONS      4
#define DIRECTIONSTEP   2

const int dirctions[DIRECTIONS][DIRECTIONSTEP] = {
    { 1, 0 },
    { 0, 1 },
    { -1, 0 },
    { 0, -1 }
};

int CheckParam(int** grid, int gridSize, int* gridColSize, int k)
{
    if (grid == NULL || gridSize <= 0 || gridColSize == NULL || k < 0) {
        return -1;
    }

    if (gridColSize[0] <= 0) {
        return -1;
    }

    return 0;
}

typedef struct {
    int x;
    int y;
    int k;
    int step;
} Enode_t;

typedef Enode_t* Item;

typedef struct {
    int max;
    int cnt;
    int head;
    int tail;
    Item *queue;
} Queue_t;

Queue_t *QueueInit(int max)
{
    Queue_t *queue = (Queue_t *)malloc(sizeof(Queue_t));
    queue->queue = (Item *)malloc(sizeof(Item) * max);
    memset(queue->queue, 0, sizeof(sizeof(Item) * max));
    queue->max = max;
    queue->tail = 0;
    queue->head = 0;
    queue->cnt  = 0;

    return queue;
}

void QueuePush(Queue_t *queue, Item item)
{
    if (queue->cnt == queue->max) {
        return;
    }

    if (queue->tail == queue->max) {
        for (int i = queue->head; i < queue->tail; ++i) {
            queue->queue[i - queue->head] = queue->queue[i];
        }
        
        queue->tail -= queue->head;
        queue->head = 0;
    }

    queue->queue[queue->tail++] = item;
    queue->cnt++;
}

Item QueuePop(Queue_t *queue)
{
    queue->cnt--;
    return queue->queue[queue->head++];
}

int IsQueueEmpty(Queue_t *queue)
{
    return queue->cnt == 0;
}

void QueueDestory(Queue_t *queue)
{
    while (!IsQueueEmpty(queue)) {
        free(QueuePop(queue));
    }

    free(queue->queue);
    free(queue);
}

Item CreateItem(int i, int j, int k, int step)
{
    Item node = (Item)malloc(sizeof(Enode_t));
    node->x = i;
    node->y = j;
    node->k = k;
    node->step = step;

    return node;
}

int BFS(int** grid, int gridSize, int* gridColSize, int k)
{
    int m = gridSize - 1;
    int n = gridColSize[0] - 1;

    char **mark = (char **)malloc(sizeof(char *) * (k + 1)); //mark[k + 1][m][n]
    memset(mark, 0, sizeof(char *) * (k + 1));
    for (int i = 0; i < k+1; ++i) {
        mark[i] = (char *)malloc(sizeof(char) * gridColSize[0] * gridSize);
        memset(mark[i], 0, sizeof(char) * gridColSize[0] * gridSize);
    }

    Queue_t *queue = QueueInit(1024);
    QueuePush(queue, CreateItem(0, 0, 0, 0));
    mark[0][0] = 1; //标识已经访问

    while (!IsQueueEmpty(queue)) {
        Item item = QueuePop(queue);
        if (item->x == m && item->y == n) {
            return item->step;
        }

        for (int s = 0; s < DIRECTIONS; ++s) {
            int newX = dirctions[s][0] + item->x;
            int newY = dirctions[s][1] + item->y;

            if (newX < 0 || newX > m || newY < 0 || newY > n) {
                continue;
            }

            if (grid[newX][newY] == 1 && item->k >= k) { //障碍物太多，无法到达
                continue;
            }
            if (mark[item->k][newX * gridColSize[0] + newY] == 0) { //如果推开k个之后没有访问过，尝试访问
                QueuePush(queue, CreateItem(newX, newY, item->k + grid[newX][newY], item->step + 1));
                mark[item->k][newX * gridColSize[0] + newY] = 1;
            }
        }
        free(item);
    }

    return -1;
}

int shortestPath(int** grid, int gridSize, int* gridColSize, int k)
{
    if (CheckParam(grid, gridSize, gridColSize, k)) {
        return -1;
    }

    if (k > gridSize + gridColSize[0] - 3) {
        return gridSize + gridColSize[0] - 2; //最短距离满足要求
    }

    return BFS(grid, gridSize, gridColSize, k);
}
```
