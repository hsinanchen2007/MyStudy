### 解题思路
动态规划：dp二维数组存储一个pair（得分，方案数）

### 代码

```cpp
class Solution {
    vector<vector<int>> dir = {{0,-1},{-1,0},{-1,-1}};
    int n, i, j;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        board[0][0] = board[n-1][n-1] = '0';
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>> (n, make_pair(0,0)));
        dp[n-1][n-1].second = 1;
        for(i = n-2; i >= 0 && board[i][n-1] != 'X'; --i)
        {
            dp[i][n-1].first = dp[i+1][n-1].first+board[i][n-1]-'0';
            dp[i][n-1].second = 1;
        }
        for(i = n-2; i >= 0 && board[n-1][i] != 'X'; --i)
        {
            dp[n-1][i].first = dp[n-1][i+1].first+board[n-1][i]-'0';
            dp[n-1][i].second = 1;
        }
        
        for(i = n-2; i >= 0; i--)
        {
            for(j = n-2; j >= 0; j--)
            {
                if(board[i][j] != 'X')
                {
                    if(dp[i+1][j+1].second)
                    {
                        if(dp[i+1][j+1].first+board[i][j]-'0' > dp[i][j].first)
                        {
                            dp[i][j].first = dp[i+1][j+1].first+board[i][j]-'0';
                            dp[i][j].second = dp[i+1][j+1].second%1000000007;
                        }
                        else if(dp[i+1][j+1].first+board[i][j]-'0' == dp[i][j].first)
                        {
                            dp[i][j].second += dp[i+1][j+1].second%1000000007;
                        }
                    }
                    if(dp[i][j+1].second)
                    {
                        if(dp[i][j+1].first+board[i][j]-'0' > dp[i][j].first)
                        {
                            dp[i][j].first = dp[i][j+1].first+board[i][j]-'0';
                            dp[i][j].second = dp[i][j+1].second%1000000007;
                        }
                        else if(dp[i][j+1].first+board[i][j]-'0' == dp[i][j].first)
                        {
                            dp[i][j].second += dp[i][j+1].second%1000000007;
                        }
                    }
                    if(dp[i+1][j].second)
                    {
                        if(dp[i+1][j].first+board[i][j]-'0' > dp[i][j].first)
                        {
                            dp[i][j].first = dp[i+1][j].first+board[i][j]-'0';
                            dp[i][j].second = dp[i+1][j].second%1000000007;
                        }
                        else if(dp[i+1][j].first+board[i][j]-'0' == dp[i][j].first)
                        {
                            dp[i][j].second += dp[i+1][j].second%1000000007;
                        }
                    }
                }
            }
        }
        return {dp[0][0].first, dp[0][0].second%1000000007};
    }
};
```