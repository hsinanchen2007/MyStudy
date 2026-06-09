这道题状态转移方程很好想 就是dp[i][j] = dp[i-1][j] + dp[i-1][j+1] + dp[i-1][j-1];(i代表走了i+1步,j代表到达数组的第j个Index)
遇到的问题是如果arrLen为10^6时会爆内存
但其实根本不可能到达10^6 最多走steps步 所以我取了两个的更小值作为j 表示最远能走的距离
```
class Solution {
    public int numWays(int steps, int arrLen) {
        if(steps == 0 || arrLen == 0)
            return 0;
        if(steps == 1 || arrLen == 1)
            return 1;
        int mod = 1000000007;
        int len = Math.min(steps, arrLen);//求一下steps和arrLen的最小值 这个值是能到达的最远距离
        int[][] dp = new int[steps][len];//走i+1步到达j时的可能数量
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < steps; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(j == 0)
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
                else if(j == len - 1)
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
                else
                    dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1]) % mod + dp[i - 1][j + 1]) % mod;
            }
        }
        return dp[steps - 1][0];
    }
}
```
