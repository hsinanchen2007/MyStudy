```
class Solution {
public:
    /*   dp[i][j]:表示s串0~i与t串0~j的最长公共子序列
    * if(s[i]==t[j])dp[i][j]=dp[i-1][j-1]+1;
    *  if(s[i]!=t[j])dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    */
    int longestCommonSubsequence(string t1, string t2) {
      int n=t1.size(),m=t2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else
                {
                    dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};
```
