### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        if(board.length<1){

        }else if(board[0].length<1){

        }else{
            int[][] a = new int[board.length][board[0].length];
            for(int i=0;i<board.length;i++){
                for(int j=0;j<board[0].length;j++){
                    a[i][j]=board[i][j];
                }
            }
            for(int i=0;i<board.length;i++){
                for(int j=0;j<board[0].length;j++){
                    board[i][j]=f(a,i,j);
                }
            }
        }
    }

    public int f(int[][] board,int p,int q){
        int count=0;
        if(p>0){
            if(board[p-1][q]==1){
                count++;
            }
            if(q>0){
                if(board[p-1][q-1]==1){
                    count++;
                }
            }
             if(q<board[0].length-1){
                if(board[p-1][q+1]==1){
                    count++;
                }
             }
        }
        if(p<board.length-1){
            if(board[p+1][q]==1){
                count++;
            }
            if(q>0){
                if(board[p+1][q-1]==1){
                    count++;
                }
            }
            if(q<board[0].length-1){
                if(board[p+1][q+1]==1){
                    count++;
                }
             }
        }
        if(q>0){
            if(board[p][q-1]==1){
                count++;
            }
        }
        if(q<board[0].length-1){
            if(board[p][q+1]==1){
                count++;
            }
        }
        if(board[p][q]==1){
            if(count<2){
                return 0;
            }else if(count<=3){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(count==3){
                return 1;
            }
        }
        return 0;
    }
}
```