### 解题思路
1.首先找到车子R的xy坐标
2.在上下左右四个方向查找：
  1).如果碰到象B则此方向不通
  2).如果碰到卒p则消灭一个，数量+1
  3).到边缘了则结束

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {

        // 定义上下左右四个方向
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        int result = 0;
        for (int rx = 0; rx < 8; rx++) {
            for (int ry = 0; ry < 8; ry++) {
                if (board[rx][ry] == 'R') {
                    for (int index = 0; index < 4; index++) {
                        result += kill(board, rx, ry, dx[index], dy[index]);
                    }
                }
            }
        }

        return result;
    }


    private int kill(char[][] board, int x, int y, int xDirection, int yDirection) {

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {

            if (board[x][y] == 'B') {
                return 0;
            }

            if (board[x][y] == 'p') {
                return 1;
            }

            x = x + xDirection;
            y = y + yDirection;

        }

        return 0;
    }
}
```