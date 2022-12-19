初看题目，我想起了《挑战程序设计竞赛》中的例题，“花园积水”问题，于是写出了这样的代码：

### 基础解法

与积水问题相似，所有`X`相连的地方，当成同一艘战舰

```java
class Solution {
    int[][] derect = new int[][]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    public int countBattleships(char[][] board) {
        int ret = 0;
        for (int i = 0; i < board.length; i++) {
           for (int j = 0; j < board[i].length; j++) {
               if (board[i][j] == 'X') {
                   ret++;
                   helper(board, i, j);
               }
           }
        }
        return ret;
    }
    
    private void helper(char[][] board, int x, int y) {
        board[x][y] = '.';
        
        for (int i = 0; i < 4; i++) {
            int nx = x + derect[i][0], ny = y + derect[i][1]; 
            if (0 <= nx && nx < board.length &&
                0 <= ny && ny < board[0].length &&
                board[nx][ny] == 'X')   helper(board, nx, ny);
        }
    }
}
```

用时`2ms`

但是“花园积水”问题明显更为复杂，因为其还要考虑斜对角线的情况，而此题只考虑横行和竖行，故大可不必如此麻烦，**“从上至下，从左至右”扫描的时候，我们只关心当前位置的左边和上边有没有`X`**。故，写出代码：

### 优化

```java
class Solution {
    public int countBattleships(char[][] board) {
        int ret = 0;
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'X') {
                    if (i == 0 && j == 0)   
                        ret++;
                    else if (i == 0 && j > 0 && board[i][j-1] == '.')
                        ret++;
                    else if (j == 0 && i > 0 && board[i-1][j] == '.')
                        ret++;
                    else if ((i > 0 && board[i-1][j] == '.') 
                             && (j > 0 && board[i][j-1] == '.'))
                        ret++;
                }
            }
        }
        return ret;
    }
}
```

脑子一时没转过弯，正向写了一堆判断条件，用时 `1ms`。

越看越不对，然后，反向写了判断条件，代码简洁了不是一点半点。。。

### 最终版

```java
class Solution {
    public int countBattleships(char[][] board) {
        int ret = 0;
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'X') {
                    if ((i > 0 && board[i-1][j] == 'X') 
                        || (j > 0 && board[i][j-1] == 'X'))
                        continue;
                    ret++;
                }
            }
        }
        return ret;
    }
}
```