### 解题思路
先找到白色车的位置，上下左右再找黑色卒，遇到白象停止查找。

### 代码

```java
class Solution {
       public  int numRookCaptures(char[][] board) {
        int num1 = 0;
        int num2 = 0;
        sign:
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if ('R'==board[i][j]) {
                    num1 = i;
                    num2 = j;
                    break sign;
                }
            }
        }
        
        return calculate(num1, num2, board);
    }

    private static int calculate(int num1, int num2, char[][] board) {

        int count = 0;
        //向右
        for (int i = num2; i < board[num1].length; i++) {
            if ('p'==board[num1][i]) {
                count++;
                break;
            }
            if ('B'==board[num1][i]) {
                break;
            }
        }
        //向左
        for (int i = num2; i > 0; i--) {
            if ('p'==board[num1][i]) {
                count++;
                break;
            }
            if ('B'==board[num1][i]) {
                break;
            }

        }
        //向下
        for (int j = num1; j < board.length; j++) {
            if ('p' == board[j][num2]) {
                count++;
                break;
            }
            if ('B'==board[j][num2]) {
                break;
            }
        }
        //向上
        for (int j = num1; j > 0; j--) {
            if ('p'==board[j][num2]) {
                count++;
                break;
            }
            if ('B'==board[j][num2]) {
                break;
            }
        }
        return count;
    }

}

```