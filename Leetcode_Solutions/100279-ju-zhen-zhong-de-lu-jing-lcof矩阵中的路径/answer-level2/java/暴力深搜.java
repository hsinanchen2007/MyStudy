### 解题思路

暴力dfs，主要的一点是递归失败后要注意状态的复原

### 代码

```java
class Solution {
    // 初始化相同矩阵表明是否遍历过
    // 遍历所有格子，找到是否被遍历
    private int[][] visited;
    private int[] lp = {0,0,1,-1}, rp = {1,-1,0,0};
    private char[] words;
    public boolean exist(char[][] board, String word) {
        visited = new int[board.length][board[0].length];
        words = word.toCharArray();
        for(int i = 0; i < board.length; i ++) {
            for(int j = 0; j < board[0].length; j ++) {
                int point = 0;
                if(words[point] == board[i][j]) {
                    visited[i][j] = 1;
                    if(dfs(board,i,j,++point)) return true;
                }
                // 重置visited
                for(int[] v : visited) Arrays.fill(v,0);
            }
        }
        return false;
    }
    private boolean dfs(char[][] board, int x, int y, int point) {
        if(point == words.length) return true;
        int tx = x, ty = y, tp = point;
        for(int i = 0; i < 4; i ++) {
            x = tx + lp[i];
            y = ty + rp[i];
            if(x >= 0 && x < visited.length && y >= 0 && y < visited[0].length && words[point] == board[x][y] && visited[x][y] == 0) {
                visited[x][y] = 1;
                if(dfs(board,x,y,++point)) return true;
                // 下面这个要加上
                visited[x][y] = 0;
                point = tp;
            }
        }
        return false;
    }
}
```