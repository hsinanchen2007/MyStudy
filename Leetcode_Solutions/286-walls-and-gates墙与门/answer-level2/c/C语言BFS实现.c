典型的BFS题目，这里自己实现的队列采用的是数组的形式，相对简单，但是比较耗内存。可以优化成按需分配的指针形式，降低内存消耗。
```
#define INF 2147483647

typedef struct Node {
    int x;
    int y;
    int step;
    bool visited;
} Node;

typedef Node ElemType;
#define MAX_ELEM_NUM 100000

typedef struct MyQueue {
    ElemType elem[MAX_ELEM_NUM];
    int front;
    int rear;
} MyQueue;

bool IsQueueEmpty(MyQueue *Q)
{
    if (Q->front == Q->rear) {
        return true;
    }
    return false;
}

bool IsQueueFull(MyQueue *Q)
{
    if ((Q->rear + 1) % MAX_ELEM_NUM == Q->front) {
        return true;
    }
    return false;
}

void QueuePush(MyQueue *Q, ElemType elem)
{
    if (IsQueueFull(Q)) {
        return;
    }
    Q->elem[Q->rear] = elem;
    Q->rear = (Q->rear + 1) % MAX_ELEM_NUM;
}

void QueuePop(MyQueue *Q, ElemType *elem)
{
    if (IsQueueEmpty(Q)) {
        return;
    }
    *elem = Q->elem[Q->front];
    Q->front = (Q->front + 1) % MAX_ELEM_NUM;
}

void InitQueue(MyQueue *Q)
{
    memset(Q, 0, sizeof(MyQueue));
}

#define DIR_NUM 4
int x_step[DIR_NUM] = {0, 0, 1, -1};
int y_step[DIR_NUM] = {1, -1, 0, 0};

void BFS(int **rooms, int rowNum, int colNum, Node **grid)
{
    MyQueue Q;
    InitQueue(&Q);

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < colNum; j++) {
            if (rooms[i][j] == 0) {
                Node tempNode = {i, j, 0, true};
                grid[i][j].step = 0;
                grid[i][j].visited = true;
                QueuePush(&Q, tempNode);
            }
        }
    }

    Node currNode;
    while (!IsQueueEmpty(&Q)) {
        QueuePop(&Q, &currNode);
        for (int i = 0; i < DIR_NUM; i++) {
            int newX = currNode.x + x_step[i];
            int newY = currNode.y + y_step[i];
            int newStep = currNode.step + 1;
            if (newX >= 0 && newX < rowNum && newY >= 0 && newY < colNum && rooms[newX][newY] == INF &&
                grid[newX][newY].visited == false) {
                Node newNode = {newX, newY, newStep, true};
                grid[newX][newY].step = newStep;
                grid[newX][newY].visited = true;
                QueuePush(&Q, newNode);
            }
        }
    }

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < colNum; j++) {
            if (grid[i][j].visited) {
                rooms[i][j] = grid[i][j].step;
            }
        }
    }
}

void wallsAndGates(int **rooms, int roomsSize, int *roomsColSize)
{
    if (rooms == NULL || roomsSize == 0) {
        return;
    }
    
    int rowNum = roomsSize;
    int colNum = roomsColSize[0];

    Node **grid = (Node **)malloc(sizeof(Node *) * rowNum);
    for (int i = 0; i < rowNum; i++) {
        grid[i] = (Node *)malloc(sizeof(Node) * colNum);
        memset(grid[i], 0, sizeof(Node) * colNum);
    }

    for (int i = 0; i < rowNum; i++) {
        for (int j = 0; j < colNum; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].step = 0;
            grid[i][j].visited = false;
        }
    }

    BFS(rooms, rowNum, colNum, grid);

    for (int i = 0; i < rowNum; i++) {
        free(grid[i]);
    }
    free(grid);
}
```
