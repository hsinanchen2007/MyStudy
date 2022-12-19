### 解题思路
海岛题有多种求法：DFS +BFS +并查集，都是对边界进行遍历，把0写成1
从代码简单程度来看，DFS是最简单的

1.DFS：
1）沿着矩阵边界，将所有为陆地的岛屿进行一遍DFS，将所有0的地方写成1，则矩阵中只剩下封闭岛屿
2）对矩阵进行遍历，碰到0的地方进行DFS，表示该位置相连的地方是1个封闭岛屿，整体被清除；计数+1；
3）返回最终的计数

2.BFS 也是类似的

3.并查集也是类似的

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> moves = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    bool inArea(int i, int j, vector<vector<int>> &grid)
    {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size()) {
            return true;
        }
        return false;
    }

    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (inArea(i, j, grid) && grid[i][j] == 0) {
            grid[i][j] = 1;
            for (auto move : moves) {
                dfs(i + move[0], j + move[1], grid);
            }
        }

        return;
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[i].size() - 1) {
                    dfs(i, j, grid);
                }
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0){
                    result++;
                    dfs(i, j, grid);
                }
            }
        }
        return result;
    }
};
```