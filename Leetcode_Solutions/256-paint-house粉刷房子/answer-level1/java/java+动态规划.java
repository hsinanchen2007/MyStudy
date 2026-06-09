设dp[i][k]为刷到第i个房子选择颜色k时的最小成本，最终要求的就是dp[m-1][0],dp[m-1][1]...中的最小值
```
public class Solution {
    public int minCost(int[][] costs) {
        if (costs == null || costs.length == 0 || costs[0] == null || costs[0].length == 0) {
            return 0;
        }
        int m = costs.length;
        int n = costs[0].length;

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int k = j;
                costs[i][j] = Math.min(costs[i - 1][(++k) % n], costs[i - 1][(++k) % n]) + costs[i][j];
            }
        }
        int minValue = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            minValue = Math.min(minValue, costs[m - 1][j]);
        }
        return minValue;
    }
}

```
