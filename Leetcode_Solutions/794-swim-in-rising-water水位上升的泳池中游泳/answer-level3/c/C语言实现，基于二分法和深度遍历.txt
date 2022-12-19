#define TRUE 1
#define FALSE 0
int DFS(int** grid,int** visited, int gridSize, int* gridColSize,int row,int column,int midVal)
{
    //数字不在范围内则退出
    if (row <0 || column<0 || row>=gridSize || column>=gridColSize[row])
    {
        return FALSE;
    }    
    else if ((row == gridSize - 1) && (column == (gridColSize[gridSize - 1]-1)))//找到最右下角的位置
    {
        if (grid[row][column]<=midVal)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }    
    if (0 == visited[row][column])
    {
        visited[row][column] = 1;
        if (grid[row][column]<=midVal)
        {
            if (DFS(grid, visited,gridSize, gridColSize,row+1,column,midVal))
            {
                return TRUE;
            }
            else if (DFS(grid, visited,gridSize, gridColSize,row-1,column,midVal))
            {
                return TRUE;
            }
            else if (DFS(grid, visited,gridSize, gridColSize,row,column+1,midVal))
            {
                return TRUE;
            }
            else if (DFS(grid, visited,gridSize, gridColSize,row,column-1,midVal))
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}

int swimInWater(int** grid, int gridSize, int* gridColSize){
int i = 0;
int j = 0;
int maxVal = -65535;//最大值保存变量，设置初始值为最小
int minVal = 65535;
int midVal = 0;
int goalVal = 65535;
int **visited = NULL;
//遍历grid的行列，获取最小和最大元素
for (i = 0;i<gridSize;i++)
{
    for(j = 0;j<gridColSize[i];j++)
    {
        if (grid[i][j]>maxVal)
        {
            maxVal = grid[i][j];
        }
        if (grid[i][j]<minVal)
        {
            minVal = grid[i][j];
        }
    }
}
/*
    int **gridvisited=(int **)malloc(sizeof(int*)*gridSize);
    for(int i=0;i<gridSize;i++){//一个标志数组
        gridvisited[i]=(int*)calloc(gridColSize[i],sizeof(int));
    }
*/
//申请跟grid一样大小的二维数组空间
visited = (int **)malloc(gridSize * sizeof(int *));
for(i = 0;i<gridSize;i++)
{
    visited[i] = (int *)calloc(gridColSize[i],sizeof(int));
}
midVal = (minVal + maxVal)/2;
while ((midVal>= minVal) && (midVal<=maxVal))
{
    //每次循环开始，清零visited
    for(i = 0;i<gridSize;i++)
    {
       memset(visited[i],0,gridColSize[i] * sizeof(int));
    }
    if (DFS(grid, visited,gridSize, gridColSize,0,0,midVal))
    {
        goalVal = goalVal>midVal?midVal:goalVal;
        maxVal = midVal - 1;
        midVal = (minVal + maxVal)/2;
    }
    else
    {
        minVal = midVal + 1;
        midVal = (minVal + maxVal)/2;
    }
}

for(i = 0;i<gridSize;i++)
{
    free(visited[i]);
}
free(visited);
return goalVal;
}