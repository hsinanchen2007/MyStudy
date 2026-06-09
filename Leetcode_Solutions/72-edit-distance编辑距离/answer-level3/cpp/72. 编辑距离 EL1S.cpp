三种操作的转移：
```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= m; i++)
            dp[0][i] = i;
        
        for(int i = 1; i <= n; i++)
            dp[i][0] = i;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + (word1[i - 1] != word2[j -1]);//替换一个 这里word1 word2的是index所以减1
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);//删掉一个
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);//添加一个


            }
        }
        return dp[n][m];
    }
};
```
