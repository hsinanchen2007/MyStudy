### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int ans = 0;
        loop:
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    ans = count(board, i, j, ans);
                    break loop;
                }
            }
        }
        return ans;
    }

    public int count(char[][] board, int i, int j, int ans){
        int row = i-1;
        int tempRow = i;
        int col = j-1;
        while(row >= 0){
            if(board[row][j] == 'p'){
                ans++;
                break;
            }
            if(board[row][j] == 'B'){
                break;
            }
            row--;
        }

        i += 1;
        while(i < 8){
            if(board[i][j] == 'p'){
                ans++;
                break;
            }
            if(board[i][j] == 'B'){
                break;
            }
            i++;
        }

        while(col >= 0){
            if(board[tempRow][col] == 'p'){
                ans++;
                break;
            }
            if(board[tempRow][col] == 'B'){
                break;
            }
            col--;
        }

        j += 1;
        while(j < 8){
            if(board[tempRow][j] == 'p'){
                
                ans++;
                break;
            }
            if(board[tempRow][j] == 'B'){
                break;
            }
            j++;
        }
        return ans;
    }
}
```