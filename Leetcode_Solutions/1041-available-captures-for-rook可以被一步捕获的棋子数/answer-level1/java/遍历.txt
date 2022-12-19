### 解题思路
找到R的时间复杂度O(n^2).空间复杂度O(1)

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int p=0, q=0, count=0;
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[0].length; j++) {
                if (board[i][j] == 'R') {
                    p = i;
                    q = j;
                    break;
                }
            }
        }
        for (int i=q; i>=0; i--) {
            if (board[p][i] == 'B') {
                break;
            } else if (board[p][i] == 'p') {
                count++;
                break;
            }
        }
        for (int i=q; i<board[0].length; i++) {
            if (board[p][i] == 'B') {
                break;
            } else if (board[p][i] == 'p') {
                count++;
                break;
            }
        }
        for (int j=p; j>=0; j--) {
            if (board[j][q] == 'B') {
                break;
            } else if (board[j][q] == 'p') {
                count++;
                break;
            }
        }
        for (int j=p; j<board.length; j++) {
            if (board[j][q] == 'B') {
                break;
            } else if (board[j][q] == 'p') {
                count++;
                break;
            }
        }
        return count;

    }
}
```