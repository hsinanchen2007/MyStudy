### 解题思路
此处撰写解题思路

### 代码

```c
void DepthFirstSearch(int** grid, int gridSize, int* gridColSize, int x, int y, int* dx, int* dy, int* cnt)
{
    if (grid[x][y] == 0) {
        return;
    }
    grid[x][y] = 0;
    ++(*cnt);
    for (int k = 0; k < 4; ++k) {
        int newX = x + dx[k];
        int newY = y + dy[k];
        if (newX < 0 || newX >= gridSize || newY < 0 || newY >= gridColSize[0]) {
            continue;
        }
        DepthFirstSearch(grid, gridSize, gridColSize, newX, newY, dx, dy, cnt);
    }
    return;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if (!grid || gridSize <= 0 || gridColSize[0] <= 0) {
        return 0;
    }
    int cnt;
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    int ret = 0;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            cnt = 0;
            DepthFirstSearch(grid, gridSize, gridColSize, i, j, dx, dy, &cnt);
            if (cnt > ret) {
                ret = cnt;
            }
        }
    }
    return ret;
}
```