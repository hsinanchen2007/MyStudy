### 解题思路
直接用方向数组遍历八个方向的细胞，然后统计个数即可。
Time O(n^2)
Space O(n^2)

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int[][] d = {
            {0, 1},
            {0, -1},
            {1, 0},
            {1, -1},
            {1, 1},
            {-1, 1},
            {-1, 0},
            {-1, -1}
        };
        
        int row = board.length;
        int col = board[0].length;
        int[][] temp = new int[row][col];
        for(int i = 0; i < row; i++){
            temp[i] = Arrays.copyOf(board[i], col);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int live = 0;
                for(int m = 0; m < 8; m++){
                    int ci = i + d[m][0];
                    int cj = j + d[m][1];
                    if(ci >= 0 && ci < row && cj >= 0 && cj < col){
                        if(board[ci][cj] == 1)
                            live++;
                    }
                }
                if(board[i][j] == 1 && (live < 2 || live > 3))
                    temp[i][j] = 0;
                if(board[i][j] == 0 && live == 3)
                    temp[i][j] = 1;
            }
        }
        for(int i = 0; i < row; i++){
            board[i] = Arrays.copyOf(temp[i], col);
        }
    }
}
```