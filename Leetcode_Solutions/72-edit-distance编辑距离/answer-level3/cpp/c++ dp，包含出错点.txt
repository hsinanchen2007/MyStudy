```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int> >dp(m+1, vector<int>(n+1, 0));
        // if(m == 0)
        // {
        //出错点1: base case是针对所有的情况，
        //        包括子情况(用到dp[i][0]/dp[0][j])
        //        和特殊情况: m = 0 或 n = 0
        for(int i = 1; i <= m;++i)
            dp[i][0] = i;
        for(int i = 1; i <= n;++i)
            dp[0][i] = i;
        // }
        // if(n == 0)
        // {
        for(int i = 1; i <= m;++i)
            dp[i][0] = i;
        // }
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1;j <= n;++j)
            {
                if(word1[i-1] == word2[j-1])  //出错点2: 比较的是i/j前面的字符
                    dp[i][j] = dp[i-1][j-1];    //出错点3: 匹配不是万事大吉了，是等于上一次的结果(不用坐变动)
                else{
                    int tmp = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                    dp[i][j] = min(dp[i-1][j-1] + 1, tmp);
                }
            }
        }
        return dp[m][n];
    }
};
```
