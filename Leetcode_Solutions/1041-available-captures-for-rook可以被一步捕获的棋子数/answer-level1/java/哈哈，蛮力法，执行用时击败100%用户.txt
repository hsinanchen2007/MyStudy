### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int count = 0;
        for(int i = 0; i < 8;i++){
            for(int j = 0; j < 8;j++){
                if(board[i][j] == 'R'){
                    for(int row = i + 1;row<8;row++){
                        if(board[row][j] != '.'){
                            if(board[row][j] == 'p') count++;
                            break;
                        }
                    }
                    for(int row = i - 1; row >= 0 ;row--){
                        if(board[row][j] != '.'){
                            if(board[row][j] == 'p') count++;
                            break;
                        }
                    }
                    for(int col = j + 1;col < 8;col++){
                        if(board[i][col] != '.'){
                            if(board[i][col] == 'p') count++;
                            break;
                        }
                    }
                    for(int col = j - 1;col >= 0;col--){
                        if(board[i][col] != '.'){
                            if(board[i][col] == 'p') count++;
                            break;  
                        }
                    }
                    return count;
                }
            }
        }
        return count; 
    }
}
```