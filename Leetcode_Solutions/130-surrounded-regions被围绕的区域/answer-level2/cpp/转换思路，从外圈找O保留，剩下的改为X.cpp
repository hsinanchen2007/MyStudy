#执行用时 :40 ms, 在所有 C++ 提交中击败了87.10%的用户#
```
class Solution {
public:
    int rows,cols;
    void search(int i,int j,vector<vector<char>>& board,vector<vector<bool>>& visited) {
        visited[i][j]=true;
        if ((i<rows-1)&&(board[i+1][j]=='O')&&(!visited[i+1][j]))   search(i+1,j,board,visited);
        if ((i>0)&&(board[i-1][j]=='O')&&(!visited[i-1][j]))    search(i-1,j,board,visited);
        if ((j>0)&&(board[i][j-1]=='O')&&(!visited[i][j-1]))   search(i,j-1,board,visited);
        if ((j<cols-1)&&(board[i][j+1]=='O')&&(!visited[i][j+1]))    search(i,j+1,board,visited);}
    void solve(vector<vector<char>>& board) {    
        rows=board.size();
        if (rows==0)   return;
        cols=board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for (int i=0;i<cols;i++){
            if ((board[0][i]=='O')&&(!visited[0][i]))   this->search(0,i,board,visited);
            if ((board[rows-1][i]=='O')&&(!visited[rows-1][i]))   this->search(rows-1,i,board,visited);}
        for (int i=1;i<rows-1;i++){
            if ((board[i][0]=='O')&&(!visited[i][0]))   this->search(i,0,board,visited);
            if ((board[i][cols-1]=='O')&&(!visited[i][cols-1]))   this->search(i,cols-1,board,visited); }
        for (int i=1;i<rows-1;i++)
            for (int j=1;j<cols-1;j++)   
                if (!visited[i][j])   
                    board[i][j]='X';}
};
```