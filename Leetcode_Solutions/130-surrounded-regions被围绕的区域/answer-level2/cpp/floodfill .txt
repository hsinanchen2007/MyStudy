不要想着怎么把连通区域找到，反而是想怎么把连通边界找到。

### 代码

```cpp
class Solution {
private:
    int m;
    int n;
    
    bool atEdge (int x, int y) {
        if ( x == 0 || x == m-1 || y == 0 || y == n-1 )
            return true;
        return false;
    }

    void backtrack(vector<vector<char>>& board, int x, int y)
    {
         if ( x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') { //越界或是已经搜索过或者搜索的是X的停止搜索返回
            return;
         }
        if (board[x][y] == 'O') {
            board[x][y] = '#';
        
            backtrack(board, x+1, y);
            backtrack(board, x, y+1);
            backtrack(board, x-1, y);
            backtrack(board, x, y-1);

        }

    }

public:
    void solve(vector<vector<char>>& board) { //思路：不要想着怎么把连通区域找到，反而是想怎么把连通边界找到。
            m = board.size();
            if (m <= 1 ) {//只有1行的不需要填充
                return;
            }
            n = board[0].size();
            for (int i = 0; i < m; i++) {   //对边界上每一个 ‘O’ 做深度优先搜索.将边缘部分的o都标记为#
                for (int j = 0; j < n; j++) {
                    if (atEdge (i, j) && board[i][j] == 'O')  
                    backtrack(board, i, j);
                }
            }

            for (int i = 0; i < m; i++) {   
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 'O') { //将0都变成x,
                        board[i][j] = 'X';
                    }
                    if (board[i][j] == '#') { //将#都恢复成o
                        board[i][j] = 'O';
                    }
                }
            }
    }
};
```