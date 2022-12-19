### 解题思路
思路：动态规划
后续工作：优化空间

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m+1, vector<int>(n+1, 0));
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (i == 1 || j == 1)
                    ans[i][j] = 1;
                else 
                    ans[i][j] = ans[i-1][j]+ans[i][j-1];
            }
        }
        return ans[m][n];
    }
};
```