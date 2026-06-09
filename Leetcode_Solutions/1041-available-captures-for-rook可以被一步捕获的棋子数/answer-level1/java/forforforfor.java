### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
         int Ri=0;
        int Rj=0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if(board[i][j]=='R') {
                    Ri=i;
                    Rj=j;
               }
            }
        }
        //N6
        int res=0;
        for(int i1=Ri+1;i1<8;i1++){
            if(board[i1][Rj]=='B') break;
            if(board[i1][Rj]=='p') {
                res++;
                break;
            }
        }
        //N12
        for(int i1=Ri-1;i1>0;i1--){
            if(board[i1][Rj]=='B') break;
            if(board[i1][Rj]=='p') {
                res++;
                break;
            }
        }
        //N3
        for(int j1=Rj+1;j1<8;j1++){
            if(board[Ri][j1]=='B') break;
            if(board[Ri][j1]=='p') {
                res++;
                break;
            }
        }
        //N9
        for(int j1=Rj-1;j1>0;j1--){
            if(board[Ri][j1]=='B') break;
            if(board[Ri][j1]=='p') {
                res++;
                break;
            }
        }
        return res;
    }
}
```