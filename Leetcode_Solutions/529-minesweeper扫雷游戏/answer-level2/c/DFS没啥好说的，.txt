个人理解DFS需要统计事项或者有什么花招都是在深搜里进行的，调节好入参即可。套路基本一样
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void Dfs(char** grid, int rows, int cols,int x, int y)
{
    if (grid[x][y] == 'E') {
        int M_nums = 0;
        if (x + 1 < rows && grid[x+1][y] == 'M') {
            M_nums++;
        } 
        if (x - 1 >= 0 && grid[x-1][y] == 'M') {
            M_nums++;
        } 
        if (y + 1 < cols && grid[x][y+1] == 'M') {
            M_nums++;
        }
        if (y - 1 >= 0 && grid[x][y-1] == 'M') {
            M_nums++;
        }
        if (x + 1 < rows && y - 1 >= 0 && grid[x+1][y-1] == 'M') {
            M_nums++;
        }
        if (x - 1 >= 0 && y - 1 >= 0 && grid[x-1][y-1] == 'M') {
            M_nums++;
        }
        if (x + 1 < rows && y + 1 < cols && grid[x+1][y+1] == 'M') {
            M_nums++;
        }
        if (x - 1 >= 0 && y + 1 < cols && grid[x-1][y+1] == 'M') {
            M_nums++;
        }
        
        if (M_nums) {
            grid[x][y] = '0'+ M_nums;
            return;
        } else {
            grid[x][y] = 'B';
            if (x - 1 >= 0 && grid[x-1][y] != 'M') {
                Dfs(grid, rows, cols, x - 1, y);
            } 
            if (x + 1 < rows && grid[x+1][y] != 'M') {
                Dfs(grid, rows, cols, x + 1, y);
            } 
            if (y - 1 >= 0 && grid[x][y-1] != 'M') {
                Dfs(grid, rows, cols, x, y - 1);
            }
            if (y + 1 < cols && grid[x][y+1] != 'M') {
                Dfs(grid, rows, cols, x, y + 1);
            }
            if (x - 1 >= 0 && y - 1 >= 0 && grid[x-1][y-1] != 'M') {
                Dfs(grid, rows, cols, x - 1, y - 1);
            } 
            if (x + 1 < rows && y - 1 >= 0 && grid[x+1][y-1] != 'M') {
                Dfs(grid, rows, cols, x + 1, y - 1);
            } 
            if (x - 1 >= 0 && y + 1 < cols && grid[x-1][y+1] != 'M') {
                Dfs(grid, rows, cols, x - 1, y + 1);
            }
            if (x + 1 < rows && y + 1 < cols && grid[x+1][y+1] != 'M') {
                Dfs(grid, rows, cols, x + 1, y + 1);
            }
        }
    } else {
        return;
    }
}

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    *returnColumnSizes = 0;
    int x = click[0], y = click[1];
    int rows = boardSize; 
    int cols = boardColSize[0];
    int* retColSizes = (int*)malloc(rows * sizeof(int)); // 返回的colsSize要自己申请内存去返回
    for (int i = 0; i < rows; i++) {
        retColSizes[i] = cols;
    }

    if (board[x][y] == 'M') {
        board[x][y] = 'X';
        *returnSize = rows;
        *returnColumnSizes = retColSizes;
        return board;
    }
    
    Dfs(board, rows, cols, x, y);
    /*
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    */
    *returnSize = rows;
    *returnColumnSizes = retColSizes; // 返回的colsSize要自己申请内存去返回
    return board;
}
```
