### 解题思路
普通的数组问题，注意点边界条件就好

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int rr = 0;
        int rc = 0;
        boolean flag = false;
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j] == 'R'){
                    rr = i;
                    rc = j;
                    flag = true;
                    break;
                    
                }
            }
            if(flag)break;
        }
        int count = 0;
        int tr = rr-1;
        while(tr >= 0){
            if(board[tr][rc] == 'B'){
                break;
            }else if(board[tr][rc] == 'p'){
                count++;
                break;
            }
            tr--;
        }
        tr = rr + 1;
        while(tr < board.length){
            if(board[tr][rc] == 'B'){
                break;
            }else if(board[tr][rc] == 'p'){
                count++;
                break;
            }
            tr++;
        }
        int tc = rc -1;
        while(tc >= 0){
            if(board[rr][tc] == 'B'){
                break;
            }else if(board[rr][tc] == 'p'){
                count++;
                break;
            }
            tc--;
        }
        tc = rc + 1;
        while(tc < board[0].length){
            if(board[rr][tc] == 'B'){
                break;
            }else if(board[rr][tc] == 'p'){
                count++;
                break;
            }
            tc++;
        }
        return count;
    }
}
```