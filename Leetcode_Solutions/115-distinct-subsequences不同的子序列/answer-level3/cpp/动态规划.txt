- dp[i][j] 的含义：
以 T 字符串的前 i 个为子字符串， 以 S 字符串的前 j 个为子字符串时， T'(T[0...i]) 在 S'(S[0...j]) 中的个数
- 怎么求dp[i][j]:
T'(T[0...i]) 在 S'(S[0...j]) 中的个数 一定 包含 T' 在 S''(S[0 ... j - 1]) 中的个数即 dp[i][j - 1]；如果在 T[i] == S[j] 的情况下，
两个子字符串各去掉最后一个字符变成T''(T[0 ... i - 1]) 在 S''(S[0 ... j - 1]) 中的个数即 dp[i - 1][j - 1], 此时 dp[i][j] 一定也包含
dp[i - 1][j - 1], 比如 s = "abc" , t = "ac" ,最后字符相等, 那么 t 在 s 中个数 和 t' = "a" 在 s' = "ab" 中的个数相等。所以最后的动态
转移方程为: dp[i][j] = dp[i][j - 1] + (T[i] == S[j] ? dp[i-1][j-1] : 0)
```
class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        if(m <= 0)
        {
            return 1;
        }
        if(m > 0 && n <= 0)
        {
            return 0;
        }
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0)); //考虑空字符串
        for(int j = 0; j < n + 1; j++)
        {
            dp[0][j] = 1; // 所有在S中的子字符串都可以由空字符串得到
        }
        //S的长度必须大于T的长度
        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                long a1 = dp[i][j - 1];
                long a2 = 0;
                if(t[i - 1] == s[j - 1])
                {
                    a2 = dp[i - 1][j - 1];
                }
                dp[i][j] = a1 + a2;
            }
        }
        return dp[m][n];
    }
};
```
