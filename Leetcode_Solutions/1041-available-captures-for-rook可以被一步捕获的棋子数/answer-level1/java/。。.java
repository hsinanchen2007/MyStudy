### 解题思路
感觉这种题目是类似dfs的，但是又不能用dfs做。

### 代码

```java
class Solution {
    private int m;
    private int n;
    private int count;

    public void left(char[][] board, int i, int j){
        if(j < 0 || board[i][j] == 'R' || board[i][j] == 'B')
            return;
        
        if(board[i][j] == 'p'){
            count += 1;
            return;
        }

        left(board, i, j-1);
    }

    public void right(char[][] board, int i, int j){
        if(j == n || board[i][j] == 'R' || board[i][j] == 'B')
            return;
        
        if(board[i][j] == 'p'){
            count += 1;
            return;
        }

        right(board, i, j+1);
    }

    public void top(char[][] board, int i, int j){
        if(i < 0 || board[i][j] == 'R' || board[i][j] == 'B')
            return;
        
        if(board[i][j] == 'p'){
            count += 1;
            return;
        }

        top(board, i-1, j);
    }

    public void bottom(char[][] board, int i, int j){
        if(i ==m || board[i][j] == 'R' || board[i][j] == 'B')
            return;
        
        if(board[i][j] == 'p'){
            count += 1;
            return;
        }

        bottom(board, i+1, j);
    }

    public int numRookCaptures(char[][] board) {
        if(board == null || board.length == 0)
            return 0;

        m = board.length;
        n = board[0].length;
        count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'R'){
                    left(board, i, j-1);
                    right(board, i, j+1);
                    top(board, i-1, j);
                    bottom(board, i+1, j);
                }
            }
        }
        return count;
    }
}
```