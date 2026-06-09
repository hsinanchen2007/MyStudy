### 解题思路
dfs先求所有解，再qsort排序一下结果,用dp数组记录一下临时结果，减少开销

### 代码

```c
int dfs(int** land, int landSize, int* landColSize, int row, int col, int (*dp)[1001])
{
    if (row < 0 || row >= landSize)
        return 0;
    if (col < 0 || col >= landColSize[row])
        return 0;
    if (dp[row][col])
        return 0;
    if (land[row][col] != 0) {
        dp[row][col] = 1;
        return 0;
    }

    int count = 1;
    dp[row][col] = 1;
    count += dfs(land, landSize, landColSize, row - 1, col -1, dp);
    count += dfs(land, landSize, landColSize, row - 1, col, dp);
    count += dfs(land, landSize, landColSize, row - 1, col + 1, dp);
    count += dfs(land, landSize, landColSize, row, col - 1, dp);
    count += dfs(land, landSize, landColSize, row, col + 1, dp);
    count += dfs(land, landSize, landColSize, row + 1, col - 1, dp);
    count += dfs(land, landSize, landColSize, row + 1, col, dp);
    count += dfs(land, landSize, landColSize, row + 1, col + 1, dp);
    return count;
}
int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize)
{
    int *ans = (int *)malloc(650000 * sizeof(int));
    int count = 0;
    int dp[1001][1001] = {0};

    for (int row = 0; row < landSize; row++) {
        for (int col = 0; col < landColSize[row]; col++) {
            int tmp = dfs(land, landSize, landColSize, row, col, dp);
            if (tmp != 0) {
                // printf("%d ", tmp);
                ans[count++] = tmp;
            }
        }
    }
    // for (int i = 0; i < count; i ++) {
    //     printf("%d ", ans[i]);
    // }
    qsort(ans, count, sizeof(int), compare);
    // returnSize = (int *)malloc(1 * sizeof(int));
    *returnSize = count;
    // for (int i = 0; i < count; i ++) {
    //     printf("%d ", ans[i]);
    // }
    return ans;
}
```