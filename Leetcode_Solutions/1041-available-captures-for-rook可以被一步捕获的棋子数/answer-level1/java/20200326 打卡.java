### 解题思路
思路没啥好说的，先定位到车的位置，而后对四个方位记得遍历，要注意遍历的时候不能被己方的棋子挡了路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int count = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'R') {
                    int row = i;
                    int column = j + 1;
                    while (column < board[0].length && board[row][column] != 'B' && board[row][column]!='P') {
                        if (board[row][column] == 'p') {
                            count += 1;
                            break;
                        }
                        column++;
                    }
                    row = i;
                    column = j -1;
                    while (column >= 0 && board[row][column] != 'B'&& board[row][column]!='P') {
                        if (board[row][column] == 'p') {
                            count += 1;
                            break;
                        }
                        column--;
                    }
                    row = i+1;
                    column = j;
                    while (row < board.length && board[row][column] != 'B'&& board[row][column]!='P') {
                        if (board[row][column] == 'p') {
                            count += 1;
                            break;
                        }
                        row++;
                    }
                    row = i-1;
                    column = j;
                    while (row >= 0 && board[row][column] != 'B'&& board[row][column]!='P') {
                        if (board[row][column] == 'p') {
                            count += 1;
                            break;
                        }
                        row--;
                    }
                    break;
                }
            }
        }
        return count;
    }
}
```