typedef struct stQueueData {
    int data[6];
} QueueData;

typedef struct stQueueNode {
    struct stQueueNode *pNext;
    QueueData data;
} QueueNode;

typedef struct stQueue {
    QueueNode *head;
    QueueNode *tail;
    int nodeNum;
} Queue;

void InitQueue(Queue *queue);
int InsertToQueue(Queue *queue, QueueData *data);
int PopFromQueue(Queue *queue, QueueData *data);
int IsQueueEmpty(Queue *queue);

void InitQueue(Queue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->nodeNum = 0;
}

int IsQueueEmpty(Queue *queue) 
{
    if (queue->nodeNum == 0) {
        return 1;
    } else {
        return 0;
    }
}

int InsertToQueue(Queue *queue, QueueData *data) 
{
    QueueNode *temp = NULL;

    temp = (QueueNode *)malloc(sizeof(QueueNode));
    if (temp == NULL) {
        return -1;
    }
    memcpy(temp->data.data, data->data, sizeof(int) * 6);
    temp->pNext = NULL;

    if (IsQueueEmpty(queue)) {
        queue->head = temp;
        queue->tail = temp;
    } else {
        queue->tail->pNext = temp;
        queue->tail = temp;
    }
    queue->nodeNum++;

    return 0;
}

int PopFromQueue(Queue *queue, QueueData *data) 
{
    QueueNode *tempHead = NULL;

    if (IsQueueEmpty(queue)) {
        return -1;
    }
   
    tempHead = queue->head;
    memcpy(data->data, tempHead->data.data, sizeof(int) * 6);
    queue->head = queue->head->pNext;
    queue->nodeNum--;
    free(tempHead);

    return 0;
}

#define DIRECT_NUM 4
#define NUM_POS 2
int g_direct[DIRECT_NUM][NUM_POS] = {{0, 1,},{1, 0,},{0, -1,},{-1, 0}};
#define MAX_NUM 600000

int GetIndexByData(QueueData *qData) {
    int index = 0;

    for (int i = 0; i < 6; i++) {
        index = index * 10 + qData->data[i];
    }

    return index;
}

void GetBoardByData(QueueData *qData, int **board)
{
    int index = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = qData->data[index++];
        }
    }
}

void GetDataByBoard(QueueData *qData, int **board, int x, int y, int nextX, int nextY)
{
    int value = board[nextX][nextY];
    int index = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == nextX && j == nextY) {
                qData->data[index++] = 0;
            } else if (i == x && j == y) {
                qData->data[index++] = value;
            } else {
                qData->data[index++] = board[i][j];
            }

        }
    }
}

void GetZeroXY(int **board, int *tempX, int *tempY)
{
    int i;
    int j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                *tempX = i;
                *tempY = j;
                return;
            }
        }
    }
}

bool IsResult(QueueData *qData) 
{
    for (int i = 0; i < 5; i++) {
        if (qData->data[i] != (i + 1)) {
            return false;
        }
    }

    if (qData->data[5] != 0) {
        return false;
    }

    return true;
}

int slidingPuzzle(int** board, int boardSize, int* boardColSize){
    Queue queue;
    int steps = 0;
    int len;
    QueueData qData;
    int tempX;
    int tempY;
    int colSize = *boardColSize;
    char *visit = (char *)malloc(sizeof(char) * MAX_NUM);
    memset(visit, 0, sizeof(char) * MAX_NUM);
   
    InitQueue(&queue);

    int index = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < colSize; j++) {
            qData.data[index++] = board[i][j];
        }
    }
    
    InsertToQueue(&queue, &qData); 
    while (!IsQueueEmpty(&queue)) {
        len = queue.nodeNum;  
        for (int i = 0; i < len; i++) {
            PopFromQueue(&queue, &qData);

            /*for (int i = 0; i < 6; i++) {
                printf("%d ", qData.data[i]);
            }
            printf("\n");*/
            if (IsResult(&qData)) {
                return steps;
            }

            index = GetIndexByData(&qData);
            visit[index] = 1;
            //printf("index %d\n", index);
            GetBoardByData(&qData, board);
            GetZeroXY(board, &tempX, &tempY);
            for (int i = 0; i < DIRECT_NUM; i++) {
                int nextX = tempX + g_direct[i][0];
                int nextY = tempY + g_direct[i][1];
                if (nextX < 0 || nextX >= boardSize || nextY < 0 || nextY >= colSize) {
                    continue;
                }
                //printf("tempX %d tempY %d nextX %d nextY %d value %d\n", tempX, tempY, nextX, nextY, board[nextX][nextY]);
                GetDataByBoard(&qData, board, tempX, tempY, nextX, nextY);
                index = GetIndexByData(&qData);
                //printf("qindex %d\n", index);
                if (visit[index] == 0) {
                    InsertToQueue(&queue, &qData); 
                }
            }
        }
        steps++;
    }

    return -1;
}