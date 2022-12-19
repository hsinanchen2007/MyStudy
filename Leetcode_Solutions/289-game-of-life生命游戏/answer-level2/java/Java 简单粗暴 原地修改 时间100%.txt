### 解题思路
### 代码                     

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int[][] countTotal = new int[board.length][board[0].length];
        int[][] towards = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                int count = 0;
                for(int k = 0; k < 8; k++){
                    int cur_i = i + towards[k][0];
                    int cur_j = j + towards[k][1];
                    if(cur_i>=0&&cur_i<board.length&&cur_j>=0&&cur_j<board[0].length&&board[cur_i][cur_j]==1){
                        count++;
                    }
                }
                countTotal[i][j] = count;

            }
        }
        
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j]==1&&(countTotal[i][j]<2||countTotal[i][j]>3))board[i][j]=0;
                if(board[i][j]==0&&countTotal[i][j]==3)board[i][j]=1;
            }
        }
                
    }
}
```

```
class Solution {
    public void gameOfLife(int[][] board) {
        int[][] towards = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                int count = 0;
                for(int k = 0; k < 8; k++){
                    int cur_i = i + towards[k][0];
                    int cur_j = j + towards[k][1];
                    //board[i][j]==-1时，是活的1变成死的0,即原来是1；
                    if(cur_i>=0&&cur_i<board.length&&cur_j>=0&&cur_j<board[0].length&&(board[cur_i][cur_j]==1||board[cur_i][cur_j]==-1)){
                        count++;
                    }
                }  
                //board[i][j]==-1时，是活的1变成死的0；board[i][j]==2时，是死的0变成活的1；
                if(board[i][j]==1&&(count<2||count>3))board[i][j]=-1;
                if(board[i][j]==0&&count==3)board[i][j]=2;                
            }
        }
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j]==2)board[i][j]=1;
                if(board[i][j]==-1)board[i][j]=0;
            }
        }
        
    }
}
```
