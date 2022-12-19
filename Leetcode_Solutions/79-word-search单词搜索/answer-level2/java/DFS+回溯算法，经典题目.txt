### 解题思路
具体的为dfs+回溯算法实现，回溯的时候一定要注意visited的标记，包括移除的时候，要转成false

### 代码

```java
class Solution {
    private int row = 0;
    private int col = 0;
    private int[][] direction = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
    private char[][] map;

    public boolean exist(char[][] board, String word){
        if(board == null || board.length == 0 || board[0].length == 0){
            return false;
        }

        if(word == null || word.length() == 0){
            return true;
        }
        row = board.length;
        col = board[0].length;
        this.map = board;
        boolean[][] visited = new boolean[row][col];
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(dfs(0, i, j, word, visited)){
                    return true;
                }
            }
        }
      return false;
    }

    public boolean dfs(int k, int x, int y, String word, boolean[][] visited){
        if(k == word.length()){
            return true;
        }

        if(x < 0 || x >= row || y<0 || y>= col || visited[x][y] || word.charAt(k) != map[x][y]){
            return false;
        }
        visited[x][y] = true;
        for(int[] d : direction){
            int nr = x + d[0];
            int nc = y + d[1];
            if(dfs(k+1, nr, nc, word, visited)){
                return true;
            }
        }
        visited[x][y] = false;
        return false;
    }
}
```