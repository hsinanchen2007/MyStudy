### 解题思路
1、沿着边搜索'O'
2、从'O'开始做BFS搜索相邻得'O'，并把这些'O'改成'Y'，这一步后，所有和边相邻的'O'都变成了'Y',剩下的'O'就是真正需要变成'X'的'O'
3、在从头扫描把所有的'O'变成'X',同时把'Y'变成'X'

### 代码

```c
typedef struct tagList {
    struct tagList *next;
    struct tagList *prev;
} List;

void  ListInit(List *listHead)
{
    listHead->next = listHead;
    listHead->prev = listHead;
    return;
}

void ListAddTail(List *head, List *entry)
{
    head->prev->next = entry;
    entry->prev = head->prev;
    head->prev = entry;
    entry->next = head;

}
bool ListEmpty(List *head)
{
    return (head->next == head);
}
void ListRemoveHead(List *head)
{
    head->next = head->next->next;
    head->next->prev = head;
}

#define NODE_ENTRY(ptr, type, member) ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

typedef struct tagMyQueueObj {
    List qHead;
    int queueLen;
} MyQueueObj;

typedef struct tagPosition {
    int x;
    int y;
} Position;

typedef struct tagMyQueueNode {
    List qEntry;
    Position pos;
} MyQueueNode;

MyQueueObj *MyQueueInit(void)
{
    MyQueueObj *queueObj = NULL;
    queueObj = (MyQueueObj *)malloc(sizeof(MyQueueObj));
    if (queueObj == NULL) {
        return NULL;
    }
    ListInit(&(queueObj->qHead));
    queueObj->queueLen = 0;
    return queueObj;
}

void MyQueueAppend(MyQueueObj *queueObj, int x, int y)
{
    MyQueueNode *queueNode = NULL;
    queueNode = malloc(sizeof(MyQueueNode));
    if (queueNode == NULL) {
        return;
    }
    queueNode->qEntry.next = NULL;
    queueNode->qEntry.prev = NULL;
    queueNode->pos.x = x;
    queueNode->pos.y = y;
    
    ListAddTail(&(queueObj->qHead), &(queueNode->qEntry));
    queueObj->queueLen++;
}

MyQueueNode *MyQueuePop(MyQueueObj *queueObj)
{
    List *tmpEntry = NULL;

    if (ListEmpty(&(queueObj->qHead))) {
        return NULL;
    }
    
    tmpEntry = queueObj->qHead.next;
    ListRemoveHead(&(queueObj->qHead));

    tmpEntry->next = NULL;
    tmpEntry->prev = NULL;

    queueObj->queueLen--;
    return (NODE_ENTRY(tmpEntry, MyQueueNode, qEntry));
}

void MyQueueNodeFree(MyQueueNode *queueNode)
{
    if (queueNode != NULL) {
        free(queueNode);
    }
    return;
}

bool MyQueueEmpty(MyQueueObj *queueObj)
{
    if (ListEmpty(&(queueObj->qHead))) {
        return true;
    } else {
        return false;
    }
}

int g_boardSize = 0;
int g_boardColSize = 0;

bool mark[1000][1000] = {{false}};
int go[4][2] = {0,-1,1,0,0,1,-1,0}; //方向向量

bool CheckIsO(char** board, int x, int y)
{    
    if ((x <= 0) || (y <= 0) || (x >= g_boardSize - 1) || (y >= g_boardColSize - 1)) {
        return false;
    }
    if (mark[x][y] == true) {
        return false;
    }
    if (board[x][y] == 'O') {
        return true;
    }
    return false;
}
void ChgO2Y(char** board, int x, int y, MyQueueObj *queue)
{   
    MyQueueNode *qNode = NULL;
    MyQueueNode *nextNode = NULL;
    MyQueueAppend(queue, x, y);
    int tmpX = 0;
    int tmpY = 0;

    mark[x][y] = true;
    while(!MyQueueEmpty(queue)) {
        qNode = MyQueuePop(queue);
        tmpX = qNode->pos.x;
        tmpY = qNode->pos.y;
        if ((board[tmpX][tmpY] == 'Y') || (board[tmpX][tmpY] == 'X'))   {
            continue;
        } 
        board[tmpX][tmpY] = 'Y';
        for (int i = 0; i < 4; i++) {
            tmpX =  qNode->pos.x + go[i][0];
            tmpY =  qNode->pos.y + go[i][1];            
            if(CheckIsO(board, tmpX, tmpY)) //如果状态满足条件则入队；
            {                
                MyQueueAppend(queue, tmpX, tmpY);
            }             
        }
        mark[x][y] = false;
    }
}
void solve(char** board, int boardSize, int* boardColSize){
    MyQueueObj *queue = MyQueueInit();
    memset(mark, false, 1000 * 1000 * sizeof(bool));
    if ((boardSize == 0) || (boardColSize == NULL)) {
        return;
    }
    g_boardSize = boardSize;
    g_boardColSize = *boardColSize;
    
    for (int i = 0; i < g_boardSize; i++) {
        for (int j = 0; j < g_boardColSize; j++) {
            if ((i == 0) || (i == boardSize - 1) || (j == 0) || (j == g_boardColSize - 1)) {
                ChgO2Y(board, i, j, queue);
            }
        }
    }

    for (int i = 0; i < g_boardSize; i++) {
        for (int j = 0; j < g_boardColSize; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
                continue;
            }
            if (board[i][j] == 'Y') {
                board[i][j] = 'O';
            }
        }
    }

    MyQueueNodeFree(queue);
}
```