### 解题思路
和粉刷房子一样，只是把3种颜色变成了n种颜色，多一次遍历就完事了
### 优化思路
这种解法的时间复杂度是N * K * K，事实上可以简化，我遍历每一行的每一个元素时都求了一次上一行的最小价格，所以我可以把这个过程拿到外面，每一行遍历完都求出该行的最小值和第二小的值，这样dp[i][j] = j == previous ? secondMin + costs[i][j] : Min + costs[i][j]，就是N * K的是时间复杂度了  
### 代码

```java
class Solution {
    public int minCostII(int[][] costs) {
        int row = costs.length;
        if (row == 0) return 0;
        int col = costs[0].length;
        int[][] dp = new int[row][col];
        for (int i = 0; i < col; i++) dp[0][i] = costs[0][i];
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = 0; k < col; k++) {
                    if (k == j) continue;
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][k]);
                }
                dp[i][j] += costs[i][j]; 
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < col; i++) res = Math.min(res, dp[row - 1][i]);
        return res;
    }
}
```