### 解题思路
找到一个点，遍历完所有能到的位置，然后找顶一个开始的点，

### 代码

```c
void FindIsland(char** grid, int x, int y, int m, int n, int** visit, int* count)
{
    if (x > m || y > n || x < 0 || y < 0 || visit[x][y] == 1 || grid[x][y] == '0') {
        return;
    }
    visit[x][y] = 1; // 访问过了
    // 向上
    FindIsland(grid, x-1, y, m, n, visit,count);
    // 向右
    FindIsland(grid, x, y+1, m, n, visit,count);
    // 向下
    FindIsland(grid, x+1, y, m, n, visit,count);
    // 向左
    FindIsland(grid, x, y-1, m, n, visit,count);
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int** visit = NULL;
    int count = 0;
    visit = (int**)calloc(gridSize, sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        visit[i] = (int *)calloc(*gridColSize, sizeof(int));
    }
    // 找从0,0位置出发的岛屿数量，遍历过的点记录下来。
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (visit[i][j] == 0 && grid[i][j] == '1') {
                count++; // 岛屿数量增加，在第count个岛屿上趟遍所有的陆地
                FindIsland(grid, i, j, gridSize-1, *gridColSize - 1, visit, &count);
                //printf("island:%d, start(%d,%d),%d,%d\n",count,i,j,gridSize-1, *gridColSize-1);
            }
        }
    }
    
    for (int i = 0; i < gridSize; i++) {
        free(visit[i]);
    }
    free(visit);
    return count;
}
```