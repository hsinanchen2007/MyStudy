### 解题思路
写了好多个for循环

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
    for (int i = 0; i < board.length; i++) {
            for (int a = 0; a < board[i].length - 1; a++) {
                for (int b = a + 1; b < board[i].length; b++) {
                    if (board[i][a] == board[i][b]) {
                        if(board[i][a]!='.'){
                            return false;
                        }else{
                            continue;
                        }
                    }
                }
            }
        }
            for (int i = 0; i < board.length; i++) {
            for (int a = 0; a < board[i].length - 1; a++) {
                for (int b = a + 1; b < board[i].length; b++) {
                    if (board[a][i] == board[b][i]) {
                        if(board[a][i] !='.'){
                            return false;
                        }else{
                            continue;
                        }
                    }
                }
            }
        }
        char[] temp = new char[9];
        for (int i = 0; i < board.length; i += 3) {
            for (int j = 0; j < board.length; j += 3) {
                int c = 0;
                for (int a = i; a < i + 3; a++) {
                    for (int b = j; b < j + 3; b++) {
                        temp[c] = board[a][b];
                        c++;
                    }
                }
                for (int a = 0; a < temp.length - 1; a++) {
                    System.out.println (temp);
                    for (int b = a + 1; b < temp.length; b++) {
                        if (temp[a] == temp[b]) {

                            if(temp[a]!='.'){
                                return false;
                            }else{
                                continue;
                            }

                        }
                    }
                }
            }
        }

        return true;
    }
}
```