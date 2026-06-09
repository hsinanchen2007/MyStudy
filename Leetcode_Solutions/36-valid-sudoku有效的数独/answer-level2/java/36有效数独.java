### 解题思路
我的想法是这样的，但是在实现上面有点小问题，然后参照别人的[https://leetcode-cn.com/problems/valid-sudoku/solution/java-bu-yong-shi-yong-e-wai-kong-jian-yun-xing-shi/](),成功解决了我的疑惑。
思路：
对于board[i][j]=ch分别从三种情况讨论：
    &emsp;&emsp;1.ch是否存在i=row行：board[row][column] == ch()
    &emsp;&emsp;2.ch是否存在j=cloum列；board[row][column] == ch()
    &emsp;&emsp;3.ch是否存在小九宫格中；board[row][column] == ch(0< column <j且colum != j,0 < row <i且row != i)

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
       for(int i = 0; i < board.length; i++){
           for(int j = 0; j < board[i].length; j++){
               if(board[i][j] != '.'){
                    if(!isValid(board, board[i][j],i, j))
                        return false;
               }
           }
       }
       return true;
    }
    public boolean isValid(char[][] board, char ch, int row, int column){
        for(int i = 0; i < row; i++){
            if(board[i][column] == ch && i != row ){
                return false;
            }
        }
        for(int j = 0; j < column; j++){
            if(board[row][j] == ch && j != column){
                return false;
            }
        }
        int n = row / 3;
        int m = column / 3;
        for(int i = n*3; i < (n+1)*3; i++){
            for(int j = m*3; j < (m+1)*3; j++){
                if(board[i][j] == ch && i!= row && j !=column){
                    return false;
                }
            }
        }
        return true;
    }
}
```