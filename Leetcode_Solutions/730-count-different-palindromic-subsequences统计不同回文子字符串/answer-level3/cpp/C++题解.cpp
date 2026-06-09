```

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        long long mod = 1000000007;
        int n = S.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j + i < n; ++j)
            {
                int t1 = j, t2 = j + i;
                if(S[t1] == S[t2])
                {
                    int l = t1+1;
                    int r = t2-1;
            
                    // 从左找到的第一个等于s[t1]和从右开始往左找到的第一个s[t1]的位置的关系。
                    // l < r 里面有两个，那么2 * 之后，那两个里面的和S[t1],S[t2]构成的重复了，所以要减去。
                    // l == r   * + 1, 里面有一个等于，那只加1(c(1) + cc(1))
                    // l > r : 2 * dp[t1+1][t2-1] + 2 ， *2是因为里面的所有回文子序列加上S[t1],S[t2]又构成同样数量的回文字符串序列。
                    while(l <= r && S[l] != S[t1]) ++l;
                    while(r >= l && S[r] != S[t1]) --r;
                    dp[t1][t2] = 2 * dp[t1+1][t2-1];
                    if(l == r)
                         dp[t1][t2] += 1;
                    else if(l < r)
                        dp[t1][t2] -= dp[l+1][r-1];
                    else
                        dp[t1][t2] += 2;
                }
                 // 如果不想等，子序列的开头和结尾肯定两个不能同时出现
                    // 1.只让t1出现
                    // 2.只让t2出现
                    // 3.t1与t2都不出现
                    // 1 + 3 = dp[t1][t2-1]
                    // 2 + 3 = dp[t1+1][t2]
                    // 3 = dp[t1+1][t2-1]
                else 
                {
                    dp[t1][t2] = dp[t1][t2-1] + dp[t1+1][t2] - dp[t1+1][t2-1];
                }
                
                dp[t1][t2] = (dp[t1][t2] + mod) % mod;
            }
        }
        return dp[0][n-1];
    }
};
```
