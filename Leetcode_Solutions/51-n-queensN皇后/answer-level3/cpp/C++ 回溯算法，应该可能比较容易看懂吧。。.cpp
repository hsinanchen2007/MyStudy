```
class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n);
        this->n = n;
        init();
        findQueens(0);
        return res;
    }


private:
    vector<string> board;
    vector<vector<string>> res;
    int n;
    void init()
    {
        for (auto &row : board)
        {
            for (int i = 0; i < n; i++)
            {
                row += '.';
            }
        }
    }
    bool check(int r, int c)  // 检查放在r, c 是否合理
    {
        for (int i = 0; i < r; i++)  //  检查列
        {
            if (board[i][c] == 'Q')
                return false; 
        }
        for (int i = r - 1,j = c - 1; i >= 0 && j >= 0; i--, j--)  // 左上斜线
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = r - 1,j = c + 1; i >= 0 && j < n; i--, j++)  // 右上斜线
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void findQueens(int row)
    {
        if (row >= n)
        {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++)
        {
            if (check(row, c))
            {
                board[row][c] = 'Q';
                findQueens(row + 1);
                board[row][c] = '.';
            }
        }
    }
};
```
