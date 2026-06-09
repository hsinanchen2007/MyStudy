### 解题思路

其实看懂题就知道怎么做了，先定位车在哪里，然后朝四个方向一步一步挪，到边或者碰到B就停止，换个方向继续，碰到P就加以，再换个方向。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int count = 0;
        int abscissa = 0;
        int ordinate = 0;
        int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    abscissa = i;
                    ordinate = j;
                    break;
                }
            }
        }

        for (final int[] d : dir) {
            for (int j = 0; ; j++) {
                int x = abscissa + j * d[0];
                int y = ordinate + j * d[1];
                if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B') {
                    break;
                }
                if (board[x][y] == 'p') {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
}
```

搜索wx公众号，kanshanshuo，可以获取免费技术资料，也可以直接控制台回复，帮你找想要的技术资料。
