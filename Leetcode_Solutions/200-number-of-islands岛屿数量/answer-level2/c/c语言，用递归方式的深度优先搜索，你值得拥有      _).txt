### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/58da168a6e09148ee6ce678048edbd007aed4655ab0dd010c9e9c09eeeba9c9b-image.png)

### 代码

```c
void DFS(char** grid, int gridSize, int* gridColSize,int r,int c)
{
    if(r < 0 || r > gridSize - 1 || c < 0 ||c > gridColSize[0] - 1 || grid[r][c] != '1')
    {
        return ;
    }

    grid[r][c] = '0';

    DFS(grid,gridSize,gridColSize,r,c-1);//up
    DFS(grid,gridSize,gridColSize,r,c+1);//down
    DFS(grid,gridSize,gridColSize,r-1,c);//left
    DFS(grid,gridSize,gridColSize,r+1,c);//right
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridSize == 0)
    {
        return 0;
    }

    int sum = 0;
    int row = gridSize;
    int col = gridColSize[0];

    
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j <col;j++)
        {
            if(grid[i][j] == '1')
            {
                sum++;
                DFS(grid,gridSize,gridColSize,i,j);
            }
        }
    }

    return sum;
}
```