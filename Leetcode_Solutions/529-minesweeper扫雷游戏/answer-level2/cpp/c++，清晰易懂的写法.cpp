```
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        } else if(board[x][y] == 'B') {
            return board;
        } else if(board[x][y] == 'E') {
            int num = nearMine(board, x, y);
            if(num == 0) dfs(board, x, y);
            else {
                board[x][y] = num + '0';
                return board;
            }
        }
        return board; 
    }

    int nearMine(vector<vector<char>>& board, int x, int y) {
        //cout<<x<<","<<y<<endl;
        int num = 0;
        if(x-1 >= 0 && board[x-1][y] == 'M') num++;
        if(x+1 < board.size() && board[x+1][y] == 'M') num++;
        if(y-1 >= 0 && board[x][y-1] == 'M') num++;
        if(y+1 < board[0].size() && board[x][y+1] == 'M') num++;
        if(x+1 < board.size() && y-1 >= 0 && board[x+1][y-1] == 'M') num++;
        if(x+1 < board.size() && y+1 < board[0].size() && board[x+1][y+1] == 'M') num++;
        if(x-1 >= 0 && y+1 < board[0].size() && board[x-1][y+1] == 'M') num++;
        if(x-1 >= 0 && y-1 >= 0  && board[x-1][y-1] == 'M') num++;
        //cout<<num<<endl;
        return num;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] != 'E') return;
        int num = nearMine(board, x, y);
        if(num == 0) {
            board[x][y] = 'B';
        } else {
            board[x][y] = num + '0';
            return;
        }
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
        dfs(board, x-1, y-1);
        dfs(board, x-1, y+1);
        dfs(board, x+1, y-1);
        dfs(board, x+1, y+1);

        return;
    }
};
```
