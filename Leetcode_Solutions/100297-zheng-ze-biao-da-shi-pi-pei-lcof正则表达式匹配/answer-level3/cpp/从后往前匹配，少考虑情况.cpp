### 解题思路


### 代码

```cpp
/*class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        bool dp[m][n];
        
        if(s[0]==p[0]||p[0]=='.')
            dp[0][0]=true;
        else
            dp[0][0]=false;
        

        for(int i=1;i<m;i++)
        {
            dp[i][0]=false;
        }
        for(int i=1;i<n;i++)
        {
            if(p[i]=='*')
            {
                if(i>1)
                    dp[0][i]=dp[0][i-1]||dp[0][i-2];
                else 
                    dp[0][i]=dp[0][i-1];
            }
            else
                dp[0][i]=false;
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(s[i]==p[j]||p[j]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j]=='*')
                {
                    if(j>1)
                        dp[i][j]=dp[i][j-1]||dp[i][j-2];
                    else if(s[i]==s[i-1])
                        dp[i][j]=dp[i-1][j-1];
                }
                else
                    dp[i][j]=false;
            }
        }
        return dp[m-1][n-1];
    }
};*/
class Solution {
public:
    bool isMatch(string s, string p) {

        bool dp[s.length() + 1][p.length() + 1];
        for(int i=0;i<=s.length();i++)
            for(int j=0;j<=p.length();j++)
                dp[i][j]=false;
        dp[s.length()][p.length()] = true;

        for (int i = s.length(); i >= 0; i--){
            for (int j = p.length() - 1; j >= 0; j--){
                bool match = (i < s.length() &&(p[j] == s[i] ||p[j] == '.'));
                if (j + 1 < p.length() && p[j+1] == '*'){  //x*匹配
                    dp[i][j] = dp[i][j+2] || match && dp[i+1][j];
                } else { //单个.匹配
                    dp[i][j] = match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
```