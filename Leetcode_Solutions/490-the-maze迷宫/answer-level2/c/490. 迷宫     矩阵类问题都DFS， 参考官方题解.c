### 解题思路
由空地和墙组成的迷宫中有一个球。球可以向上下左右四个方向滚动，但在遇到墙壁前不会停止滚动。当球停下时，可以选择下一个方向。

给定球的起始位置，目的地和迷宫，判断球能否在目的地停下。

迷宫由一个0和1的二维数组表示。 1表示墙壁，0表示空地。你可以假定迷宫的边缘都是墙壁。起始位置和目的地的坐标通过行号和列号给出。

 

示例 1:

输入 1: 迷宫由以下二维数组表示

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

输入 2: 起始位置坐标 (rowStart, colStart) = (0, 4)
输入 3: 目的地坐标 (rowDest, colDest) = (4, 4)

输出: true




矩阵类DFS  上下左右 递归

### 代码

```c
int rowSize,colSize;
int visit[500][500];

bool dfs (int** maze,int row, int col,int *dest){
    
    if(row < 0 || row >= rowSize || col < 0 || col >=colSize)
        return false;

    if(visit[row][col])
        return false;

    if(row == dest[0] && col == dest[1]){
        printf("%d %d got it!\n",row,col);
        return true;
    }
    //printf("%d %d entry \n",row,col);

    visit[row][col] = 1;

    int u = row - 1;
    int d = row + 1;
    int l = col - 1;
    int r = col + 1;

    //条件判断这样写， 其他写法容易把墙直接跳过去接着跑
    while(u >= 0 && maze[u][col] == 0)
        u--;
    if(dfs(maze,u+1,col,dest)){
        return true;
    }else{
        //printf("%d %d u entry\n",u,col);
    }
    
    while(d < rowSize && maze[d][col] == 0)
        d++;
    if(dfs(maze,d - 1,col,dest)){
        return true;
    }else{
        //printf("%d %d d entry\n",d,col);
    }

    while(l >=0 && maze[row][l]==0)
        l--;
    if(dfs(maze,row,l+1,dest)){
        return true;
    }else{
        //printf("%d %d l entry\n",row,l);
    }

    while(r < colSize && maze[row][r]==0)
        r++;
    if(dfs(maze,row,r-1,dest)){
        return true;
    }else{
        //printf("%d %d r entry\n",row,r);
    }

    return false;
}



bool hasPath(int** maze, int mazeSize, int* mazeColSize, int* start, int startSize, int* destination, int destinationSize){
    memset(visit,0,500*500*sizeof(int));
    colSize = *mazeColSize;
    rowSize = mazeSize;
    printf(" %d %d \n",colSize,rowSize);
    return dfs(maze,start[0],start[1],destination);
}
```