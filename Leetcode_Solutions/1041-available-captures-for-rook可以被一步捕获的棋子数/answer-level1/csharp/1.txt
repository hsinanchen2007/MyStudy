### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int NumRookCaptures(char[][] board) {
         int sum = 0;
        int a = 0;
        int b = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    a = i;
                    b = j;
                    break;
                }
            }
        }

        //四方向同时探测
        //向左
        for(int i = b-1; i >= 0; i--){
            if(board[a][i] == 'B'){
                break;
            }
            if(board[a][i] == 'p'){
                sum++;
                break;
            }
        }

        //向右
        for(int i = b+1; i < 8; i++){
            if(board[a][i] == 'B'){
                break;
            }
            if(board[a][i] == 'p'){
                sum++;
                break;
            }
        }

        //向上
        for(int i = a-1; i >= 0; i--){
            if(board[i][b] == 'B'){
                break;
            }
            if(board[i][b] == 'p'){
                sum++;
                break;
            }
        }

        //向下
        for(int i = a+1; i < 8; i++){
            if(board[i][b] == 'B'){
                break;
            }
            if(board[i][b] == 'p'){
                sum++;
                break;
            }
        }

        return sum;
    }
}

```