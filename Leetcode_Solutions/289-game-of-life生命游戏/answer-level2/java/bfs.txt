### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int m, n;
    private int[][] direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    public void gameOfLife(int[][] board) {
        if(board == null || board.length == 0 || board[0].length == 0){
            return;
        }
        m = board.length;
        n = board[0].length;
        int up[][] = new int[m][n];
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                up[i][j] = board[i][j];
                cnt = 0;
                for(int[] dd : direction){
                    int nextr = dd[0] + i;
                    int nextc = dd[1] + j;
                    int res = dfs(board, nextr, nextc);
                    cnt += res;
                }
                //int res = dfs(board, i, j, cnt, 0);
                if(board[i][j] == 1){
                    if(cnt < 2 || cnt > 3){
                        up[i][j] = 0;
                    }
                }else{
                    if(cnt == 3){
                        up[i][j] = 1;
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != up[i][j]){
                    board[i][j] = up[i][j];
                }
            }
        }
    }

    private int dfs(int[][] board, int r, int c){
        if(r >= m || r < 0 || c >= n || c < 0){
            return 0;
        }
        if(board[r][c] == 1){
            return 1;
        }else{
            return 0;
        }
    }
}
```