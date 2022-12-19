### 解题思路
此处撰写解题思路

### 代码

```c
#define DIRECTON 4

inline int Max(int a, int b)
{
    return a > b ? a : b;
}

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    if (!grid || gridSize <= 0) {
        return 0;
    }
    int colMax = gridColSize[0];
    int* dx = (int*)malloc(sizeof(int) * DIRECTON);
    int* dy = (int*)malloc(sizeof(int) * DIRECTON);
    dx[0] = -1;dx[1] = 0;dx[2] = 1;dx[3] = 0;
    dy[0] = 0;dy[1] = 1;dy[2] = 0;dy[3] = -1;
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < colMax; j++) {
            if (grid[i][j] > 0) {
                ret += 2;
            }
            for (int k = 0; k < DIRECTON; k++) {
                int r = i + dx[k];
                int c = j + dy[k];
                int h = 0;
                if (r >= 0 && r < gridSize && c >= 0 && c < colMax) {
                    h = grid[r][c];
                }
                ret += Max(grid[i][j] - h, 0);
            }
        }
    }
    free(dx);
    free(dy);
    return ret;
}
```