### 解题思路
动态规划+滚动数组

![image.png](https://pic.leetcode-cn.com/4e2f3ebd5041dc5ec939305e4da3cb4859d161b84e79292e496ca95957052bd2-image.png)

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        long long f[2][200];
        int n = grid.size();
        int m = grid[0].size();
        int now = 1;
        f[0][0] = grid[0][0];
        for(int i = 1; i < m; i ++)
            f[0][i] = f[0][i - 1] + grid[0][i];
        for(int i = 1; i < n; i ++)
        {
            f[now][0] = f[1 - now][0] + grid[i][0];
            for(int j = 1; j < m; j ++)
            {
                f[now][j] = min(f[1 - now][j], f[now][j - 1]) + grid[i][j];
            }
            now = 1 - now;
        }
        return f[1 - now][m - 1];
    }
};
```