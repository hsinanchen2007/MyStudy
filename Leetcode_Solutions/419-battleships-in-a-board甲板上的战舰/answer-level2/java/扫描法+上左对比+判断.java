### 解题思路
1，逐行扫描；
2，如果扫描的元素是X，分别与上面和左面相邻的元素比较，如果上和左都没有X，则战舰数量+1；如果上和左发现有X，则说明和左上的某个战舰组成一个战舰，战舰数量不变，继续扫描，直至扫描完成；

### 代码

```java
class Solution {
    public int countBattleships(char[][] board) {
        int ans = 0;
        int rows = board.length;
        if (rows != 0) {
            int cols = board[0].length;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (board[i][j] == 'X') {
                        if (i == 0 && j == 0) {
                            ans++;
                        } else if (i > 0 && j == 0) {
                            if (board[i - 1][j] != 'X') {
                                ans++;
                            }
                        } else if (i == 0 && j > 0) {
                            if (board[i][j - 1] != 'X') {
                                ans++;
                            }
                        } else if (i > 0 && j > 0) {
                            if (board[i][j - 1] != 'X' && board[i - 1][j] != 'X') {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
}
```