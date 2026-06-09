### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private final int N = 8;
    private int[][] direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public int numRookCaptures(char[][] board) {
        if(board == null || board.length == 0 || board[0].length == 0){
            return 0;
        }
        int total = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == 'R'){
                    for(int[] d: direction){
                        int nexti = i + d[0];
                        int nextj = j + d[1];
                        total += dfs(board, nexti, nextj, d);
                    }
                }
            }
        }
        return total;
    }

    private int dfs(char[][] board, int r, int c, int[] d){
        if(r >= N || r < 0 || c >= N || c < 0){
            return 0;
        }
        if(board[r][c] == 'B'){
            return 0;
        }
        if(board[r][c] == 'p'){
            return 1;
        }
        int nexti = r + d[0];
        int nextj = c + d[1];
        return dfs(board, nexti, nextj, d);
    }

}
```