### 解题思路
此处撰写解题思路

### 代码

```c
void myFindCircleNum(char **M, int **arr, int ROW, int COL, int row, int col)
{
    if (row >= 0 && row < ROW && col >= 0 && col < COL && (M[row][col] == '1') && (arr[row][col] == 0)) {        
            arr[row][col] = 1;
            myFindCircleNum(M, arr, ROW, COL, row - 1, col);
            myFindCircleNum(M, arr, ROW, COL, row + 1, col);
            myFindCircleNum(M, arr, ROW, COL, row, col - 1);
            myFindCircleNum(M, arr, ROW, COL, row, col + 1);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int **arr = NULL;
    int row = gridSize;
    int col = *gridColSize;
    int i, j, res = 0;

    if (grid == NULL || row <= 0) {
        return 0;
    }
     
    arr = (int **)malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        arr[i] = (int *)malloc(sizeof(int) * col);
        memset(arr[i], 0, sizeof(int) * col);
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (arr[i][j] == 0) {
                if (grid[i][j] == '1') {
                   myFindCircleNum(grid, arr, row, col, i, j);
                   res++; 
                }
            }
        }
    }
    
    return res;
}

```