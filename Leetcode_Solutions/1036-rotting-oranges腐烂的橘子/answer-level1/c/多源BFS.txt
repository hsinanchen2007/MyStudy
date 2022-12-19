比起n次广度优先搜索，还是多源BFS更香一点
理解起来其实不难，就是一开始把烂橘子都放进队列里边，去模拟实际橘子腐烂的过程
因为橘子它实际就是一起同时腐烂的
代码里的last就是判断遍历层数的重要变量
参考代码如下
```
int count;
struct Coordinates
{
    char c;
    int x;
    int y;
};
void BFS(int** grid,int gridSize, int* gridColSize)
{
    int dic[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    struct Coordinates Q[100];
    int rear=0,front=0;
    int last=0;
    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<gridColSize[0];j++)
        {
            if(grid[i][j]==2)
            {
                Q[rear].x=i;
                Q[rear].y=j;
                Q[rear++].c=2;
            }
        }
    }
    last=rear;
    while(rear!=front)
    {
        if(last==front)
        {
            count++;
            last=rear;
        }
        int curx=Q[front].x;
        int cury=Q[front].y;
        int curc=Q[front++].c;
        if(curc==2)
        {
            for(int i=0;i<4;i++)
            {
                int nextx=curx+dic[i][0];
                int nexty=cury+dic[i][1];
                if(nextx>=0&&nextx<gridSize&&nexty>=0&&nexty<gridColSize[0]&&grid[nextx][nexty]!=2&&grid[nextx][nexty]!=0)
                {
                    Q[rear].x=nextx;
                    Q[rear].y=nexty;
                    Q[rear++].c=2;
                    grid[nextx][nexty]=2;
                }
            }
        }
    }
    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<gridColSize[0];j++)
        {
            if(grid[i][j]==1)
            {
                count=-1;
            }
        }
    }
}
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    count=0;
    BFS(grid,gridSize,gridColSize);
    return count;
}
```
