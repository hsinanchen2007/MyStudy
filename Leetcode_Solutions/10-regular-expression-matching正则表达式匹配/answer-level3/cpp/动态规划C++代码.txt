看了这么多题解，好像没有用C++写的。。我大C++怎能如此颓废？
直接上代码吧，是看了[@kao-la-7](/u/kao-la-7/)的题解的思路之后完成的，感谢大佬的题解！
```
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0 && s.length() == 0)
            return true;
        else if (p.length() == 0)
            return false;
        // 多一行一列空的
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, 0));
        dp[0][0] = 1;  // 空和空匹配
        for (int j = 2; j <= (int)p.length(); j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-2];
        }
        if (s.length() == 0)
            return dp[0][p.length()];
        dp[1][1] = ((s[0] == p[0]) || (p[0] == '.'));
        for (int i = 1; i <= (int)s.length(); i++) {
            for (int j = 2; j <= (int)p.length(); j++) {
                if (p[j-1] == s[i-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    if (p[j-2] == s[i-1] || p[j-2] == '.') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                    }
                    else {
                        dp[i][j] = dp[i][j-2];
                    }
                }
                // else 就是0
            }
        }
        //return dp[0][2];
        return dp[s.length()][p.length()];
    }
};
```
