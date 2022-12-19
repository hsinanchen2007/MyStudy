### 解题思路
本题难点在于当p串是*的时候，要对前一个字符是否和s匹配进行分类讨论。

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*'&&dp[0][i-2]) dp[0][i]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='.') dp[i][j]=dp[i-1][j-1];//很简单如果是.肯定能匹配
                else if(p[j-1]=='*'){
                    if(p[j-2]==s[i-1]||p[j-2]=='.')dp[i][j]=dp[i-1][j]||dp[i][j-2];//如果和前一个字符匹配，其可以匹配0个或多个字符
                    else dp[i][j]=dp[i][j-2];//如果不行，只能尝试*匹配0个的情况，那么当前是否匹配依赖于前2个字符的结果
                }else{
                    dp[i][j]=(s[i-1]==p[j-1]?dp[i-1][j-1]:false);//同样简单，当字符相等时才能匹配到
                }
            }
        }
        return dp[n][m];
    }
};
```