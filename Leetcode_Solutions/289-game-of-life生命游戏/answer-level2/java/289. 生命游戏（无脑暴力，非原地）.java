### 解题思路
借助二维数组，空间复杂度O（mn）

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int rows=board.length;
        int cols = board[0].length;
        int[][] res=new int[rows][cols];
        int[] neighbors = {0,1,-1};
        
        for(int row=0;row<rows;row++){//复制二维数组
            for(int col=0;col<cols;col++){
                res[row][col]=board[row][col];
            }
        }

        for(int row=0;row<rows;row++){
            for (int col=0;col<cols;col++){
                int count=0;

                for(int i=0;i<3;i++){//活细胞计数
                    for (int j=0;j<3;j++){

                        if(!(neighbors[i]==0&&neighbors[j]==0)){
                            int r=row+neighbors[i];
                            int c=col+neighbors[j];
                            if((r<rows&&r>=0)&&(c<cols&&c>=0)&&res[r][c]==1){
                                count=count+1;
                            }
                        }
                    }
                }

                if((res[row][col]==1)&&(count<2||count>3)){
                    board[row][col]=0;
                }

                if((res[row][col]==0)&&count==3){
                    board[row][col]=1;
                }

            }
        }
    }
}
```