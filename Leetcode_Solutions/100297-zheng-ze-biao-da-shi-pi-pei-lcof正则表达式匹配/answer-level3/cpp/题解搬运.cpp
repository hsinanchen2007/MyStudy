### 解题思路
思路请看：
https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/
### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n  = s.size(),m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        dp[0][0] = 1;
        for(int i = 2; i <= m; i+=2)
        {
            if(p[i-1] == '*')
            {
                dp[0][i] = dp[0][i-2];
            }else
            {
                break;
            }
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == p[j-1]||p[j-1]=='.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1]=='*')
                {
                    if(s[i-1] == p[j-2] || p[j-2]=='.')
                    {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                    }else{
                        dp[i][j] = dp[i][j-2];//0
                    }
                }
            }
        }
        return dp[n][m];
    }
};
```