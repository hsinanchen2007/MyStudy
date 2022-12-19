```java
class Solution {
    public int maxSumAfterPartitioning(int[] nums, int k) {
        int n = nums.length;
        // dp[i] = ans(nums[0]...nums[i-1])
        int[] dp = new int[n + 1];
        int[][] max = new int[n][n];
        for (int i = 0; i < n; i++) {
            max[i][i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                max[i][j] = Math.max(max[i][j - 1], nums[j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i && j <= k; j++) {
                dp[i] = Math.max(dp[i], dp[i - j] + max[i - j][i - 1] * j);
            }
        }
        return dp[n];
    }
}
```
