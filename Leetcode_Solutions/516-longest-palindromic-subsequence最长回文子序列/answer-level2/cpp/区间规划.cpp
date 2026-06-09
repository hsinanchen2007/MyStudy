### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0)return 0;
        //dp[0][n-1]表示0到n-1的最长回文长度
        //dp[0][n-1] = dp[1][n-2]+2，首尾两端的字符相等
        //dp[0][n-1] = max(dp[0][n-2], dp[1][n-1])，首尾两端字符不等
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;  //单个字符是回文
        }
        for(int len=2; len <= n; ++len)
        {
            //区间长度len从2增长到n
            for(int i = 0; i <= n-len; ++i)  //注意：i的最大值为n-len
            {
                //由len = j-i+1得j = i+len-1
                int j = i+len-1;
                if(s[i] == s[j])
                {
                    if(len == 2)
                    {
                        dp[i][j] = 2;  //区间长度为2，说明是初始状态
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
```