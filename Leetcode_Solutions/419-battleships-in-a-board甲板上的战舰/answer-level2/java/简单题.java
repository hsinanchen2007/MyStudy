### 解题思路
简单题，注意边界条件

### 代码

```java
class Solution {
    public int countBattleships(char[][] board) {
               int count = 0;
        if (board == null){
            return count;
        }

        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length; j++){
                int icur = i;
                int jcur = j;
                if(board[icur][jcur] == 'X'){
                    while (jcur+1<board[0].length&&
                            board[icur][jcur+1] == 'X'){
                        board[icur][jcur+1] = '.';
                        jcur = jcur + 1;
                    }
                    while (icur+1<board.length&&
                            board[icur+1][jcur] == 'X'){
                        board[icur+1][jcur] = '.';
                        icur = icur + 1;
                    }
                    count++;
                }
            }
        }
        return count;
    }
}
```