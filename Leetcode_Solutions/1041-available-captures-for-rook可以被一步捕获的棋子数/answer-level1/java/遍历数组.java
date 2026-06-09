### 解题思路
此处撰写解题思路
这次并没有创建移动方向的数组，直接找到R所在位置，然后在这一行一列里直接找p和B即可
### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int r = 0, c = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    r = i;
                    c = j;
                    break;
                }
            }
        }
        int temp = 0;
        for(int i = r; i < 8; i++){
            if (board[i][c] == 'p'){
                temp += 1;
                break;
            }else if(board[i][c] == 'B')
                break;
        }
        for(int i = r; i >= 0; i--){
            if (board[i][c] == 'p'){
                temp += 1;
                break;
            }else if(board[i][c] == 'B')
                break;
        }
        for(int i = c; i < 8; i++){
            if (board[r][i] == 'p'){
                temp += 1;
                break;
            }else if(board[r][i] == 'B')
                break;
        }
        for(int i = c; i >= 0; i--){
            if (board[r][i] == 'p'){
                temp += 1;
                break;
            }else if(board[r][i] == 'B')
                break;
        }
        return temp;
    }
}
```