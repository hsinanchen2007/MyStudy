
牛逼，除了被判空wa了一发，直接过
```
class Solution {
public:


    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        // 从边界开始dfs，将所有与O相连的变成P，然后将剩余的O变成X，将剩余的P编程O;
        int row = board.size();
        int col = board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<col;i++){
            if(board[0][i] == 'O'){
                board[0][i]  = 'P';
                q.push( make_pair(0,i));
            }
        }
        for(int i=0;i<col;i++){
            if(board[row-1][i] == 'O'){
                board[row-1][i]  = 'P';
                q.push( make_pair(row-1,i));
            }
        }
         for(int i=1;i<row-1;i++){
            if(board[i][0] == 'O'){
                board[i][0]  = 'P';
                q.push( make_pair(i,0));
            }
        }
         for(int i=1;i<row-1;i++){
            if(board[i][col-1] == 'O'){
                board[i][col-1]  = 'P';
                q.push( make_pair(i,col-1));
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            pair<int,int>now = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if(nx >0 && nx <row-1  && ny>0&& ny<col-1 && board[nx][ny] == 'O'){
                    board[nx][ny] = 'P';
                    q.push(make_pair(nx,ny));
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'P'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};
```
