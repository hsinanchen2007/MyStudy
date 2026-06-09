### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    public void solve(char[][] board) {
        int height = board.length;
        if(height == 0){
            return;
        }
        int width = board[0].length;
        if(width == 0){
            return;
        }       
        // 标记矩阵
        boolean[][] mark = new boolean[height][width];
        // 搜寻四个边
        // -------- row = 0
        for(int col = 0; col < width; col++){
            if(board[0][col] == 'O'){
                dfs(new int[]{0, col}, board, mark);   
            }
            if(board[height-1][col] == 'O'){
                dfs(new int[]{height - 1, col}, board, mark);
            }
        }
        // |||||||||col = 0
        for(int row = 0; row < height; row++){
            if(board[row][0] == 'O'){
                dfs(new int[]{row, 0}, board, mark);
            }
            if(board[row][width-1] == 'O'){
                dfs(new int[]{row, width-1}, board, mark);
            }
        }
        // 通过mark赋值
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){  
                if(mark[i][j]){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }

    // 以point为起点进行dfs
    private void dfs(int[] point, char[][] board, boolean[][] mark){
        // 标记一下
        mark[point[0]][point[1]] = true;
        board[point[0]][point[1]] = 'X';
        for(int[] direction : directions){
            int x = point[0] + direction[0];
            int y = point[1] + direction[1];
            if(x >= 0 && x < board.length && y >= 0 && y < board[0].length && board[x][y] == 'O'){
                dfs(new int[]{x, y}, board, mark);
            }
        }
    }
}
```