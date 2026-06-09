```
class Solution {
public:
    int palindromePartition(string s, int k) {
        // dp[i][j][k]
        // [i,j]分为k份需要修改的字符串个数
        // 最多分为 j - i + 1 份
        // 最少 1 份
        int n = s.size();
        const int N = INT_MAX / 2;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,0)));

        
        for(int i = 2; i <= n; ++i)
        {
            // 长度为i的
            int tmp = n - i + 1;
            for(int j = 1; j <= tmp; ++j)
            {
                int t = j + i - 1;
                // 首 j 末尾 t 长度i
                //最多分 min(i,k)份
                int fen = min(i,k);
                // 最少分1份 单独拎出来
                dp[j][t][1] = dp[j+1][t-1][1] + (s[j-1] == s[t-1] ? 0 : 1);
                
                for(int K = 2; K <= fen; ++K)
                {
                    // 当前分为K份
                    int tt = N;
                    
                    // kk 代表前面有几份
                    for(int kk = 1; kk < K; ++kk)
                    {
                        // kk份要求至少有kk个元素, (i - m)为剩下的元素，K - kk为剩下的份数 i - m >= K - kk m <= i + kk - K
                        int e1 =  i + kk - K;
                        for(int m = kk; m <= e1; ++m)
                        {
                            tt = min(tt,dp[j][j+m-1][kk]+dp[j+m][t][K-kk]);
                        }
                    }
                    dp[j][t][K] = tt;
                }
            }
        }
      
        return dp[1][n][k];
    }
};
```
