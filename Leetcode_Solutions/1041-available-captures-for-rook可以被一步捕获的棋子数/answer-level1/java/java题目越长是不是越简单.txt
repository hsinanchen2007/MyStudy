### 解题思路
java题目越长是不是越简单

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        if(board==null|| board.length==0 || board[0].length ==0){
            return 0;
        }

        int m = board.length;
        int n = board[0].length;
        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'R'){
                    
                   for(int h = i; h < n; h++){
                        if(board[h][j] == 'B'){
                            break;
                        }else if(board[h][j] == 'p'){
                            count++;
                            break;
                        }
                    }
                    
                    for(int h = i; h >= 0; h--){
                        if(board[h][j] == 'B'){
                            break;
                        }else if(board[h][j] == 'p'){
                            count++;
                            break;
                        }
                    }
                    
                    for(int l = j; l >= 0; l--){
                        if(board[i][l] == 'B'){
                            break;
                        }else if(board[i][l] == 'p'){
                            count++;
                            break;
                        }
                    }
                    
                    for(int l = j; l < m; l++){
                        if(board[i][l] == 'B'){
                            break;
                        }else if(board[i][l] == 'p'){
                            count++;
                            break;
                        }
                    }
                    return count;

                }
            }
        }

        return 0;
    }
}
```