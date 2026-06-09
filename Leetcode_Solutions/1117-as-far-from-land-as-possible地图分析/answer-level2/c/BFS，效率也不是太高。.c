### 解题思路
此处撰写解题思路

### 代码

```c

/*找到非1的点，上下左右bfs，直到找到1，返回层数。*/
#define MAX_NUMS 1000001
typedef struct NODE_
{
    int x;
    int y;
    int level;
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

int QueueCnt(Queue *queue)
{
    return abs(queue->rear - queue->front);
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

int getDistance(int** grid, int gridSize, int gridColSize, int i , int j, int visit[gridSize][gridColSize]) {

Queue myQueue;
QueueInit(&myQueue);
Node myNode;
myNode.x = i;
myNode.y = j;
myNode.level = 0;
visit[i][j] = 1;
QueuePush(&myQueue, myNode);

while(!Empty(&myQueue))
{
    int quecnt = QueueCnt(&myQueue);
    for(int i = 0; i < quecnt; i++)
    {
        Node tmpNode;
        tmpNode = QueueTop(&myQueue);
        
        if(grid[tmpNode.x][tmpNode.y] == 1) {
            //printf("%d,%d\r\n", tmpNode.x, tmpNode.y);
            QueueClear(&myQueue);
            return tmpNode.level;
        }
        QueuePop(&myQueue);
        
        if(tmpNode.x + 1 < gridSize && visit[tmpNode.x+1][tmpNode.y] == 0 )
        {
            Node n1;
            n1.x = tmpNode.x+1;
            n1.y = tmpNode.y;
            n1.level = tmpNode.level+1;
			//printf("Enter Queue %d,%d %d\r\n", n1.x, n1.y, n1.level);
            QueuePush(&myQueue,n1);
            visit[n1.x][n1.y] = 1;
        }
        if(tmpNode.x - 1 >= 0 &&visit[tmpNode.x-1][tmpNode.y] == 0 )
        {
            Node n2;
            n2.x = tmpNode.x - 1;
            n2.y = tmpNode.y;
            n2.level = tmpNode.level+1;
			//printf("Enter Queue %d,%d %d\r\n", n2.x, n2.y, n2.level);
            QueuePush(&myQueue,n2);
            visit[n2.x][n2.y] = 1;
        }

        if(  tmpNode.y + 1 < gridColSize && visit[tmpNode.x][tmpNode.y+1] == 0)
        {
            Node n3;
            n3.x = tmpNode.x;
            n3.y = tmpNode.y+1;
            n3.level = tmpNode.level+1;
			//printf("Enter Queue %d,%d %d\r\n", n3.x, n3.y, n3.level);
            QueuePush(&myQueue,n3);
            visit[n3.x][n3.y] = 1;
        }
        if(tmpNode.y - 1 >= 0 && visit[tmpNode.x][tmpNode.y -1] == 0)
        {
            Node n4;
            n4.x = tmpNode.x;
            n4.y = tmpNode.y-1;
            n4.level = tmpNode.level+1;
			//printf("Enter Queue %d,%d %d\r\n", n4.x, n4.y, n4.level);
            QueuePush(&myQueue,n4);
            visit[n4.x][n4.y] = 1;
        }

    }
}

QueueClear(&myQueue);

return -1;

}

#define max(a,b) a>b?a:b
int maxDistance(int** grid, int gridSize, int* gridColSize){

int mydis = -1;
if(gridSize == 0 || *gridColSize == 0) {
    return -1;
}
int visit[gridSize][*gridColSize];
for(int i = 0; i < gridSize; i++) {
    for(int j = 0; j <*gridColSize; j++)
    {
        visit[i][j] = 0;
    }
}

for(int i = 0; i < gridSize; i++) {
    for(int j = 0; j <*gridColSize; j++)
    {
        if(grid[i][j] == 0) {
            memset(visit,0,sizeof(visit));
            
           int dis = getDistance(grid, gridSize, *gridColSize, i,j,visit);
           //printf("%d, %d,%d\r\n",i, j,dis);
           mydis = max(mydis, dis);
        }
    }
}

return mydis;

}
```