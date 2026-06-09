给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

### 解题思路
dp[i][j]代表从下面到第[i][j]位置的最短路径，他等于dp[i+1][j],dp[i+1][j+1]（左，右）中的最短路径，加上他本身。
需要注意i 从 triangle.size()-2开始， -1是索引从0开始，再-1是至少两层

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1) return triangle[0][0];
        vector<vector<int>> dp(triangle);
        for (int i = triangle.size()-2; i >=0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
```