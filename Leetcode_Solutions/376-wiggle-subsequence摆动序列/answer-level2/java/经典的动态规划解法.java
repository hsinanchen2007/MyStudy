这是个经典的动态规划问题，跟股票问题很像，这道题我们定义两种状态。

dp[i][0]表示从nums[0]到nums[i]的最长摆动序列长度，且nums[i] < nums[i - 1]，dp[i][1]表示从nums[0]到nums[i]的最长摆动序列长度，且nums[i] > nums[i - 1 ]。

```
public int wiggleMaxLength(int[] nums) {
    int n = nums.length;
    if (n <= 1) return n;
    int[][] dp = new int[n][2];
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][0] + 1;
        } else if (nums[i] < nums[i - 1]) {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = dp[i - 1][1];
        } else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }
    }
    return Math.max(dp[n - 1][0], dp[n - 1][1]);
}
```
