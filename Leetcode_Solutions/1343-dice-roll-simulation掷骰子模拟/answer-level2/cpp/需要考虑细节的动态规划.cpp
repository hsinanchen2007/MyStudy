令dp[i][j] : 第j位为i的合法方案数
则不考虑rollMax[i]约束的情况下，dp[i][j]的递推公式应该是
dp[i][j] += dp[k][j-1],k=[1..6] 

现在来减去不满足rollMax[i]约束的情况
考虑dp[i][j]中违反rollMax[i]的情况
一定是位置:j-rollMax[i] 到 位置: j-1 已经都为 i 时， 此时再在第j个位置填 i 就是违反约束的
那么减去所有这样的情况
dp[i][j] -= dp[k][j-rollMax[i]-1], k=[1..6]//注意不是减dp[k][j-rollMax[i]]
但是多减了一个情况即 dp[i][j-rollMax[i]-1]
原因是因为，dp[i][j-1] 为第j个位置填i的所有合法方案数
在这个方案中若 位置j-rollMax[i]-1 为i， 那么 位置j-rollMax[i] 到 位置j-2不可能都为 i
因为这样dp[i][j-1]（第j-1个位置填i就不合法了）就不是所有的合法方案数了，也就是说dp[i][j] 在从dp[i][j-1]转移过来的时候就已经排除了位置j-rollMax[i]-1为i且违反约束的所有情况
所以dp[i][j] += dp[i][j-rollMax[i]-1];

边界情况考虑
当j-rollMax[i]-1为0时
此时只需要减1就行了
因为dp[k][0] = 1
如果还是dp[i][j] -= p[k][j-rollMax[i]-1], k=[1..6]这样减的话，第零位是没有数字的，就重复减去了，实际上只需要减一次

这道题需要考虑的细节还是挺多的

```
class Solution {
public:
    long long MOD = 1e9+7;
    long long dp[10][5007];
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; i++) dp[i][0] = 1, dp[i][1] = 1;
        for (int j = 2; j <= n; j++)
        {
            for (int i = 1; i <= 6; i++)
            {
                for (int k = 1; k <= 6; ++k)
                {
                    dp[i][j] = (dp[i][j] + dp[k][j-1]) % MOD;   
                }
                //if (j-rollMax[i-1] >= 0)
                //    dp[i][j] = (dp[i][j] - dp[i][j-rollMax[i-1]] + MOD) % MOD;   
                //解释上面这样的减法为什么是错的，我想减去的是j-rollMax[i]->j-1位置都是i的个数，并不是减 dp[i][j-rollMax[i]] 而是减dp[k][j-rollMax[k]-1] k[1->6] !!
                //cout << dp[i][j] << endl;
                if (j-rollMax[i-1]-1 > 0)
                {
                    for (int k = 1; k <= 6; ++k)
                    {
                    //trap 比较难想这里，多减了一个重复情况, 要除去
                        if (k != i)
                            dp[i][j] = (dp[i][j] - dp[k][j-rollMax[i-1]-1] + MOD) % MOD;
                    }                    
                }
                else if (j-rollMax[i-1]-1 == 0) (dp[i][j] = dp[i][j] - 1 + MOD) % MOD;
                //cout << dp[i][j] << endl;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= 6; i++) ans = (ans + dp[i][n]) % MOD;
        return ans;
    }
    
};
```





