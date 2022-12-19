### 解题思路
这道题是非常经典的广度和深度的题目，值得好好的品读，为了深刻的理解DFS和BFS遍历，我从递归DFS到递归BFS，再把队列的形式转换为非递归的BFS。

基本思路就是把一整块相连的区域的1全部遍历，全部置0，这样就算一块岛屿。

三种思路，代码写的还算很清爽的，如有疑问，欢迎提问~
这里留一个小问题，为什么把1置0要在入队的时候置0，而不是或者说能不能在出队的时候置0？

### 代码

```
//递归DFS
void DFS(char** grid, int gridSize, int* gridColSize,int x,int y)
{
    grid[x][y]='0';
    //for direction
    int dir_y[4]={0,0,-1,1};//横列竖行
    int dir_x[4]={-1,1,0,0};
    int i;
    
    int new_x,new_y;
    for(i=0;i<4;i++)
    {
        new_x=x+dir_x[i];
        new_y=y+dir_y[i];
        if((new_x>=0&&new_x<gridSize)&&(new_y>=0&&new_y<*gridColSize))//在网格之内
        {
            if(grid[new_x][new_y]=='1')
            {
                DFS(grid,gridSize,gridColSize,new_x,new_y);
            }
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int i,j;
    int count=0;
    for(i=0;i<gridSize;i++)
        for(j=0;j<*gridColSize;j++)
        if(grid[i][j]=='1')
        {
            count++;
            DFS(grid,gridSize,gridColSize,i,j);
        }
    return count;
}
```

```c
//递归BFS遍历
#define MaxSize 500
void BFS(char** grid, int gridSize, int* gridColSize,int x,int y,int *Queue_x,int *Queue_y,int *front,int *rear)
{
    //FOR DIRECTION
    int dir_x[4]={-1,1,0,0};
    int dir_y[4]={0,0,-1,1};
    int i;

    int new_x;
    int new_y;
    if(*rear!=*front)
    {
            //出栈
        (*front)++;
        *front%=MaxSize;
        int pos_x=Queue_x[*front];
        int pos_y=Queue_y[*front];
        for(i=0;i<4;i++)
        {
            new_x=pos_x+dir_x[i];
            new_y=pos_y+dir_y[i];
            if(new_x>=0&&new_x<gridSize&&new_y>=0&&new_y<*gridColSize)
            {
                    if(grid[new_x][new_y]=='1'){
                    grid[new_x][new_y]='0';
                    //入栈
                    ++(*rear);
                    *rear%=MaxSize;
                    Queue_x[*rear]=new_x;
                    Queue_y[*rear]=new_y;
                    BFS(grid,gridSize,gridColSize,new_x,new_y,Queue_x,Queue_y,front,rear);
                    }
            }
        }
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize){
        //fOR QUEUE
    int Queue_x[MaxSize];
    int Queue_y[MaxSize];
    int front=-1;
    int rear=-1;

    int i,j;
    int num=0;
    for(i=0;i<gridSize;i++)
        for(j=0;j<*gridColSize;j++)
        if(grid[i][j]=='1')
        {
                //入栈
            Queue_x[++rear]=i;
            Queue_y[rear]=j;
            grid[i][j]='0';
            num++;
            BFS(grid,gridSize,gridColSize,i,j,Queue_x,Queue_y,&front,&rear);
        }
    return num;
}


```

```
//非递归BFS遍历
#define MaxSize 500
void BFS(char** grid, int gridSize, int* gridColSize,int x,int y)
{
    //fOR QUEUE
    int Queue_x[MaxSize];
    int Queue_y[MaxSize];
    int front=-1;
    int rear=-1;

    //入栈
    Queue_x[++rear]=x;
    Queue_y[rear]=y;
    grid[x][y]='0';

    //FOR DIRECTION
    int dir_x[4]={-1,1,0,0};
    int dir_y[4]={0,0,-1,1};
    int i;

    int pos_x;
    int pos_y;

    int new_x;
    int new_y;
    while(rear!=front)
    {
        front++;
        front%=MaxSize;
        pos_x=Queue_x[front];//出栈
        pos_y=Queue_y[front];
        for(i=0;i<4;i++)
        {
            new_x=pos_x+dir_x[i];
            new_y=pos_y+dir_y[i];
            if(new_x>=0&&new_x<gridSize&&new_y>=0&&new_y<*gridColSize)
            {
                    if(grid[new_x][new_y]=='1'){
                    grid[new_x][new_y]='0';
                    //入栈
                    ++rear;
                    rear%=MaxSize;
                    Queue_x[rear]=new_x;
                    Queue_y[rear]=new_y;
                    }
            }
        }
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    int i,j;
    int num=0;
    for(i=0;i<gridSize;i++)
        for(j=0;j<*gridColSize;j++)
        if(grid[i][j]=='1')
        {
            num++;
            BFS(grid,gridSize,gridColSize,i,j);
        }
    return num;
}


```
