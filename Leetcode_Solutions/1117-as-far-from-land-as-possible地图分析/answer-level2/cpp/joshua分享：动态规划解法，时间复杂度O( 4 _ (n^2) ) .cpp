### 解题思路
先从左、上走到当前位置；再从右、下走到当前位置，一共四个方向的路径

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int landNum = 0, tMax = 0;

        // 初始化n*n的方阵，均为最大值
        vector<vector<int>> dp(n, vector<int>(n, n*n));
        // 如果是陆地，就初始化为 0 
        for(int i = 0; i < n; i ++) for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) { dp[i][j] = 0; landNum++; }
        }
        // 极限情况，如果全都是一样，直接返回-1
        if(landNum == 0 || landNum == n*n) return -1;
        // 先从左、上走到当前位置
        for(int i = 0; i < n; i ++) for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) continue;
            if(i-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        
        } 
        // 再从右、下走到当前位置
        for(int i = n-1; i >= 0; i--) for(int j = n-1; j >= 0; j--) {
            if(grid[i][j] == 1) continue;
            if(i+1 < n) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
            if(j+1 < n) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
        } 
        // 四个方向都走完了后，再筛选最大值。
        for(int i = 0; i < n; i ++) for(int j = 0; j < n; j++) {
            tMax = max(tMax, dp[i][j]);
        }

        return tMax;
    }
};
```