### 解题思路
DFS深度优先遍历先找到第一个岛，并进行染色标志未2；找到第一个后退出；
将找到的第一个岛的位置入队列（C语言没有现成的队列封装函数，需要自己实现）
对第一个岛的节点进行广度优先遍历，找到1的层数就是需要返回的值；

### 代码

```c
#define QUENUE_MAX_SIZE 10000
typedef struct {
    int xValue;
    int yValue;
}BridgePos;

typedef struct {
    BridgePos data[QUENUE_MAX_SIZE];
    int front;
    int rear;
}Queue;

void InitQueue(Queue *que)
{
    que->front = que->rear = 0;
}

void EnQueue(Queue *que, BridgePos data)
{
    if ((que->rear + 1) % QUENUE_MAX_SIZE == que->front) {
        return;
    } else {
        que->data[que->rear].xValue = data.xValue;
        que->data[que->rear].yValue = data.yValue;
        que->rear = (que->rear + 1) % QUENUE_MAX_SIZE;
    }
}

void DeQueue(Queue *que, BridgePos *data)
{
    if (que->rear == que->front) {
        return;
    }
        
    *data = que->data[que->front];
    que->front = (que->front + 1) % QUENUE_MAX_SIZE;
}

int IsEmpty(Queue *que)
{
    if (que->front == que->rear) {
        return 1;
    }

    return 0;
}

void dfsBridge(int **A, int ASize, int colSize, int i , int j)
{
    A[i][j] = 2;

    if ((i - 1 >= 0) && (A[i - 1][j] == 1)) {
        dfsBridge(A, ASize, colSize, i - 1 , j);
    }
    if ((i + 1 < ASize) && (A[i + 1][j] == 1)) {
        dfsBridge(A, ASize, colSize, i + 1 , j);
    }
    if ((j - 1 >= 0) && (A[i][j - 1] == 1)) {
        dfsBridge(A, ASize, colSize, i , j - 1);
    }
    if ((j + 1 < colSize) && (A[i][j + 1] == 1)) {
        dfsBridge(A, ASize, colSize, i, j + 1);
    }

    return;
}

void SetFirstBridge(int** A, int ASize, int* AColSize, int type, Queue *que) 
{
    int colSize = 0;
    BridgePos data;

    for (int i = 0; i < ASize; i++) {
        colSize = AColSize[i];
        for (int j =0; j < colSize; j++) {
            if (A[i][j] == 1 && type == 0) {
                dfsBridge(A, ASize, colSize, i, j);
                return;
            }

            if (type == 1 && A[i][j] == 2) {
                data.xValue = i;
                data.yValue = j;

                EnQueue(que, data);
            }
        }
    }
}

int GetQueSize(Queue *que)
{
    if (que == NULL) {
        return 0;
    }

    return (que->rear - que->front);
}

int GetBridgeMinValue(int** A, int ASize, int* AColSize, Queue *que) 
{
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int step = 0;
    int queSize = 0;
    int incX = 0;
    int incY = 0;
    BridgePos data;
    BridgePos dataTmp;

    while (!(IsEmpty(que))) {
        queSize = GetQueSize(que);

        for (int i = 0; i < queSize; i++) {
            DeQueue(que, &data);
            for (int j =0; j < 4; j++) {
                incX = data.xValue + dx[j];
                incY = data.yValue + dy[j];

                if (incX < 0 || incX >= ASize || incY < 0 || incY >= AColSize[0]) {
                    continue;
                }
                
                if (A[incX][incY] == 2) {
                    continue;
                }

                if (A[incX][incY] == 1) {
                    return step;
                }

                dataTmp.xValue = incX;
                dataTmp.yValue = incY;
                A[incX][incY] = 2;

                EnQueue(que, dataTmp);
            }
        }

        step++;

    }

    return step;
}

int shortestBridge(int** A, int ASize, int* AColSize)
{
    int ret = 0;
    Queue bridgeQue;

    if (A == NULL || ASize == 0 || AColSize == NULL) {
        return ret;
    }

    InitQueue(&bridgeQue);

    SetFirstBridge(A, ASize, AColSize, 0, &bridgeQue);

    SetFirstBridge(A, ASize, AColSize, 1,&bridgeQue);

    ret = GetBridgeMinValue(A, ASize, AColSize, &bridgeQue);

    return ret;
}
```