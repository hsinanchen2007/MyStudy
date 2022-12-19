### 解题思路
妥妥拉拉，代码写得不够优雅，这个题应该算是个简单题目。
### 代码

```c
#define MAX_NUMS 1000
typedef struct Node_
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

int QueueCount(Queue *queue)
{
	return (queue->rear - queue->front) % MAX_NUMS;
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

Queue myqueue;

int cacu(int** matrix, int matrixSize, int* matrixColSize, int i, int j)
{
	int m = matrixSize;
	int n = *matrixColSize;
	Node tnode;
	tnode.x = i;
	tnode.y = j;
	tnode.level = 0;
    QueuePush(&myqueue,tnode);
	while(!Empty(&myqueue))
	{
		int maxNode = QueueCount(&myqueue);
        for(int i = 0; i < maxNode; i++)
		{
            //逐个看队列中这一堆元素中有没有0，如果有，说明达到了位置。
			Node tmp = QueueTop(&myqueue);
			QueuePop(&myqueue);
			int x=tmp.x;
			int y=tmp.y;
			int level = tmp.level;
			if(matrix[x][y] == 0)
			{
				QueueClear(&myqueue);
				return level;
			}

			if(x+1 < m && y < n && y>=0) {
				tmp.x = x+1;
				tmp.y = y;
				tmp.level = level+1;
				QueuePush(&myqueue, tmp);
			}
			if(x < m && x>=0 && y+1 < n ) {
				tmp.x = x;
				tmp.y = y+1;
				tmp.level = level+1;
				QueuePush(&myqueue, tmp);

			}
			if(x-1 >=0 && x-1 < m && y < n && y>=0 ) {
				tmp.x = x - 1;
				tmp.y = y;
				tmp.level = level+1;
				QueuePush(&myqueue, tmp);

			}
			if(x >=0 && x<m && y-1 >= 0 && y-1 < n) {
				tmp.x = x;
				tmp.y = y-1;
				tmp.level = level+1;
				QueuePush(&myqueue, tmp);
			}

		}
	}
    return 0;
}

int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){

QueueInit(&myqueue);
int ** ret = malloc(sizeof(int *) * matrixSize);
int *recol = malloc(sizeof(int)*matrixSize);

for(int i = 0; i < matrixSize;i++)
{

	ret[i] = malloc(sizeof(int) * (*matrixColSize));
	recol[i] = *matrixColSize;
}
for(int i = 0; i < matrixSize;i++)
{
	for(int j=0;j<*matrixColSize;j++) {
		if(matrix[i][j] == 0)
		{
			ret[i][j] = 0;
		}
		else
		{

			ret[i][j] = cacu(matrix, matrixSize, matrixColSize, i,j);
		}
    }
}
*returnSize = matrixSize;
*returnColumnSizes = recol;
return ret;



}
```