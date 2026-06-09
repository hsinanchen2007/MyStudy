### 解题思路
不复制原二维数组，主要通过标记来保证原地算法，一共有4种变化：活变死=-1，活变活=1，死变死=0，死变活=2，这样通过绝对值=1来确定之前是否是活细胞来计数，最后再将小于1的全部置为0，大于0的置为1即可。

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int rows=board.length;
        int cols = board[0].length;
        int[] neighbors = {0,1,-1};
        for(int row=0;row<rows;row++){
            for (int col=0;col<cols;col++){
                int count=0;
                for(int i=0;i<3;i++){//活细胞计数
                    for (int j=0;j<3;j++){
                        if(!(neighbors[i]==0&&neighbors[j]==0)){
                            int r=row+neighbors[i];
                            int c=col+neighbors[j];
                            if((r<rows&&r>=0)&&(c<cols&&c>=0)&&Math.abs(board[r][c])==1){
                                count=count+1;
                            }
                        }
                    }
                }
                if((board[row][col]==1)&&(count<2||count>3)){
                    board[row][col]=-1;
                }
                if((board[row][col]==0)&&count==3){
                    board[row][col]=2;
                }

            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]<1)board[i][j]=0;
                else{
                    board[i][j]=1;
                }
            }
        }
    }
}
```