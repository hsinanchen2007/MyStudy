### 解题思路
先找到边界上的 `O` 压入队列，然后通过 bfs 查找与边界连通的 `O` 标记为访问过的；

最后遍历一遍 board 数组，如果没有被标记过的 `O`表示是无法到达的 `O`， 直接置为`X`.

### 代码

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return ;
        vector<vector<bool>> st(board.size(), vector<bool>(board[0].size(), false));
        queue<pair<int, int>> q;

        for(int i = 0;i < board.size(); i ++ )
            for(int j = 0;j < board[0].size(); j ++)
            {
                if(board[i][j] == 'O')
                {
                    if(i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1)
                    {
                        st[i][j] = true;
                        q.push({i, j});
                    }    
                }
            }
        
        int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
        while(!q.empty())
        {
            pair<int, int> t;
            t = q.front();
            q.pop();
            // cout<< t.first <<" "<<t.second<<endl;
            for(int i =0;i < 4; i ++ )
            {
                int x = t.first + dx[i], y = t.second + dy[i];
                if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
                if(board[x][y] == 'X') continue;
                if(board[x][y] == 'O' && st[x][y] == false)
                {
                    q.push({x, y});
                    st[x][y] = true;
                }
            }
        }

        for(int i = 0;i < board.size(); i ++)
            for(int j = 0;j < board[0].size(); j ++ )
            {
                if(board[i][j] == 'O' && st[i][j] == false)
                {
                    board[i][j] = 'X';
                }
            }
    }
};
```