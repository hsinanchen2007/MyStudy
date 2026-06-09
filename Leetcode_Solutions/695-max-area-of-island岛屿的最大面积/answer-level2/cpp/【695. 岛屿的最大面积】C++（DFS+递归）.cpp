### 解题思路
深度优先遍历
找到陆地（1），标记置0，循环四个方向的邻接点，DFS
DFS的终止条件：到达边界或不是陆地

### 代码

```cpp
class Solution {
    // 深度优先搜索+递归
    int dfs(vector<vector<int>>& grid, int dx, int dy){
        // 特殊情况(出界或不是“陆地”)，返回0
        if(dx<0 || dy<0 || dx==grid.size() || dy==grid[0].size() || grid[dx][dy] != 1)
            return 0;
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};
        int ans = 1;
        grid[dx][dy] = 0; //置0，防止重复访问
        for(int k = 0; k<4; k++){
            ans += dfs(grid, dx+dir_x[k], dy+dir_y[k]);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};
```