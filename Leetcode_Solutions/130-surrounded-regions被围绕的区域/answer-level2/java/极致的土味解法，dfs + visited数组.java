执行用时 :2 ms, 在所有 Java 提交中击败97.96%的用户
内存消耗 :41.7 MB, 在所有 Java 提交中击败了39.88%的用户

```
class Solution {
    private int[] dx = {-1, 1, 0, 0};
    private int[] dy = {0, 0, -1, 1};
    public void solve(char[][] board) {
        if(board.length == 0 || board[0].length == 0){
            return;
        }
        //如果visited[i][j] == false则都是需要置为‘X’的
        int row = board.length;
        int col = board[0].length;
        boolean[][] visited = new boolean[row][col];
        //找出边界上的'o'，并且从这些‘o’开始遍历
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if((i == 0 || i == row - 1 || j == 0 || j == col - 1) && board[i][j] == 'O' && !visited[i][j]){
                    visited[i][j] = true;
                    dfs(board, visited, i, j);
                }
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
    private void dfs(char[][] board, boolean[][] visited, int x, int y){
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isValid(board, newX, newY) && !visited[newX][newY] && board[newX][newY] == 'O'){
                visited[newX][newY] = true;
                dfs(board, visited, newX, newY);
            }
        }
    }
    private boolean isValid(char[][] board, int x, int y){
        return x >= 0 && x < board.length && y >= 0 && y < board[0].length;
    }
}
```

