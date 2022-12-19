### 解题思路
是只有C++有这个问题吗，最后还得改成long才能过，这问题找了我蛮久，还以为是自己做错了出来这么大数字。。。

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        vector<vector<long>> ans(n, vector<long>(m, 0));
        if (obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        ans[0][0] = 1;
        for (int i=1; i<n; i++) {
            ans[i][0] = obstacleGrid[i][0] == 1 ? 0 : ans[i-1][0];
        }    
        for (int j=1; j<m; j++) {
            ans[0][j] = obstacleGrid[0][j] == 1 ? 0 : ans[0][j-1];
        }    
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (obstacleGrid[i][j] == 1)
                    ans[i][j] = 0;
                else
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];        
            }
        }
        return ans[n-1][m-1];
    }
};
```