```
class Solution {
public:
    vector<vector<char>> board;
    int row,col;
    vector<vector<bool>>vis ;
    bool find = false;
    void dfs(int x,int y,string word,int cur){
        if(cur == word.length()){
            find = true;
            return;
        }
        if(find) return;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx <row && ny>=0 && ny < col && !vis[nx][ny] && board[nx][ny] == word[cur]){
                vis[nx][ny] = 1;
                dfs(nx,ny,word,cur+1);
                vis[nx][ny] = 0;
            }
        }

    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        char start = word[0];
        row = board.size();
        col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == start && !find){
                    vis.assign(row,vector<bool>(col,0)); // 清空
                    vis[i][j] = 1;
                    dfs(i,j,word,1);
                }
            }
        }
        return find;
    }
};
```
