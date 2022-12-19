dp[i][target]表示用前i个骰子投出target的可能组合数

状态转移方程为:
dp[i][target] = sum{dp[i-1][target-k], k >= 1 && k <= f && target-k >= 0}
由于当前状态只与上一状态的之前状态有关，所以，可以从上往下，从右往左遍历，这样只要一维的dp数组就可以了

```
  public int numRollsToTarget(int d, int f, int target) {
    int MOD = 1_000_000_007;
    int[] dp = new int[target+1];
    for (int i = 1; i <= f && i <= target; i++) {
      dp[i] = 1;
    }

    for (int i = 2; i <= d; i++) {
      for (int j = target; j >= i; j--) {
        dp[j] = 0;
        for (int k = 1; k <= f && j-k >= 0; k++) {
          dp[j] += dp[j-k];
          dp[j] %= MOD;
        }
      }
      dp[i-1] = 0;
    }
    return dp[target];
  }
```
