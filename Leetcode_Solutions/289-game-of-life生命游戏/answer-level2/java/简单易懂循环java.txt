![image.png](https://pic.leetcode-cn.com/ede149b6d260ece2dd7673cb72894b3907cb5b468e1abdf3abda44f1d8d07efe-image.png)
```
class Solution {
     public void gameOfLife(int[][] board) {
        //0死，1活，2由死到活，3由活到死。
        //即偶数表示死，奇数表示活；
        int row=board.length;
        if(row==0) return;
        int col=board[0].length;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int cnt=0;//记录活细胞的个数
                if(i-1>=0){
                    if(j-1>=0 && board[i-1][j-1]%2!=0) cnt++;
                    if(board[i-1][j] %2 !=0) cnt++;
                    if(j+1<col && board[i-1][j+1] %2!=0) cnt++;
                }
                if(i+1<row){
                    if(j-1>=0 && board[i+1][j-1] %2 !=0) cnt++;
                    if(board[i+1][j]%2 != 0) cnt++;
                    if(j+1<col && board[i+1][j+1]%2!=0) cnt++;
                }
                if(j-1>=0 && board[i][j-1]%2!=0) cnt++;
                if(j+1<col && board[i][j+1]%2!=0) cnt++;
                if(cnt<2 || cnt>3){
                    if(board[i][j]==1) board[i][j]=3;
                }
                else if(cnt==3){
                    if(board[i][j]==0) board[i][j]=2;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==2) board[i][j]=1;
                else if(board[i][j]==3) board[i][j]=0;
            }
        }
     }
}
```
