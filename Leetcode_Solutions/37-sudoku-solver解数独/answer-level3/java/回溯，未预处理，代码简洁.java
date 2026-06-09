```
class Solution {
    private char[][] board;
    public void solveSudoku(char[][] board) {
        this.board = board;
        dfs(0,0);
    }
    private boolean dfs(int i,int j){
        if (i==9)
            return true;
        if (board[i][j]!='.')
            return next_dfs(i,j);
        for (int x=0;x<9;x++){
            board[i][j] = (char)(x+'1');
            if (isTrue(i,j) && next_dfs(i,j))
                    return true;
            board[i][j] = '.';
        }
        return false;
    }
    private boolean next_dfs(int i,int j){
        if (j!=8)
            return dfs(i,j+1);
        else
            return dfs(i+1,0);
    }
    private boolean isTrue(int i,int j){
        for (int x=0;x<9;x++)
            if ((board[i][x]==board[i][j] && x!=j) || (board[x][j]==board[i][j] && x!=i))
                return false;
        for (int x=i/3*3;x<i/3*3+3;x++)
            for (int y=j/3*3;y<j/3*3+3;y++)
                if (board[x][y]==board[i][j] && !(x==i && y==j))
                    return false;
        return true;
    }
}
```
