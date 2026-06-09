### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int i, j;

        int x = 0, y = 0;//记录rook的位置

        int[] move_x = {-1, 1, 0, 0}; //四种移动的可能性
        int[] move_y = {0, 0, -1, 1};

        for (i = 0; i < board.length; i++) { //找到rook的位置
            for (j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                }
            }
        }

        int storage_x = x; //保存rook的位置
        int storage_y = y;
        
        int res = 0; //统计结果
        for (i = 0; i < 4; i++) {
            x = storage_x;
            y = storage_y;
            while (true) {
                x += move_x[i];
                y += move_y[i];
                //首先是每个字母可移动的边界，再就是该字符为B的情况
                if (x <= 0 || y <= 0 || x >= 8 || y >= 8 || board[x][y] == 'B') {
                    break;
                }
                if (board[x][y] == 'p') {
                    res++;
                    break;
                }
            }
        }
        return res;

    }
}

```