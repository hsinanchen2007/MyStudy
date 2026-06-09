### 解题思路
先处理board中已经存在的数字，标记为他们已经存在。

使用 row[9][9] col[9][9] st[3][3][9] 代表行列，每个方格，各个数字（1 - 9）的使用情况。

直接上代码。

### 代码

```cpp
class Solution {
public:
    bool row[9][9], col[9][9], st[3][3][9];
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row); // 初始化三个数组
        memset(col, 0, sizeof col);
        memset(st, 0, sizeof st);
        for(int i = 0; i < 9 ; i ++ )
            for(int j = 0; j < 9; j ++ )
            {
                if(board[i][j]!='.')
                {
                    int num = board[i][j] - '1';
                    row[i][num] = col[j][num] = st[i / 3][j / 3][num] = 1; // 初始化已经存在的数字
                }
            }
        cout<<dfs(board, 0, 0)<<endl;
    }
    bool dfs(vector<vector<char>> & board, int r, int c) // 按行遍历
    {
        if(c == 9) r ++, c = 0;  // 如果这一行的每一列都被遍历过，就直接跳转到下一行的第一列
        if(r == 9) return true; // 遍历完所有行，返回
        if(board[r][c]!='.') return dfs(board, r, c + 1); // 当前是数字，直接跳到下一列
        for(int i = 0; i < 9; i ++ )
        {
            if(!row[r][i] && !col[c][i] && !st[r / 3][ c / 3][i])
            {
                board[r][c] = i + '1';
                row[r][i] = col[c][i] = st[r / 3][c / 3][i] = 1;
                if(dfs(board, r, c + 1)) return true;
                row[r][i] = col[c][i] = st[r / 3][c / 3][i] = 0;
                board[r][c] = '.';
            }
        }
        
        return false;
    }
};
```