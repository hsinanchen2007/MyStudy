/*
    这道题的思路就是找到两个数值，分别代表每一行的最大值和每一列的最大值
    然后遍历这个二维矩阵，对于其中的每一个元素，增加到的值不能大于改行和该列的最大值
*/
int maxIncreaseKeepingSkyline(int **grid, int gridSize, int *gridColSize)
{
    if (!grid || gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }
    int *row_max = (int *)malloc(gridSize * sizeof(int));
    int *col_max = (int *)malloc(gridSize * sizeof(int));
    memset(row_max, 0, gridSize);
    memset(col_max, 0, gridSize);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            row_max[i] = row_max[i] > grid[i][j] ? row_max[i] : grid[i][j];
            col_max[i] = col_max[i] > grid[j][i] ? col_max[i] : grid[j][i];
        }
        printf("row_max[i]=%d, col_max[i]=%d\n",row_max[i],col_max[i]);
    }
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            tmp = row_max[i] > col_max[j] ? col_max[j] : row_max[i];
            ans += (tmp - grid[i][j]);
        }
    }
    return ans;
}