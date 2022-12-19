- 递归思路如下：
![最小路径和](https://pic.leetcode-cn.com/62cb5eb8f3fb25d8983bf05d4944fc60c4d5ad6d410f3bab782bc44bef717110.png)
- 递归代码实现
```
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        return getRes(grid,0,0,m,n);
    }

    private int getRes(int[][] grid, int r, int c, int m, int n) {
        if(r == m - 1 && c == n - 1) return grid[m - 1][n - 1];
        if(r == m - 1) return grid[r][c] + getRes(grid, r, c + 1, m, n);
        if(c == n - 1) return grid[r][c] + getRes(grid, r + 1, c, m, n);
        return grid[r][c] + Math.min(getRes(grid, r + 1, c, m, n),getRes(grid, r, c + 1, m, n));
    }
}
```
- memo优化
```
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        HashMap<String,Integer> memo = new HashMap<>();
        return getRes(grid,0,0,m,n,memo);
    }

    private int getRes(int[][] grid, int r, int c, int m, int n, HashMap<String,Integer> memo) {
        if(r == m - 1 && c == n - 1) return grid[m - 1][n - 1];
        String key = r + "@" + c;
        if(memo.containsKey(key)) return memo.get(key);
        if(r == m - 1) {
            int right = grid[r][c] + getRes(grid, r, c + 1, m, n, memo);
            memo.put(key,right);
            return right;
        }
        if(c == n - 1) {
            int down = grid[r][c] + getRes(grid, r + 1, c, m, n, memo);
            memo.put(key,down);
            return down;
        }
        int ans = grid[r][c] + Math.min(getRes(grid, r + 1, c, m, n, memo), getRes(grid, r, c + 1, m, n, memo));
        memo.put(key,ans);
        return ans;
    }
}
```
- 动态规划
```
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = grid[i][j];
                } else if (i == m - 1) {
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                } else if (j == n - 1) {
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                } else {
                    dp[i][j] = grid[i][j] + Math.min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
}
```
- dp数组降维
```
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] dp = new int[n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    dp[j] = grid[i][j];
                } else if (i == m - 1) {
                    dp[j] = grid[i][j] + dp[j + 1];
                } else if (j == n - 1) {
                    dp[j] = grid[i][j] + dp[j];
                } else {
                    dp[j] = grid[i][j] + Math.min(dp[j], dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
}
```