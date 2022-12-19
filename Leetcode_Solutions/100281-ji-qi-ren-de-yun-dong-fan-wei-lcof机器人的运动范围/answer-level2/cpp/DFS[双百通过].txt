### 解题思路
![image.png](https://pic.leetcode-cn.com/1d58d9f50eb7665d6d1c099bc509e5d98127e4eaa697447755c20d6a11ec2ed7-image.png)
先求出不合格的Grid空格，将其打上无法通过标签；
然后通过DFS进行上下左右递归拓展，并计数；
PS:无需回溯

### 代码

```cpp
class Solution {
public:
    int result = 0;
    int movingCount(int m, int n, int k) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!CanArrived(i, j, k)) {
                    grid[i][j] = 1;
                }
            }
        }
        Dfs(grid, 0, 0);
        return result;
    }

    void Dfs(vector<vector<int>>& grid, int index1, int index2) {
        grid[index1][index2] = 1;
        result++;
        if (index1 + 1 < grid.size() && grid[index1 + 1][index2] != 1) {
            Dfs(grid, index1 + 1, index2);
        }
        if (index1 - 1 >= 0 && grid[index1 - 1][index2] != 1) {
            Dfs(grid, index1 - 1, index2);
        }
        if (index2 + 1 < grid[0].size() && grid[index1][index2 + 1] != 1) {
            Dfs(grid, index1, index2 + 1);
        }
        if (index2 - 1 > 0 && grid[index1][index2 - 1] != 1) {
            Dfs(grid, index1, index2 - 1);
        }
        return;
    }

    bool CanArrived(int m, int n, int k) {
        int count = 0;
        while (m >= 10) {
            count += m / 10;
            m = m % 10;
        }
        while (n >= 10) {
            count += n / 10;
            n = n % 10;
        }
        count += m;
        count += n;
        if (count <= k) {
            return true;
        }
        return false;
    }
};
```