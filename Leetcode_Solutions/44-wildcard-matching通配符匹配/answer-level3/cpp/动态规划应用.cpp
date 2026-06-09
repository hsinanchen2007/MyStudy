### 解题思路
1、初始化(dp[i][j]对应s[i-1],p[j-1])。
  1）dp[0][0] = true;
  2) dp[0][j]&&p[j-1]=='*'====》dp[0][j] = true;
2、情况1：s[i-1]==p[j-1] || p[j-1]== '?',这种情况可以忽略s的第i位和p的第j位，即dp[i][j] = dp[i-1][j-1]
   情况2：p[j-1]=='*'。
   若p[j-1]匹配空字符（ab和ab*），dp[i][j] = dp[i][j-1];
   若p[j-1]匹配任意字符串（abbc和abb），dp[i][j] = dp[i-1][j];
### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));
        dp[0][0] = true;
        for(int i = 1; i<n+1; i++){
            if(p[i-1] == '*'){
                dp[0][i] = true;
            }
            else{
                break;
            }
        }
        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                if(p[j-1] == '?' ||s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
```