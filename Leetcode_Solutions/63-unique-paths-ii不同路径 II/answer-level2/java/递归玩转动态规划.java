- 在64题的基础上加了障碍物，所以要稍微改动一下递归的思路。
![不同路径 II](https://pic.leetcode-cn.com/27c471bdf6da1908eb3a8b3e70c63cfb7b5d50303c3118c1b0db4a3370119a5a.png)
- 改一下暴力递归的代码（超时）
```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        return getRes(obstacleGrid,0,0,m,n);
    }

    private int getRes(int[][] obstacleGrid, int r, int c, int m, int n) {
        if(obstacleGrid[r][c] == 1) return 0;
        if(r == m - 1 && c == n - 1) return 1;
        if(r == m - 1) return getRes(obstacleGrid,r,c + 1,m,n);  // 向右走
        if(c == n - 1) return getRes(obstacleGrid,r + 1,c,m,n);  // 向下走
        return getRes(obstacleGrid, r + 1, c, m, n) + getRes(obstacleGrid, r, c + 1, m, n);
    }
}
```
- 补充一个哈希map提升性能的代码(可以AC)
```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        HashMap<String, Integer> memo = new HashMap<>();
        return getRes(obstacleGrid, 0, 0, m, n, memo);
    }

    private int getRes(int[][] obstacleGrid, int r, int c, int m, int n, HashMap<String, Integer> memo) {
        if (obstacleGrid[r][c] == 1) return 0;
        if (r == m - 1 && c == n - 1) return 1;
        String key = r + "@" + c;
        if (memo.containsKey(key)) return memo.get(key);
        if (r == m - 1) {
            int right = getRes(obstacleGrid, r, c + 1, m, n, memo);
            memo.put(key, right);
            return right;  // 向右走
        }
        if (c == n - 1) {
            int down = getRes(obstacleGrid, r + 1, c, m, n, memo);
            memo.put(key, down);
            return down;  // 向下走
        }
        int ans = getRes(obstacleGrid, r + 1, c, m, n, memo) + getRes(obstacleGrid, r, c + 1, m, n, memo);
        memo.put(key, ans);
        return ans;
    }
}
```
- 递归改动态规划，直接按照递归的逻辑来
```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = 1;
                } else if (i == m - 1) {
                    dp[i][j] = dp[i][j + 1];
                } else if (j == n - 1) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
}
```

- 空间上一样可以优化
```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[] dp = new int[n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }
                if (i == m - 1 && j == n - 1) {
                    dp[j] = 1;
                } else if (i == m - 1) {
                    dp[j] = dp[j + 1];
                } else if (j == n - 1) {
                    dp[j] = dp[j];
                } else {
                    dp[j] = dp[j] + dp[j + 1];
                }
            }
        }
        return dp[0];
    }
}
```