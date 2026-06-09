### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                if(flag)
                    return true;
                if(board[i][j] == word[0])
                {
                    vis[i][j] = true;
                    DFS(board, i, j, word, 0);
                    vis[i][j] = false;
                }
            }
        }
        return flag;
    }
    void DFS(vector<vector<char>>& board, int x, int y, string &word, int ind)
    {
        if(ind == word.length() - 1)
        {
            flag = true;
            return ;
        }
        if(!flag)   //剪枝
        {
            for(int i = 0 ; i < 4 ; ++i)
            {
                if(flag)    //剪枝
                    break;
                int newX = x + nextX[i];
                int newY = y + nextY[i];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY] && board[newX][newY] == word[ind + 1])
                {
                    vis[newX][newY] = true;
                    DFS(board, newX, newY, word, ind + 1);
                    vis[newX][newY] = false;
                }
            }
        }
    }
private:
    bool vis[210][210] = {false};
    int nextX[4] = {1, -1, 0, 0};
    int nextY[4] = {0, 0, 1, -1};
    int n, m;
    int length;
    bool flag = false;
};
```