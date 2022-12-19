### 解题思路
aa

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int row = board.length,col = board[0].length;
        int res =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 'R'){
                    for(int k=i;k>=0;k--){
                        if(board[k][j]=='B') break;
                        else if(board[k][j]=='p'){
                            res += 1;
                            break;
                        }
                    }
                    for(int k=i;k<row;k++){
                        if(board[k][j]=='B') break;
                        else if(board[k][j]=='p'){
                            res += 1;
                            break;
                        }
                    }
                    for(int k=i;k>=0;k--){
                        if(board[i][k]=='B') break;
                        else if(board[i][k]=='p'){
                            res += 1;
                            break;
                        }
                    }
                    for(int k=i;k<col;k++){
                        if(board[i][k]=='B') break;
                        else if(board[i][k]=='p'){
                            res += 1;
                            break;
                        }
                    }
                }
            }
        }
        return res;

    }
}
```