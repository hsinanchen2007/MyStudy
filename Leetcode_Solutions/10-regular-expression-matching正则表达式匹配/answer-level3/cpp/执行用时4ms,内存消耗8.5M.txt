### 解题思路
通用的dp的思想
### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        //初始化
        bool dp[m+1][n+1]={false};
        //初始化
        dp[0][0]=true;
        
        for(int i=1;i<=m;i++)
            dp[i][0]=false;
        for(int i=1;i<=n;i++)
            {dp[0][i]=((p[i-1]=='*' ? true : false)&&(i-2<0?false:dp[0][i-2]));
            //记住p中的下标要减1因为字符串是从0开始的，我一开始没有减1，笑死我了，还    还有i-2是不是要小于0，此外初始化的时候,如果p[i-1]='*'的话,dp[i]还要要看dp[i-2]的
            }
        for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
                if(p[j-1]==s[i-1]||p[j-1]=='.') 
                    {dp[i][j]=dp[i-1][j-1];}
                else if(p[j-1]=='*'){
                    if(p[j-2]==s[i-1]||p[j-2]=='.'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1]||(j-2<0?false:dp[i][j-2]);
                    }
                    else if(p[j-2]!=s[i-1]) 
                        {dp[i][j]=(j-2<0 ? false :dp[i][j-2]);}
                }
                }
        return dp[m][n];
    }
};
```