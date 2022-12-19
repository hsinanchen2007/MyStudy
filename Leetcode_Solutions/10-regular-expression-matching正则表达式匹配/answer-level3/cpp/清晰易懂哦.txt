```
class Solution {
public:
    bool isMatch(string s, string p) {
        int l1=s.size(), l2=p.size();
        bool dp[l1+7][l2+7];
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;  // dp含义 : 长度为i和长度为j的字符串是否匹配
        for (int i=0;i<=l1;i++)  // i要从零开始 : s为空字符串, p为.*之类的
            for (int j=1;j<=l2;j++) {
                if (i&&(s[i-1]==p[j-1]||p[j-1]=='.')) // 末尾字符串可以匹配, 看前面的
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'&&j!=1) {    // 末尾字符串为*, 分为里两种情况(x*)是否与s的当前字符匹配
                    if (i==0)                   // dp[i][j-2]:不匹配  dp[i-1][j]: 匹配 
                        dp[i][j]=dp[i][j-2];    // i==0或者两者末尾字符串不相同, 只能选择不匹配
                    else if (s[i-1]==p[j-2]||p[j-2]=='.')
                        dp[i][j]=max(dp[i][j-2], dp[i-1][j]);
                    else 
                        dp[i][j]=dp[i][j-2];
                }
            }
        return dp[l1][l2];
    }
};
```
