**将矩形转为三角形来计算最小路径。**
考虑之前做的三角形找最小路径，当时使用从下往上找的办法做得挺快的，所以这里可以将这道题
转为同样的做法，复杂点的地方就在于转化的过程，转好了后就可以直接计算最小结果了。
```
// 先将m * n的正方形网格化为一个等边三角形再计算
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int **tmp;
    int row, col;
    int tmpRow, tmpCol;
    int gridCol = gridColSize[0];
    int totalSize = gridSize + gridCol - 1;            // 三角形总的行数等于行数加列数减1
    tmp = (int **)malloc(totalSize * sizeof(int *));     

    for (row = 0; row < totalSize; row++) {
        tmp[row] = (int *)malloc((row + 1) * sizeof(int));
        tmpRow = row;
        tmpCol = 0;
        for (col = 0; col <= row; col++) {                 // 填充三角形的内容
            if (tmpRow < gridSize && tmpCol < gridCol) {
                tmp[row][col] = grid[tmpRow][tmpCol];  
            } else if (tmpRow >= gridSize) {                          
                tmp[row][col] = grid[gridSize - 1][row - gridSize + 1];    
            } else if (tmpCol >= gridCol){
                tmp[row][col] = grid[row - gridCol + 1][gridCol - 1]; 
            }
            tmpRow--;
            tmpCol++;
        }
    }
    /* 最后从三角形从下往上算最小结果 */
    for (row = totalSize - 2; row >= 0; row--) {
        for (col = 0; col <= row; col++) {
            tmp[row][col] += (tmp[row + 1][col] < tmp[row + 1][col + 1]) ? tmp[row + 1][col] : tmp[row + 1][col + 1];
        }
    }
    int min = tmp[0][0];
    free(tmp);
    return min;
}

```

