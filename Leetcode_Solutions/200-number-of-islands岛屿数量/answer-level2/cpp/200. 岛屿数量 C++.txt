### 解题思路
使用递归 将上下左右为'1'的设置为'2'

### 代码

```cpp
class Solution {
public:
    void infect(vector<vector<char>>& grid, int row, int col)
    {
        int m = grid.size();
        int n = grid.at(0).size();

        if (row < 0 || row == m || col < 0 || col == n || grid.at(row).at(col) != '1')
        {
            return;
        }

        grid.at(row).at(col) = '2';

        infect(grid, row - 1, col); //上
        infect(grid, row + 1, col); //下
        infect(grid, row, col - 1); //左
        infect(grid, row, col + 1); //右
    }

    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty())
        {
            return 0;
        }

        int m = grid.size();
        int n = grid.at(0).size();
        int count = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid.at(i).at(j) == '1')
                {
                    ++count;
                    infect(grid, i, j);
                }
            }
        }

        return count;
    }
};
```