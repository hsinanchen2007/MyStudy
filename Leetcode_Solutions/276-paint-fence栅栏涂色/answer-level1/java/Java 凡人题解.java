分2中情况进行分析：
1、第i个栅栏颜色与i-1个栅栏颜色不同：
第i-2个栅栏的涂色方案有dp[i-2]，第i-1个栅栏可以涂k-1种颜色，这种情况下涂色的方案有：dp[i] = dp[i-2]*(k-1)
2、第i个栅栏颜色与i-1个栅栏颜色相同：
当前栅栏可涂的颜色有k-1种，所以dp[i] = dp[i -1]*(k-1)

所有递推的公式是：dp[i] = dp[i-2]*(k-1) + dp[i -1]*(k-1)

class Solution {
    public int numWays(int n, int k) {
        if (n < 1 || (k < 1)) {
            return 0;
        }
        if (n == 1) {
            return k;
        }
        int ret = 0;
        int[] dp = new int[n + 1];
        dp[0] = k;
        dp[1] = k * k;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 2] * (k - 1) + dp[i - 1] * (k - 1);
        }
        return dp[n - 1];

    }
}