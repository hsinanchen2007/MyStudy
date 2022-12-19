### 解题思路
此处撰写解题思路

### 代码

```c
#define VIST_FLG 1
int g_dir[4][2] = {
    {0,1},
    {0,-1},
    {1, 0},
    {-1, 0}
};

void printGrid(int **grid, int rowSize, int colSize)
{
    int i;
    int j;
    for (i = 0; i < rowSize; i++) {
        for (j = 0; j < colSize; j++) {
            printf("%u ", grid[i][j]);
        }
        printf("\n");
    }

    return;
}

int isValidCorrd(int row, int col, int rowSize, int colSize)
{
    if (row < 0 || row > rowSize - 1) {
        return 0;
    }

    if (col < 0 || col > colSize - 1) {
        return 0;
    }
    return 1;
}

int isBoundary (int row, int col, int rowSize, int colSize) {
    if (row == 0 || row == rowSize - 1 || col == 0 || col == colSize - 1) {
        // printf("isBoundary row:%u, col:%u, rowSize:%u, colSize:%u\r\n", row, col, rowSize, colSize);
        return 1;
    }
    return 0;
}

void dfs(int row, int col, int **grid, int rowSize, int colSize, int *val)
{
    int i;
    int tempRow;
    int tempCol;
    int ret = 0;
    if (grid == NULL) {
        return;
    }

    if (isValidCorrd(row, col, rowSize, colSize) != 1) {
        return;
    }

    if (grid[row][col] == VIST_FLG) {
        return;
    }

    // printf("dfs row:%u, col:%u \r\n", row, col);
    /* 如果是边界则设置val为0，表示非封闭区域 */  
    if (isBoundary(row, col, rowSize, colSize)) {
        *val = 0;
        return;
    }
    grid[row][col] = VIST_FLG;
    // printGrid(grid, rowSize, colSize);
    
    for (i = 0 ; i< 4; i++) {
        tempRow = row + g_dir[i][0];
        tempCol = col + g_dir[i][1];
        dfs(tempRow, tempCol, grid, rowSize, colSize, val);
    }
    return;
}

int closedIsland(int** grid, int gridSize, int* gridColSize)
{
    int i;
    int j;
    int cnt = 0;
    int val;
    if (grid == NULL || gridColSize == NULL) {
        return 0;
    }
    if (gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) {
                // printf("closedIsland i:%u, j:%u \r\n", i, j);
                val = 1;
                dfs(i, j, grid, gridSize, gridColSize[0], &val);
                cnt +=val;
                // printf("cnt:%u \r\n", cnt);
            }
           
        }
    }
    return cnt;
}
```
![image.png](https://pic.leetcode-cn.com/345d76f8de04beb2789cba08a4018695dcad12aa503cf752f7bfe47cb1fd8f56-image.png)
