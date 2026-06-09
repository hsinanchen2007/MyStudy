### 解题思路
![image.png](https://pic.leetcode-cn.com/6c78a59432bd7f5f7d25d412d4275eb657b8f9eb402043aeed1502126dc29a3a-image.png)
效率一般，代码比较清晰



### 代码

```c
#define MAX(a, b) (a) > (b) ? (a) : (b)

int CheckLand(int **grid, int x, int y, int col, int line, int **vis)
{
    int count = 0;
    if (grid[x][y] == 0) {
        return 0;
    }

    if (vis[x][y] == 1) {
        return 0;
    }

    vis[x][y] = 1;
    count = 1;

    //检查同一行
    for (int i = y - 1; i >= 0; i--) {
        if (grid[x][i] == 0) {
            break;
        }
        count += CheckLand(grid, x, i, col, line, vis);
    }
    for (int i = y + 1; i < col; i++) {
        if (grid[x][i] == 0) {
            break;
        }
        count += CheckLand(grid, x, i, col, line, vis);
    }

    //检查同一列
    for (int i = x - 1; i >= 0; i--) {
        if (grid[i][y] == 0) {
            break;
        }
        count += CheckLand(grid, i, y, col, line, vis);
    }
    for (int i = x + 1; i < line; i++) {
        if (grid[i][y] == 0) {
            break;
        }
        count += CheckLand(grid, i, y, col, line, vis);
    }

    return count;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    //遍历每个节点，递归处理相连的节点
    int **vis = malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        vis[i] = malloc(sizeof(int) * gridColSize[i]);
        memset(vis[i], 0, sizeof(int) * gridColSize[i]);
    }

    // printf("gridSize: %d\n", gridSize);

    int maxCount = 0;
    int count;
    for (int i = 0; i < gridSize; i++) {
        // printf("gridColSize[%d]: %d\n", i, gridColSize[i]);
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 0) {
                continue;
            }

            count = CheckLand(grid, i, j, gridColSize[i], gridSize, vis);
            maxCount = MAX(maxCount, count);
        }
    }

    for (int i = 0; i < gridSize; i++) {
        free(vis[i]);
    }
    free(vis);

    return maxCount;
}
```