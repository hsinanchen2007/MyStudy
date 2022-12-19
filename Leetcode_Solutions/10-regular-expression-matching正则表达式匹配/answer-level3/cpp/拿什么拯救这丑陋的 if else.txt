```
        bool isMatch(string s, string t){
            int sizeS = s.length();
            int sizeT = t.length();
            vector<vector<bool>> dp(sizeS+1, vector<bool>(sizeT+1,false));
            dp[0][0]  = true;
            for(int i=0; i<=sizeS; ++i){
                for(int j=1; j<=sizeT; ++j){
                    if(t[j-1] == '*' && j>1){
                        dp[i][j] = dp[i][j-2] || ((i>0)?(dp[i-1][j]&&(t[j-2]=='.'||t[j-2]==s[i-1])):0);
                    }else if(i>0 && (t[j-1]=='.'||t[j-1]==s[i-1])){
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
            return dp[sizeS][sizeT];
        }

```
