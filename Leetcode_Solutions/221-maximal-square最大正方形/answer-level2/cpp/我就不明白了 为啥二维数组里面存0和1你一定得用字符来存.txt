### 解题思路
爷哭了

### 代码

```cpp
class Solution {
public:
    int dp[555][555] = {0};
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0)return 0;
        int ans = 0;
        
        for (int i = 0; i < matrix.size(); i++){dp[i][0] = matrix[i][0]-'0';ans = max(ans, dp[i][0]);}
        for (int i = 0; i < matrix[0].size(); i++){dp[0][i] = matrix[0][i]-'0';ans = max(ans, dp[0][i]);}
        for (int i = 1; i < matrix.size(); i++)
            for (int j = 1; j < matrix[i].size(); j++)
                if (matrix[i][j]=='1')
                {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                    ans = max(ans, dp[i][j]);
                    //printf("%d\n", ans);
                }
                else dp[i][j] = 0;
        return ans*ans;
    }
};
```