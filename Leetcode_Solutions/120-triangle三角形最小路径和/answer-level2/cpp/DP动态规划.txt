### 解题思路
定义DP： dp[i][j] 是index为i,j的节点，到底部的最小路径；
状态转移方程： dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
初始化变量： 最底部 i = triangle.size - 1 这一层的节点都保持原值既可。
### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>& dp  = triangle;
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};
```