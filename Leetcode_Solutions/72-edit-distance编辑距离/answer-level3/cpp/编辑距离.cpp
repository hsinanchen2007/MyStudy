考虑最优策略的最后一步，word1的最后一个字符如何变成word2的最后一个字符，1）插入  2）删除  3）替换  4）不变
状态：dp[i][j]代表word1的前i个字符变成word2的前j个字符的最少操作数
转移方程：dp[i][j] = min( dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1] + 1,  dp[i-1][j-1](word1[i-1] == word2[j-1] )   )
初始化条件：dp[0][i] = i ; dp[i][0] = i;

```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1,0)); //dp[i][j]代表A的前i个字符和B的前j个字符的最小编辑距离
        
   
        //让word1的最后一个字符变成word2 的最后一个字符
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
            	if(i == 0){
            		dp[i][j] = j;
            		continue;
            	}
            	if(j == 0){
            		dp[i][j] = i;
            		continue;
            	}
                //dp[i][j] = min(dp[i][j-1]+1 , dp[i-1][j]+1, dp[i-1][j-1]+1, dp[i-1][j-1](A[i-1] == B[j-1]) ) 
                dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+1));
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        
       return dp[m][n];
    }
};
```