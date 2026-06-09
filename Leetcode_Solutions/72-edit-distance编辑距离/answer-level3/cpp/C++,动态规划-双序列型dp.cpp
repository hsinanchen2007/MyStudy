
```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0x7f7f7f7f));
        //下面进行初始化操作，
        for(int i=0;i<=n;i++){//第一行空留出来初始化，目的是：方便后面的操作
            dp[i][0]=i;//表示的是当word2为空串时，word1[0.....i]转成空串所需要的步数
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        return dp[n][m];
    }
};
```
