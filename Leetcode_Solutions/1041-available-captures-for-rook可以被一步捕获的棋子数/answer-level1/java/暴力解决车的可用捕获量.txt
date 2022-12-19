1.找到R车的位置
2.分别向四个方向找卒,如果遇到像则结束循环，如果遇到卒加一并且结束


### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int x = 0;
        int y = 0;
        for (int i = 0; i < board.length; i++) {
            char[] chars = board[i];
            for (int j = 0; j < chars.length; j++) {
                if(chars[j] == 'R'){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int count = 0;
        for (int i = x-1; i >=0; i--) {
            if(board[i][y] == 'B'){
                break;
            }
            char c = board[i][y];
            if(board[i][y] == 'p'){
                count++;
                break;
            }
        }
        for (int i =  x+1; i < board.length; i++) {
            if(board[i][y] == 'B'){
                break;
            }
            if(board[i][y] == 'p'){
                count++;
                break;
            }
        }
        for (int i =  y+1; i < board.length; i++) {
            if(board[x][i] == 'B'){
                break;
            }
            if(board[x][i] == 'p'){
                count++;
                break;
            }
        }
        for (int i = y-1; i >=0; i--) {
            if(board[x][i] == 'B'){
                break;
            }
            if(board[x][i] == 'p'){
                count++;
                break;
            }
        }
        return count;
    }
}
```