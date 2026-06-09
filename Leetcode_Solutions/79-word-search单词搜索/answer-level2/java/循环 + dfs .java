### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        
        int n = board.length;
        int m = board[0].length;

        int[][] map = new int[n][m];

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                boolean result = travel(board, n, m, i, j, word, 0, map);
                if (result) {
                    return true;
                }
            }
        }
        return false;
    }

    boolean travel(char[][] board, int n, int m, int y, int x, 
                    String word, int i, int[][] map) {
         if (word.length() == i) {
            return true;
        }
        if (y < 0 || y >= n || x<0 || x>=m) {
            return false;
        }
        if (board[y][x] != word.charAt(i)) {
            return false;
        }
        if (map[y][x] == 1) {
            return false;
        } else {
            map[y][x] = 1;
        }     
        // up
        if(travel(board, n, m, y-1, x, word, i + 1, map) ||
        // down
        travel(board, n, m, y+1, x, word, i + 1, map) ||
        // left
        travel(board, n, m, y, x-1, word, i + 1, map) ||
        // right
        travel(board, n, m, y, x+1, word, i + 1, map)) {
            return true;
        }  
        map[y][x] = 0;
        return false;
    }
}
```