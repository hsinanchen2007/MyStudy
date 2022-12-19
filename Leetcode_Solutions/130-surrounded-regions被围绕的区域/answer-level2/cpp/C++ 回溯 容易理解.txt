### 解题思路
对边界上的'O'进行dfs。

### 代码

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        if(h == 0) return;
        int w = board[0].size();
        for(int i = 0;i < h;i++)
        {
            if(board[i][0] == 'O')
            {
                backtrack(board,i,0);
            }
            if(board[i][w - 1] == 'O')
            {
                backtrack(board,i,w - 1);
            }
        }
        for(int j = 0;j < w;j++)
        {
            if(board[0][j] == 'O')
            {
                backtrack(board,0,j);
            }
            if(board[h - 1][j] == 'O')
            {
                backtrack(board,h - 1,j);
            }
        }
        for(int i = 0;i < h;i++)
        {
            for(int j = 0;j < w;j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void backtrack(vector<vector<char>>& board,int x,int y)
    {
        if(!isvaild(board,x,y) || board[x][y] != 'O') return;
        board[x][y] = '#';
        backtrack(board,x + 1,y);
        backtrack(board,x - 1,y);
        backtrack(board,x,y + 1);
        backtrack(board,x,y - 1);
    }
    bool isvaild(vector<vector<char>>& board,int x,int y)
    {
        return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
    }
};
```