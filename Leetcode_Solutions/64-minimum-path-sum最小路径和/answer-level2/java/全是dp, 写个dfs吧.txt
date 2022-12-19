

```
public int minPathSum(int[][] grid) {
    if(grid.length == 0) return 0;
    int m = grid[0].length, n = grid.length;
    return minPathSumDfs(m, n, new int[n][m], grid);
}

private int minPathSumDfs(int m, int n, int[][] cache, int[][] grid){
    if(m < 1 || n < 1) return Integer.MAX_VALUE;
    if(m == 1 && n == 1) return grid[n - 1][m - 1];
    if(cache[n-1][m-1] != 0 ) return cache[n-1][m-1] - 1; // 减去多加的1
    int sum = Math.min(minPathSumDfs(m - 1, n, cache, grid), minPathSumDfs(m, n - 1, cache, grid));
    cache[n-1][m-1] = sum + grid[n - 1][m - 1] + 1; // 让cache值至少是1
    return cache[n-1][m-1] - 1;
}  
```
