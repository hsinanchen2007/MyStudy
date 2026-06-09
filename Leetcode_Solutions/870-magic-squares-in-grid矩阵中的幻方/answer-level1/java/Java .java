![1.png](https://pic.leetcode-cn.com/989595faecb598e5dd72242f7b9964a26d5ffdcde5df870f05c6db84cfba34f9-1.png)


```java []
public int numMagicSquaresInside(int[][] grid) {
    int count = 0;
    boolean f = false;
    for (int i = 1; i < grid.length - 1; i++) {
        for (int j = 1; j < grid[i].length - 1; j++) {
            if (grid[i][j] == 5 && judge(i, j, grid) ) {
                count++;
                j++;
                f = true;
            }
        }
        if (f) {
            i++;
        }
        f = false;
    }
    return count;
}

private boolean judge(int i, int j, int[][] grid) {
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) {
                continue;
            }
            if (grid[i + k][j + l] < 1 || grid[i + k][j + l] > 9 || grid[i + k][j + l] == 5) {
                return false;
            }
        }
    }
    return grid[i - 1][j - 1] + grid[i + 1][j + 1] == 10 && grid[i - 1][j] + grid[i + 1][j] == 10
            && grid[i - 1][j + 1] + grid[i + 1][j - 1] == 10 && grid[i][j - 1] + grid[i][j + 1] == 10
            && grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] == 15
            && grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] == 15
            && grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] == 15
            && grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1] == 15;
}
```

