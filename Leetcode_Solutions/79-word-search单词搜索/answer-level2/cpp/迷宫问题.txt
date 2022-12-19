### 解题思路
注意一开始的那个字符也要设置为已访问。
### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                if(board[i][j] == word[0] && !flag)
                {
                    memset(vis, false, sizeof(vis));
                    string temp = "";
                    temp += board[i][j];
                    vis[i][j] = true;
                    DFS(board, i, j, 1, temp, word);
                    if(flag)
                    break;
                }
            }
        }
        return flag;
    }
    void DFS(vector<vector<char>>& board, int x, int y, int n, string &temp, string &word)
    {
        if(n == word.length())
        {
            cout<<temp<<endl;
            if(temp == word)
            {
                flag = true;
            }
            return ;
        }
        for(int i = 0 ; i < 4 ; ++i)
        {
            int nextX = x + a[i];
            int nextY = y + b[i];
            if(nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board[0].size() && !vis[nextX][nextY] && board[nextX][nextY] == word[n] && !flag)
            {
                vis[nextX][nextY] = true;
                temp += board[nextX][nextY];
                DFS(board, nextX, nextY, n + 1, temp, word);
                temp = temp.substr(0, temp.length() - 1);
                vis[nextX][nextY] = false;
            }
        }
    }
private:
    bool flag = false;
    int a[4] = {0, 0, 1, -1};
    int b[4] = {1, -1, 0, 0};
    bool vis[150][150];
};
```