模仿了搜索树
```
class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    void helper(vector<vector<int>>& board, int i, int j)
    {
        int cnt = 0;
        int x = 0;
        int y = 0;
        for(int z = 0; z < 8; ++z)
        {
            x = i + dx[z];
            y = j + dy[z];
            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            continue;
            else
            {
                if(board[x][y] == 1 || board[x][y] == -1)
                {
                    cnt ++;
                }
            }
        }
        if(board[i][j] == 1)
        {
            if(cnt < 2 || cnt > 3)
            {
                board[i][j] = -1;
            }
        }
        else if(board[i][j] == 0)
        {
            if(cnt == 3)
            {
                board[i][j] = 2;
            }
        }
        return;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                helper(board, i, j);
            }
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == -1)
                {
                    board[i][j] = 0;
                }
                else if(board[i][j] == 2)
                {
                    board[i][j] = 1;
                }
            }
        }
        return;
    }
};
```

