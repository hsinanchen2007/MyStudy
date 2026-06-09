处理好递归边界，搜就完事了
```
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board, click[0], click[1]);
        return board;
    }

    int dir[8][2] =
    {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    void dfs(vector<vector<char> >& board, const int x, const int y)
    {
        int row = board.size();
        int col = board[0].size();

        if(x < 0 || x >= row || y < 0 || y >= col) // 越界，递归边界
        {
            return;
        }

        if(board[x][y] == 'M') // 挖出地雷，递归边界
        {
            board[x][y] = 'X';
            return;
        }

        if(board[x][y] != 'E') // 已被挖出，递归边界
        {
            return;
        }

        if(board[x][y] == 'E') // 空白方块，计算8个方向有多少地雷
        {
            int cnt = calcBmob(board, x, y);
            if(cnt > 0)
            {
                board[x][y] = cnt + '0';
                return;
            }
            else board[x][y] = 'B';
        }

        for(int i = 0; i < 8; i++)
        {
            dfs(board, x + dir[i][0], y + dir[i][1]);
        }
    }

    int calcBmob(vector<vector<char> >& board, const int x, const int y)
    {
        int ans = 0;
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < 8; i++)
        {
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if(newX >= 0 && newX < row && newY >= 0 && newY < col)
            {
                if(board[newX][newY] == 'M' || board[newX][newY] == 'X')
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
```
