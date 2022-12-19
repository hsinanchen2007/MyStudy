### 解题思路
纯C++

### 代码

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (true == grid.empty())
        {
            return 0;
        }

        int res = 0;

        for (int row = 0; row <= grid.size() - 1; row++)
        {
            for (int col = 0; col <= grid[0].size() - 1; col++)
            {
                res += grid[row][col] - '0';
                dfs(grid, row, col); // 岛的其余部分清零
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || '0' == grid[row][col])
        {
            return ;
        }

        grid[row][col] = '0'; // 对岛清零

        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
};
```