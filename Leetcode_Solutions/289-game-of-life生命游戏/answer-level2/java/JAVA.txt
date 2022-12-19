### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int row=board.length;
        int col=board[0].length;
        boolean[][] flag = new boolean[row][col];
        int[] dx={0,1,-1};
        int[] dy={0,1,-1};
        int[] count = {0,0};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                count[0]=0;count[1]=0;
                for(int x=0;x<dx.length;x++){
                    for(int y=0;y<dy.length;y++){
                        if(dx[x]==0&&dy[y]==0) continue;
                        else{
                            if(i+dx[x]<row&&j+dy[y]<col&&i+dx[x]>=0&&j+dy[y]>=0){
                                count[board[i+dx[x]][j+dy[y]]]++;
                            }
                        }
                    }
                }
                if(board[i][j]==1){
                    if(count[1]<2||count[1]>3) flag[i][j]=true;
                }else{
                    if(count[1]==3) flag[i][j]=true;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(flag[i][j]==true) board[i][j]^=1;
            }
        }
    }
}
```