### 解题思路
纯C++

### 代码

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (0 == board.size())
        {
            return ;
        }

        function<void(int, int)> dfs = [&](int col, int row)
        {
            if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O')
            {
                return ;
            }

            board[row][col] = 'G';

            dfs(col - 1, row);
            dfs(col + 1, row);
            dfs(col, row - 1);
            dfs(col, row + 1);
        };

        for (int row = 0; row <= board.size() - 1; row++)
        {
            dfs(0, row), dfs(board[0].size() - 1, row);
        }

        for (int col = 0; col <= board[0].size() - 1; col++)
        {
            dfs(col, 0), dfs(col, board.size() - 1);
        }

        map<char, char> flip
        {
            {'G', 'O'},
            {'O', 'X'},
            {'X', 'X'}
        };

        for (int row = 0; row <= board.size() - 1; row++)
        {
            for (int col = 0; col <= board[0].size() - 1; col++)
            {
                board[row][col] = flip[board[row][col]];
            }
        }
    }
};
```