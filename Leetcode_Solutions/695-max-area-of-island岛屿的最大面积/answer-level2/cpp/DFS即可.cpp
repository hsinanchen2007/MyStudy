### 解题思路
DFS即可求解

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int count = 0;
                Dfs(grid, i, j, count);
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
    void Dfs(vector<vector<int>>& grid, int index1, int index2, int& count) {
        if (grid[index1][index2] != 1) {
            return;
        }
        count++;
        grid[index1][index2] = 0;
        if (index1 + 1 < grid.size() && grid[index1 + 1][index2] == 1) {
            Dfs(grid, index1 + 1, index2, count);
        }
        if (index2 + 1 < grid[0].size() && grid[index1][index2 + 1] == 1) {
            Dfs(grid, index1, index2 + 1, count);
        }
        if (index1 - 1 >= 0 && grid[index1 - 1][index2] == 1) {
            Dfs(grid, index1 - 1, index2, count);
        }
        if (index2 - 1 >= 0 && grid[index1][index2 - 1] == 1) {
            Dfs(grid, index1, index2 - 1, count);
        }
        return;
    }
};

```