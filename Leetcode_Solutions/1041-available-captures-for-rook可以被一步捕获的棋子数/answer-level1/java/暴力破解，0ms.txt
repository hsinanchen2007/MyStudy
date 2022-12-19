### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int count = 0;
        int x=0,y=0;
        for(int i = 0; i < 8; i++){//扫描棋盘，找到'R'
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    for(x = i; x < 8; x++){//扫描右边
                        if(board[x][j] == 'B')
                            break;
                        else if(board[x][j] == 'p'){
                            count++;break;
                        }   
                    }
                    for(x = i; x > 0; x--){//扫描左边
                        if(board[x][j] == 'B')
                            break;
                        else if(board[x][j] == 'p'){
                            count++;break;
                        }
                    }
                    for(y = j; y > 0; y--){//扫描上边
                        if(board[i][y] == 'B')
                            break;
                        else if(board[i][y] == 'p'){
                            count++;break;
                        }
                    }
                    for(y = j; y < 8; y++){//扫描上边
                        if(board[i][y] == 'B')
                            break;
                        else if(board[i][y] == 'p'){
                            count++;break;
                        }
                    }
                    break;
                } 
            }
        }
        return count;
    }
}
```