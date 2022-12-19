### 解题思路
和200题基本思路一致，只是DFS获取的结果有所不同，200题会了，这个题也没啥难度。

### 代码

```c
#define MAX(a , b) ((a) > (b)) ? (a) : (b)
void DFS(int **grid, int x, int y, int *ans, int n, int m)
{
    if (x - 1 >= 0 && grid[x - 1][y] == 0 && x + 1 < n && grid[x + 1][y] == 0 &&
        y - 1 >= 0 && grid[x][y - 1] == 0 && y + 1 < m && grid[x][y + 1] == 0 ) {
           return;
       }
       
       if (x - 1 >= 0 && grid[x - 1][y] == 1) {grid[x - 1][y] = 0; (*ans)++; DFS(grid, x - 1, y, ans, n, m);}
       if (x + 1 < n  && grid[x + 1][y] == 1) {grid[x + 1][y] = 0; (*ans)++; DFS(grid, x + 1, y, ans, n, m);}
       if (y - 1 >= 0 && grid[x][y - 1] == 1) {grid[x][y - 1] = 0; (*ans)++; DFS(grid, x, y - 1, ans, n, m);}
       if (y + 1 < m  && grid[x][y + 1] == 1) {grid[x][y + 1] = 0; (*ans)++; DFS(grid, x, y + 1, ans, n, m);}
       return;

}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int ans = 0;
    for (int i =0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                int temp = 1;
                grid[i][j] = 0;
                DFS(grid, i, j, &temp, gridSize, *gridColSize);
                ans = MAX(ans, temp);
            }
        }

    }
    
    return ans;
}
```