### 解题思路
实际上只需要找到车，然后朝他的四个方向遍历即可，碰到一个非空白的格子就停止那个方向的遍历，若碰到的是p则ans++；。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
 int ans = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                //找到车的位置
                if (board[i][j] == 'R') {
                    //向上
                    for (int k = i - 1; k > 0; k--) {
                        if (board[k][j] != '.') {
                            if (board[k][j] == 'p') {
                                ans++;
                            }
                            break;
                        }
                    }
                    //向下
                    for (int k = i + 1; k < board.length; k++) {
                        if (board[k][j] != '.') {
                            if (board[k][j] == 'p')
                                ans++;
                            break;
                        }
                    }
                    //向左
                    for (int k = j - 1; k > 0; k--) {
                        if (board[i][k] != '.') {
                            if (board[i][k] == 'p')
                                ans++;
                            break;
                        }
                    }
                    //向右
                    for (int k = j + 1; k < board[i].length; k++) {
                        if (board[i][k] != '.') {
                            if (board[i][k] == 'p')
                                ans++;
                            break;
                        }
                    }
                    return ans;
                }
            }
        }
        return ans;
    }
}
```