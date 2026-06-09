第一次写题解，参考了一些大佬的做法，自己写了一个。不足之处还请指教。
这题是个动态规划的问题。第一步要设定dp[i][j]表示的是什么，这里表示s的前i个字符与p的前j个字符匹配。然后看初始化，dp[0][0]也就是空字符串和空字符串是匹配的。这里我还初始化了s为空的情况下dp的状态。最重要的一步也就是状态方程的建立。分类讨论p[j]。
1 如果p[j]等于s[i]或者p[j]等于万能的'.',那只要p的前j-1个字符和s的前i-1个字符匹配，dp[i][j]就为true；即dp[i][j] = dp[i-1][j-1];
2 如果p[j]等于'*'，那么只要dp[i][j-2]为true，则dp[i][j]也是true，因为*可以将*前的一个字符消掉，这是一种情况。如果p[j-1]=s[i]或者p[j-1]等于'.'，那么dp[i-1][j]成立或者dp[i][j-2]之中有一个为true则dp[i][j]就为true；即dp[i][j] = dp[i-1][j] || dp[i][j-2];
```
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(),m = p.size();
        p = ' ' + p,s = ' ' + s;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[0][0] = true;
        for(int j = 2;j<=m;j++)
        {
            if(p[j]== '*' && dp[0][j-2])
                dp[0][j] = true;
        }

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(j+1<=m && p[j+1] == '*') continue;//当下一个字符是*的时候，可以直接跳过
                if(p[j] == s[i] || p[j] == '.')
                    dp[i][j] = dp[i-1][j-1];
                if(p[j] == '*')
                {
                    if(j == 1) dp[i][j] = false;
                    else{
                        dp[i][j] = dp[i][j-2];
                        if(p[j-1] == s[i] || p[j-1] == '.')
                            dp[i][j] = (dp[i-1][j] || dp[i][j-2]);
                    }
                }
            }
        }

        return dp[n][m];
    }
};
```

