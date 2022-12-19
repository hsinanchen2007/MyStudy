dfs是把一堆东西塞到某一个地方，塞的时候要注意约束条件
这道题就是把1-9的数字塞进数独表格里面
约束条件是：一行1-9出现一次，一列1-9出现一次，一个3*3格子1-9出现一次
```
class Solution {
    bool dfs(int rowidx, int colidx, vector<vector<char>>& board, vector<vector<bool>> rows, vector<vector<bool>> cols, vector<vector<bool>> grid)
    {


        if(colidx == board[0].size())
        {
            rowidx++;
            colidx = 0;
        }
        if(rowidx == board.size())
            return true;
        if(board[rowidx][colidx] != '.')
        {
            if(dfs(rowidx, colidx + 1,board, rows, cols, grid))
                return true;
            return false;
        }
        else
        {
            for(int i = 1; i <= 9; i++)
            {
                if(grid[1 + 3*(rowidx/3) + colidx/3][i] ||rows[rowidx][i] || cols[colidx][i])
                    continue;
                board[rowidx][colidx] = '0' + i;
                grid[1 + 3*(rowidx/3) + colidx/3][i] = rows[rowidx][i] = cols[colidx][i] = true;
                if(dfs(rowidx, colidx + 1,board, rows, cols, grid))
                    return true;
                grid[1 + 3*(rowidx/3) + colidx/3][i] = rows[rowidx][i] = cols[colidx][i] = false;
                board[rowidx][colidx] = '.';
            }
            return false;
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(!board.size() || !board[0].size())
            return;
        int n = board.size(), m = board[0].size();
        int total = 0;
        vector<vector<bool>> rows(n, vector<bool>(9 + 1, false)), cols(m, vector<bool>(9 + 1, false));
        vector<vector<bool>> grid(10, vector<bool>(9 + 1, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j]!='.')
                {
                    total++;
                    int val = board[i][j] - '0';
                    rows[i][val] = true;
                    cols[j][val] = true;
                    grid[1 + 3*(i/3) + j/3][val] = true;
                }
            }
        }
        if(total == m * n)
            return;
        dfs(0, 0, board, rows, cols, grid);
    }
};
```
可以通过优化状态存储来节省空间：

