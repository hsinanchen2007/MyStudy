### 解题思路
有一个好消息，有一个坏消息...
好消息是，这道题跟之前做过的[矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)几乎一毛一样...
坏消息是，我还是不会做...哈哈哈哈哈哈嗝。

### 代码

```cpp
class Solution {
private:
    int d_i[4] = {0, 0, 1, -1};
    int d_j[4] = {1, -1, 0, 0};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        //0.！！矩阵问题，深度搜索问题，首先写这个模板！遍历矩阵中的每个点，并更新最值！
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        //1.递归出口：出界或者该方向土地不连通或者该土地已经走过
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0)
            return 0;
        //2.我们把走过的土地设置为 0 
        grid[i][j] = 0;
        int ans = 1;
        //3.探索脚下土地的四个方向
        for (int index = 0; index < 4; ++index) {
            int next_i = i +d_i[index], next_j = j + d_j[index];
                ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }
};
```