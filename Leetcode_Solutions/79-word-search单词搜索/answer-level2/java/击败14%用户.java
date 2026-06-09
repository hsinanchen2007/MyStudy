### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    public boolean exist(char[][] board, String word) {
        if(word.length() == 0){
            return false;
        }
        int height = board.length;
        if(height == 0){
            return false;
        }
        int width = board[0].length;
        if(width == 0){
            return false;
        }
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(board[i][j] == word.charAt(0)){
                    boolean[][] mark = new boolean[height][width];
                    mark[i][j] = true;
                    if(exist(new int[]{i, j}, board, word.substring(1), mark)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    private boolean exist(int[] point, char[][] board, String word, boolean[][] mark){
        // 当word为空字符串时，说明之前的所有字母都找到了
        if(word.length() == 0){
            return true;
        }
        int h = board.length;
        int w = board[0].length;
        for(int[] direction : directions){
            int x = point[0] + direction[0];
            int y = point[1] + direction[1];
            if(x >= 0 && x < h && y >= 0 && y < w && board[x][y] == word.charAt(0) && !mark[x][y]){
                mark[x][y] = true;
                if(exist(new int[]{x, y}, board, word.substring(1), mark)){
                    return true;
                };
                mark[x][y] = false;
            }
        }
        return false;
    }
}
```