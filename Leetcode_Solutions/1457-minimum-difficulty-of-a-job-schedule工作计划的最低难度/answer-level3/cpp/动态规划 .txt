题意就是把一个数列分成d段, 要使每段的**最大值之和最小**.

设$f(i,j)$为前$i$个工作分成$j$段的最小值。

则
$f(i, 0) = 0$
$f(i, j) = min(f(k, j-1) + max(a[k], a[k+1], ..., a[i]) | 0 < k < i)$

使用动态规划转移即可。

时间复杂度$O(dn^2)$. 

从题意来看， 因为每一段的cost是这段的最大值，**感觉这道题可以优化**， 不是斜率优化就是单调队列优化。 这样的话即使d打到1e3也可顺利通过。 希望各位大佬找到这种优化办法。

```
class Solution {
public:

    int dp[303][12];
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if(n < d)return -1;

        memset(dp, -1, sizeof(dp));

        dp[0][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= d; j++){
                int maxv = jobDifficulty[i-1];
                for(int k = i - 1; k >= 0; k--){
                    if(dp[k][j-1] != -1){
                        int cur = dp[k][j-1] + maxv;
                        if(dp[i][j] == -1 || cur < dp[i][j])dp[i][j] = cur;
                    }

                    if(k > 0)maxv = max(maxv, jobDifficulty[k-1]);
                }
                //printf("%d %d %d\n",i,j,dp[i][j]);
            }
            
        }
        return dp[n][d];
    }
};
```
