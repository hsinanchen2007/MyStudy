### 解题思路
很傻逼的把所有情况写了一遍

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 0) {
                    int sum = 0;
                    if (i > 0 && j > 0 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 3)) sum++; 
                    if (i > 0 && (board[i - 1][j] == 1 || board[i - 1][j] == 3)) sum++; 
                    if (i > 0 && j < board[0].length - 1 && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 3)) sum++; 
                    if (j > 0 && (board[i][j - 1] == 1 || board[i][j - 1] == 3)) sum++;  
                    if (j < board[0].length - 1 && (board[i][j + 1] == 1 || board[i][j + 1] == 3)) sum++;   
                    if (i < board.length - 1 && j > 0 && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 3)) sum++; 
                    if (i < board.length - 1 && (board[i + 1][j] == 1 || board[i + 1][j] == 3)) sum++;    
                    if (i < board.length - 1 && j < board[0].length - 1 && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 3)) sum++; 
                    if (sum == 3) board[i][j] = 2;           
                } else if (board[i][j] == 1) {
                    int sum = 0;
                    if (i > 0 && j > 0 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 3)) sum++; 
                    if (i > 0 && (board[i - 1][j] == 1 || board[i - 1][j] == 3)) sum++; 
                    if (i > 0 && j < board[0].length - 1 && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 3)) sum++; 
                    if (j > 0 && (board[i][j - 1] == 1 || board[i][j - 1] == 3)) sum++;  
                    if (j < board[0].length - 1 && (board[i][j + 1] == 1 || board[i][j + 1] == 3)) sum++;   
                    if (i < board.length - 1 && j > 0 && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 3)) sum++; 
                    if (i < board.length - 1 && (board[i + 1][j] == 1 || board[i + 1][j] == 3)) sum++;    
                    if (i < board.length - 1 && j < board[0].length - 1 && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 3)) sum++; 
                    if (sum < 2 || sum > 3) board[i][j] = 3;           
                }
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 2) board[i][j] = 1;
                if (board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
}
```