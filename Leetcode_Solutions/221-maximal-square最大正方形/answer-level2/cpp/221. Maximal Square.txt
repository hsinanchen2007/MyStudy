### 解题思路
DP
注意状态转移方程
注意dp数组是dp[m + 1][n + 1]，扩充1方便初始化dp

### 代码

```cpp
class Solution {
public:
    //dp[i][j]: 以[i,j]为右下角的最大的正方形的边长，是范围内最优解
    //dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m + 1][n + 1] = {};
        memset(dp, 0, sizeof(dp));
        int maxLength = 0;
//       for(int j = 0; j < matrix[0].size(); j++){
//          dp[0][j] = (matrix[0][j] == '1' ? 1 : 0); 
//           maxLength = max(maxLength, dp[0][j]);
//        }
//       for(int i = 0; i < matrix.size(); i++){
//            dp[i][0] = (matrix[i][0] == '1' ? 1 : 0); 
//            maxLength = max(maxLength, dp[i][0]);
//        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i-1][j-1] == '0'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                }
                maxLength = max(maxLength, dp[i][j]);
                //cout << maxLength << endl;
            }
        }
        return maxLength*maxLength;
    }
};
```