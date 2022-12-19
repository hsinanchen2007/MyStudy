### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[][] row = new int[9][9];
        int[][] col = new int[9][9];
        int[][] box = new int[9][9];

        for(int r = 0; r < 9; r ++) {
            for(int c = 0; c < 9; c++) {
                int number = board[r][c];
                if(number == '.')continue;
                number = (int)number - 49;
                
                row[r][number ]++;
                col[c][number]++;
                box[r/3*3 + c/3][number]++;

                if(row[r][number] > 1 || 
                   col[c][number] > 1 || 
                   box[r/3*3 + c/3][number]>1
                ) {
                    return false;
                }

            }

        }

        return true;
    }
}
```