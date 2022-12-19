```Java
class Solution {
    public int numRollsToTarget(int d, int f, int target) {
        int[] dp = new int[target+1];
        for (int i = 1; i <= f && i <= target; i++) {
            dp[i] = 1;
        }
        for (int i = 1; i < d; i++) {
            for (int j = target; j > 0; j--) {
                int sum = 0;
                for (int k = 1; k <= f && k <= j; k++) {
                    sum = (sum + dp[j-k]) % 1000000007;
                }
                dp[j] = sum;
            }
        }
        return dp[target];
    }
}
```