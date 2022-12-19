### 解题思路
第一步，查找`R`所在的位置，然后以`R`为中心，四路展开检索`p`的位置，根据规则进行匹配，最后进行统计。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int rI = 0;
        int rJ = 0;
        int catchNumber = 0;
        for (int i=0; i < board.length; ++i) {
            for (int j=0; j < board[i].length; ++j) {
                if (board[i][j] == 'R') {
                    rI = i;
                    rJ = j;
                    break;
                }
            }
        }

        // 查找rI数组捕获量
        boolean find = false;
        for (int i=0; i < rJ; ++i) {
            if (board[rI][i] == 'p') {
                if (find == false) {
                    find = true;
                }
            }
            if (board[rI][i] == 'B') {
                find = false;
            }
        }

        if (find) {
            catchNumber++;
        }
        
        find = false;
        for (int i=rJ + 1; i < 8; ++i) {
            if (board[rI][i] == 'p') {
                if (find == false) {
                    find = true;
                }
            }
            if (board[rI][i] == 'B') {
                break;
            }
        }

        if (find) {
            catchNumber++;
        }
        find = false;


        // 查找rJ数组捕获量
        for (int i=0; i < rI; ++i) {
            if (board[i][rJ] == 'p') {
                if (find == false) {
                    find = true;
                }
            }
            if (board[i][rJ] == 'B') {
                find = false;
            }
        }

        if (find) {
            catchNumber++;
        }
        find = false;

        for (int i=rI + 1; i < 8; ++i) {
            if (board[i][rJ] == 'p') {
                if (find == false) {
                    find = true;
                }
            }
            if (board[i][rJ] == 'B') {
                break;
            }
        }

        if (find) {
            catchNumber++;
        }

        return catchNumber;
    }
}
```