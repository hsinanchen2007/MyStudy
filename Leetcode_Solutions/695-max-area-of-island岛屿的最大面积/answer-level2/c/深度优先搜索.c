### 解题思路
深度优先搜索
伪代码
关键在于找到某节点后，则针对这个节点展开搜索，但是仍在堆栈中调用本函数，针对此节点的下一个节点，其实是深度搜索，而非广度。
![image.png](https://pic.leetcode-cn.com/9b62f4193c53cdbff69812050fbda7d920b9816a2c74a9678e12aa07fd679e29-image.png)


### 代码

```c
int MaxCount(int** grid, int i, int j, int gridSize, int* gridColSize, int** visit)
{
    int count = 1;
    visit[i][j] = 1;
    if (i + 1 < gridSize && grid[i + 1][j] && !visit[i + 1][j]) {
        count += MaxCount(grid, i + 1, j, gridSize, gridColSize, visit);
    }
    if (i - 1 >= 0 && grid[i - 1][j] && !visit[i - 1][j]) {
        count += MaxCount(grid, i - 1, j, gridSize, gridColSize, visit);
    }
    if (j + 1 < gridColSize[i] && grid[i][j + 1] && !visit[i][j + 1]) {
        count += MaxCount(grid, i, j + 1, gridSize, gridColSize, visit);
    }
    if (j - 1 >= 0 && grid[i][j - 1] && !visit[i][j - 1]) {
        count += MaxCount(grid, i, j - 1, gridSize, gridColSize, visit);
    }
    return count;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int **visit = (int **)calloc(1, sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        visit[i] = (int *)calloc(1, sizeof(int) * (gridColSize[i]));
    }
    // memset(visit, 0, sizeof(visit));
    int i, j;
    int maxRes = 0;
    int cnt = 0;
    int row = gridSize;

    for (i = 0; i < row; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1 && visit[i][j] == 0) {
                // visit[i][j] = 1;
                cnt = MaxCount(grid, i, j, gridSize, gridColSize, visit);
                maxRes = maxRes > cnt ? maxRes : cnt;
            }
        }
    }
    return maxRes;
}
```