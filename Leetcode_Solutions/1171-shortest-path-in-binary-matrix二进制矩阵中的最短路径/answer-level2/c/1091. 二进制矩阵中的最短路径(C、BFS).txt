### 解题思路
BFS:
    逐点遍历，更新到每个点的最短路径长度。最后输出右下角点的最短路径长度即可。

    剪枝：
    1、到此节点的长度超过最短长度，则剪枝。
    2、上个节点1步范围内的节点，没必要重复遍历。(可选，优化效果不明显)

    代码逻辑：
    从第一个节点开始，入队。
    出队一个节点，检查周围1步范围内为0的节点，计算到这些节点的路径长度。如果满足剪枝条件，则不必入队。否则入队。

    与树不同的是，每个节点有可能多次访问，所以不能用入队的节点保存路径信息。需要单独开辟一块空间，为各个节点保存路径信息。

### 代码
1. 使用队列实现BFS

```c


typedef struct tagPOS_S {
    int deep;
    int band;
    int pathLen;
    int lastDeep;
    int lastBand;
}POS_S;

typedef struct tagQUEUE_HEAD_S {
    POS_S *queue;
    int head;
    int tail;
    int queueLen;
}QUEUE_HEAD_S;


/* 
    需要保存到每个节点的最短路径长度
*/

typedef struct tagGRID_NODE_INFO_S{
    int lestLen;
    int block;
}GRID_NODE_INFO_S;


/* 
    使用循环双向链表实现队列
    retval: 返回一个节点的地址，其中它的next为队列头，priv为队列尾
*/
QUEUE_HEAD_S *QueueInit(int len) 
{
    POS_S *queue = (POS_S *)malloc(sizeof(POS_S) * len);
    if (queue == NULL) {
        return NULL;
    }
    memset(queue, 0, sizeof(POS_S) * len);

    QUEUE_HEAD_S *queueHead = (QUEUE_HEAD_S *)malloc(sizeof(QUEUE_HEAD_S));
    if (queueHead == NULL) {
        free(queue);
        return NULL;
    }
    memset(queueHead, 0, sizeof(QUEUE_HEAD_S));
    queueHead->queue = queue;
    queueHead->queueLen = len;
    queueHead->head = -1;
    queueHead->tail = -1;

    return queueHead;
}

/*
    description： 首尾相等，则队列为空。
    param：
        node：队列指针
    attention： 调用者保证指针不为空
*/
bool QueueIsEmpty(QUEUE_HEAD_S *queueHead)
{
    if (queueHead == NULL) {
        return true;
    }
    if (queueHead->head == -1 && queueHead->tail == -1) {
        return true;
    }

    return false;
}

/*
    description： 数据从队列尾入队
    param：
        node：队列指针
        data：需要入队的数据
    attention： 调用者保证指针不为空
*/
void QueueIn(QUEUE_HEAD_S *queueHead, POS_S *data) 
{
    if (QueueIsEmpty(queueHead)) {
        queueHead->tail = 0;
        queueHead->head = 0;
    } else {
        queueHead->tail = (queueHead->tail + 1) % queueHead->queueLen;
    }
    memcpy(&queueHead->queue[queueHead->tail], data, sizeof(POS_S));

   //printf("[IN]tail: %d head:%d \n", queueHead->tail, queueHead->head);

    return;
}
/*
    description： 数据从队列首出队
    param：
        node：队列指针
    retval：出队的数据,
    attention： 调用者释放返回的data
*/
void QueueOut(QUEUE_HEAD_S *queueHead, POS_S *pos)
{
    if (QueueIsEmpty(queueHead)) {
        return;
    }
    memcpy(pos, &queueHead->queue[queueHead->head], sizeof(POS_S));
    memset(&queueHead->queue[queueHead->head], 0, sizeof(POS_S));
    if (queueHead->head == queueHead->tail) {
        queueHead->tail = -1;
        queueHead->head = -1;
    } else {
        queueHead->head = (queueHead->head + 1) % queueHead->queueLen;
    }
    //printf("[OUT]tail: %d head:%d \n", queueHead->tail, queueHead->head);
    return;
}

/* 销毁队列 */
void QueueDestroy(QUEUE_HEAD_S *queueHead)
{
    free(queueHead->queue);
    free(queueHead);

    return;
}


bool IsNextPosOK(int nextDeep, int nextBand, POS_S *curPos, int gridSize, GRID_NODE_INFO_S **grid) {
    if (grid[nextDeep][nextBand].block == 1) {
        return false;
    }
    int i, j;
    
    for (i = curPos->lastDeep - 1; i <= curPos->lastDeep + 1; i++) {
        for (j = curPos->lastBand - 1; j <= curPos->lastBand + 1; j++) {
            if (nextDeep == i && nextBand == j) {
                return false;
            }
        }
    }

    return true;
}

int NextPosInQueue(int nextDeep, int nextBand, POS_S *curPos, GRID_NODE_INFO_S** grid, int gridSize, QUEUE_HEAD_S *queue){
    //printf("in: %d %d", nextDeep, nextBand);
    if (IsNextPosOK(nextDeep, nextBand, curPos, gridSize, grid)) {
        //printf("OK \n");
        if (grid[nextDeep][nextBand].lestLen == -1) {
            grid[nextDeep][nextBand].lestLen = curPos->pathLen + 1;
        } else if (curPos->pathLen + 1 >= grid[nextDeep][nextBand].lestLen) {
            return 0;
        }

        POS_S nextPos;
        nextPos.band = nextBand;
        nextPos.deep = nextDeep;
        nextPos.lastBand = curPos->band;
        nextPos.lastDeep = curPos->deep;
        nextPos.pathLen = curPos->pathLen + 1;
        QueueIn(queue, &nextPos);
    }

    return 0;
}
#define MAX_PATH_LEN(gridSize) (gridSize * (gridSize + 1) / 2)

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return -1;
    }

    if (grid[0][0] == 1 || grid[gridSize - 1][gridSize - 1] == 1) {
        return -1;
    }
   
    if (gridSize == 1) {
        return 1;
    }

    GRID_NODE_INFO_S **gridMap = (GRID_NODE_INFO_S **)malloc(sizeof(GRID_NODE_INFO_S *) * gridSize);
    if (gridMap == NULL) {
        return -1;
    }
    int i,j;
    for (i = 0; i < gridSize; i++) {
        gridMap[i] = (GRID_NODE_INFO_S *)malloc(sizeof(GRID_NODE_INFO_S) * gridColSize[i]);
        for (j = 0; j < gridColSize[i]; j++) {
            gridMap[i][j].block = grid[i][j];
            gridMap[i][j].lestLen = -1;
        }
    }

    POS_S curPos;
    curPos.band = 0;
    curPos.deep = 0;
    curPos.lastBand = -1;
    curPos.lastDeep = -1;
    curPos.pathLen = 1;

    QUEUE_HEAD_S *queue = QueueInit(gridSize * gridSize);
    
    QueueIn(queue, &curPos);
    int nextDeep;
    int nextBand;
    POS_S *nextPos = NULL;
    while(!QueueIsEmpty(queue)) {
        QueueOut(queue, &curPos);
        int curDeep = curPos.deep;
        int curBand = curPos.band;
        //printf("\n out %d %d \n", curDeep, curBand);
        if (curDeep == gridSize - 1 && curBand == gridSize - 1) {
            //printf(" pathLen = %d minPathLen = %d\n", curPos.pathLen, minPathLen);
            continue;
        }

        for (i = (curDeep - 1 >= 0 ? curDeep - 1 : 0); i <= (curDeep + 1 < gridSize ? curDeep + 1 : gridSize - 1); i++) {
            for (j = (curBand - 1 >= 0 ? curBand - 1 : 0); j <= (curBand + 1 < gridColSize[i] ? curBand + 1 : gridColSize[i] - 1); j++) {
                NextPosInQueue(i, j, &curPos, gridMap, gridSize, queue);
            }
        }
    }
    QueueDestroy(queue);

    int minPathLen = gridMap[gridSize - 1][gridSize - 1].lestLen;
    for (i = 0; i < gridSize; i++) {
        free(gridMap[i]);
    }
    free(gridMap);

    return minPathLen;
}
```


2. 使用递归实现BFS
```c
int *g_PathInfo = NULL; 

int InitPathInfo(int **grid, int gridSize, int *gridColSize)
{
    int i, j;

    g_PathInfo = (int *)malloc(sizeof(int) * gridSize * gridSize);
    if (g_PathInfo == NULL) {
        return -1;
    }
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            g_PathInfo[i * gridSize + j] = -1;
        }
    }

    return 0;
}

void DestroyPathInfo() 
{
    if (g_PathInfo != NULL) {
        free(g_PathInfo);
        g_PathInfo = NULL;
    }
    return;
}

typedef struct tagSTEP_S{
    int i;
    int j;
    int len;
}STEP_S;


void GetNext(int** grid, int gridSize, int* gridColSize, STEP_S *curStep, STEP_S *nextStep, int *nextCnt)
{
    int posI = curStep->i;
    int posJ = curStep->j;
    int len = curStep->len;
    int i, j;  /* 表示要遍历的下一个节点 */
    //printf("%d %d: len %d, minLen %d\n", posI, posJ, len, g_PathInfo[posI * gridSize + posJ]);
    for (i = (posI - 1 >= 0 ? posI - 1 : 0); i <= (posI + 1 < gridSize ? posI + 1 : gridSize - 1); i++) {
        for (j = (posJ - 1 >= 0 ? posJ - 1 : 0); j <= (posJ + 1 < gridColSize[i] ? posJ + 1 : gridColSize[i] - 1); j++) {
            if (grid[i][j] == 1) {
                continue;
            }

            if (i == posI && j == posJ) {
                continue;
            }

            if (g_PathInfo[i * gridSize + j] == -1) {
                g_PathInfo[i * gridSize + j] = len + 1;
            } else if (g_PathInfo[i * gridSize + j] <= len + 1) {
                continue;
            } else {
                g_PathInfo[i * gridSize + j] = len + 1;
            }

            nextStep[*nextCnt].i = i;
            nextStep[*nextCnt].j = j;
            nextStep[*nextCnt].len = len + 1;
            (*nextCnt)++;
        }
    }
    
    return;
}

void bfs(int** grid, int gridSize, int* gridColSize, STEP_S *curStep, int curCnt, STEP_S *nextStep)
{
    int i;
    int nextCnt = 0;
    for (i = 0; i < curCnt; i++) {
        GetNext(grid, gridSize, gridColSize, &curStep[i], nextStep, &nextCnt);
    }

    if (nextCnt == 0) {
        return;
    }

    bfs(grid, gridSize, gridColSize, nextStep, nextCnt, curStep);
}

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize)
{
    if (grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return -1;
    }

    if (grid[0][0] == 1 || grid[gridSize - 1][gridSize - 1] == 1) {
        return -1;
    }

    if (InitPathInfo(grid, gridSize, gridColSize) == -1) {
        return -1;
    }

    grid[0][0] = 1;

    STEP_S *curStep = (STEP_S *)malloc(sizeof(STEP_S) * gridSize * gridSize);
    if (curStep == NULL) {
        DestroyPathInfo();
        return -1;
    }
    curStep[0].i = 0;
    curStep[0].j = 0;
    curStep[0].len = 1;
    g_PathInfo[0] = 1;
    STEP_S *nextStep = (STEP_S *)malloc(sizeof(STEP_S) * gridSize * gridSize);
    if (nextStep == NULL) {
        free(curStep);
        DestroyPathInfo();
        return -1;
    }

    bfs(grid, gridSize, gridColSize, curStep, 1, nextStep);

    int minLen = g_PathInfo[gridSize * gridSize - 1];
    DestroyPathInfo();

    return minLen;
}
```