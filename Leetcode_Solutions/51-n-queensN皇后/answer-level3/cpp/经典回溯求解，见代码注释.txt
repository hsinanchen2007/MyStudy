### 解题思路
经典回溯求解，见代码注释

24ms 10.8M
--- wangtao HW-2020/2/23
### 代码

```cpp
class Solution {
public:
    bool isQueenOK(vector<vector<char>>& grid, int row, int col)
    {
        // 按照横向遍历的，所以横向一定是合法的，纵向合法性校验
        for (int i = 0; i < row; i++) {
            if (grid[i][col] == 'Q') return false;
        }
        // 主对角线合法性校验
        int x = row;
        int y = col;
        while((--x) >= 0 && (--y) >= 0) {
            if (grid[x][y] == 'Q') return false;
        }
        // 副对角线合法性校验
        x = row;
        y = col;
        while((--x) >= 0 && (++y) < grid.size()) {
            if (grid[x][y] == 'Q') return false;
        }
        return true;
    }
    
    void queenDFS(vector<vector<string>>& ans, vector<vector<char>>& grid, int index, int n)
    {
        if (index == n) {
            // 输出数据
            vector<string> tmpstr;
            for (auto c : grid) {
                tmpstr.push_back(accumulate(c.begin(), c.end(), string("")));
            }
            ans.push_back(tmpstr);
            return;
        }
        for (int i = 0; i < n; i++) {
            // 检查(index, i)位是否能放Q
            if (isQueenOK(grid, index, i)) {
                grid[index][i] = 'Q';
                queenDFS(ans, grid, index + 1, n);
                grid[index][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        queenDFS(ans, grid, 0, n);
        return ans;
    }
};
```