### 解题思路
用队列实现bfs，遍历地图，每找到一个值为1的点，表示发现新大陆，从这个点开始搜索，把这个岛的所有点染色（标记为大于1的值），同时记录点数，随时更新答案的最大值。
就是用时有丶长
执行用时 :44 ms, 在所有 C 提交中击败了11.99%的用户
内存消耗 :7.4 MB, 在所有 C 提交中击败了100.00%的用户
### 代码

```c
typedef struct MY_QUEUE_NODE{
    int x;
    int y;
    struct MY_QUEUE_NODE *next;
}MyQueueNode;

typedef struct MY_QUEUE{
    MyQueueNode *front;
    MyQueueNode *rear;
}MyQueue;

void pushIntoRear(MyQueue *mq,int x,int y)
{
    MyQueueNode *newnode;
    newnode=(MyQueueNode*)malloc(sizeof(MyQueueNode));
    newnode->x=x;
    newnode->y=y;
    newnode->next=NULL;
    if(mq->rear==NULL)
    {
        mq->front=mq->rear=newnode;
    }
    else
    {
        mq->rear->next=newnode;
        mq->rear=newnode;
    }
}

void popFromFront(MyQueue *mq)
{
    MyQueueNode *tmp;
    tmp=mq->front;
    mq->front=mq->front->next;
    if(mq->front==NULL)
    {
        mq->rear=NULL;
    }
    free(tmp);
}

MyQueueNode *topOfMyQueue(MyQueue *mq)
{
    return mq->front;
}

bool isMyQueueEmpty(MyQueue *mq)
{
    if(mq->front==NULL)
    {
        return true;
    }
    return false;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    //printf("%d %d",gridSize,*gridColSize);

    int xstep[]={-1,1,0,0};
    int ystep[]={0,0,-1,1};
    int ans=0;

    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<*gridColSize;j++)
        {
            if(grid[i][j]==1)
            {
                int cnt=1;
                grid[i][j]+=cnt;
                MyQueue mq;
                mq.front=mq.rear=NULL;
                pushIntoRear(&mq,i,j); //printf("(push:%d %d)",mq.rear->x,mq.rear->y);
                
                while(!isMyQueueEmpty(&mq))
                {  // printf("ine ");
                    MyQueueNode *node=topOfMyQueue(&mq);                    
                    int x=node->x;
                    int y=node->y;
                    popFromFront(&mq);
                    for(int k=0;k<4;k++)
                    {
                        x+=xstep[k];
                        y+=ystep[k];
                        if(x>=0 && x<gridSize && y>=0 && y<*gridColSize && grid[x][y]==1)
                        {
                            cnt++;
                            grid[x][y]+=cnt;
                           // printf("cnt=%d ",cnt);
                            pushIntoRear(&mq,x,y);
                        }
                        x-=xstep[k];
                        y-=ystep[k];                        
                    }                    
                }
                ans=ans>cnt?ans:cnt;
            }
           // printf("%d ",grid[i][j]);
        }
        //printf("\n");
    }

    return ans;
}
```