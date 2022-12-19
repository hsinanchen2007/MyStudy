### 解题思路
看懂题目了就会发现很简单。。而且棋盘大小其实也是固定的

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        // 无聊题。。
        int rows = board.length;
        int cols = board[0].length;
        if(rows == 0 || cols == 0 || board == null) {
            return 0;
        }
        int cnt = 0;
        int[][] location = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'R') {
                    for(int k = 0; k < 4; k++) {
                        int x = i, y = j;
                        while(true) {
                            x += location[k][0];
                            y += location[k][1];
                            if(x >= cols || x < 0 || y < 0 || y >= rows || board[x][y] == 'B') {
                                break;
                            }
                            if(board[x][y] == 'p') {
                                cnt++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
}
```