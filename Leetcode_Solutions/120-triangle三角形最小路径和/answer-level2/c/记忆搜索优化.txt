# 思路
思路很简单，就是遍历所有的路径，并保存和值最小的子路径的和，防止再次计算。通过一个二维数组来保存这些最优子路径的数值。
# 代码
```
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int i = 0;
    int j = 0;
    
    int **dp  =  (int **)calloc(triangleSize, sizeof(int **));
    for (i = 0; i < triangleSize; i++) {
        dp[i] = (int *)calloc(triangleColSize[i], sizeof(int));
    }
    
    int result = slove(triangle, triangleSize, triangleColSize, 0,0, triangle[0][0], dp);
    
    for (i = 0; i < triangleSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}
int slove(int** triangle, int triangleSize, int* triangleColSize, int row, int col, int current, int **dp) {
    if (dp[row][col] != 0) {
        return dp[row][col];
    }
    if (row == triangleSize-1) {
        return triangle[row][col];
    }
    int left = slove(triangle, triangleSize, triangleColSize, row+1, col, current+triangle[row+1][col], dp);
    int right = slove(triangle, triangleSize, triangleColSize, row+1, col+1, current+triangle[row+1][col+1], dp);
    dp[row][col] = left > right ? right + triangle[row][col]: left + triangle[row][col];
    return dp[row][col];
}
```
