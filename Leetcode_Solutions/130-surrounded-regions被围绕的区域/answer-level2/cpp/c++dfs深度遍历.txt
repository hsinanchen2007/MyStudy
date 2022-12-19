### 解题思路
1. 对边界上的'O'进行递归并标记'#'
2. 剩余的'O'即为可填充为'X'的区域
3. 遍历，将'O'变为'X'，将'#'变为'O'

### 代码

```cpp
class Solution {
public:
    int xlen;
    int ylen;
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int xlen = board[0].size();
        int ylen = board.size();
        this->xlen = xlen;
        this->ylen = ylen;
        for(int i = 0; i < ylen; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][xlen-1] == 'O') dfs(board, i, xlen-1);
        }
        for(int j = 0; j < xlen; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[ylen-1][j] == 'O') dfs(board, ylen-1, j);
        }
        for(int i = 0; i < ylen; i++){
            for(int j = 0; j < xlen; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        board[x][y] = '#';
        if(x<ylen-1 && board[x+1][y] == 'O') dfs(board, x+1, y);
        if(x>0 && board[x-1][y] == 'O') dfs(board, x-1, y);
        if(y<xlen-1 && board[x][y+1] == 'O') dfs(board, x, y+1);
        if(y>0 && board[x][y-1] == 'O') dfs(board, x, y-1);
    }
};
```