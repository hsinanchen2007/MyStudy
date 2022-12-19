```
class Solution {
    private static final int MOD = 1000000007;
    // 初始化条件： dp[1][k] = 1, 1<=k<=min(f,target)
    // 递推公式： dp[i][j] = dp[i-1][j-f[1]] + dp[i-1][j-f[2]] + ... + dp[i-1][j-f[n]]
    public int numRollsToTarget(int d, int f, int target) {
         int[][] dp = new int[d + 1][target + 1];
         for(int k=1;k<=(f>target ? target : f);k++) {
             dp[1][k] = 1;
         }
         for(int i=1;i<=d;i++) {
             for(int j=1;j<=target;j++) {
                for(int n=1;n<=f;n++) {
                    if(j>=n) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-n]) % MOD;
                    }
                }
             }
         }
         return dp[d][target];
    }
}
```
