### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int row = 0;
        int col = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        int ans = 0;
        //上
        for(int i = row; i >= 0; i--){
            if(board[i][col] == 'B'){
                break;
            }
            if(board[i][col] == 'p'){
                ans++;
                break;
            }
        }
        //下
        for(int i = row; i < 8; i++){
            if(board[i][col] == 'B'){
                break;
            }
            if(board[i][col] == 'p'){
                ans++;
                break;
            }
        }
        //左
        for(int i = col; i >= 0; i--){
            if(board[row][i] == 'B'){
                break;
            }
            if(board[row][i] == 'p'){
                ans++;
                break;
            }
        }
        //右
        for(int i = row; i < 8; i++){
            if(board[row][i] == 'B'){
                break;
            }
            if(board[row][i] == 'p'){
                ans++;
                break;
            }
        }
        return ans;
    }
}
```