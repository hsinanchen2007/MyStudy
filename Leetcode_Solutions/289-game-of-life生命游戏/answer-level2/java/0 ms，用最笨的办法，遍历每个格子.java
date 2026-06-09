### 解题思路
遍历每个格子，计算周围八个格子的累加数字，即可计算出下一轮存活

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int row = board.length;
        int col = board[0].length;
        int[][] result = new int[row][col];
        for(int i =0;i<row;i++){
            for(int j=0;j<col;j++){
                int curr = board[i][j];
                int l_count = 0;
                //上一行
                if(i-1>=0){
                    //左上角，1
                    if(j-1>=0){
                        l_count += board[i-1][j-1];
                    }
                    //上，2
                    l_count += board[i-1][j];
                    //右上角,3
                    if(j+1<col){
                        l_count += board[i-1][j+1];
                    }
                }
                //当前行
                {   //左，4
                    if(j-1>=0){
                        l_count += board[i][j-1];
                    }
                    //右，5
                    if(j+1<col){
                        l_count += board[i][j+1];
                    }
                }
                //下边行
                if(i+1<row){
                    //左下角，6
                    if(j-1>=0){
                        l_count += board[i+1][j-1];
                    }
                    //下，7
                    l_count += board[i+1][j];
                    //右上角,8
                    if(j+1<col){
                        l_count += board[i+1][j+1];
                    }
                }
                //开始计算
                if(l_count <2){
                    result[i][j]=0;
                }
                
                if(l_count ==2||l_count ==3){
                    result[i][j]=curr;
                }
                
                if(l_count ==3){
                    result[i][j]=1;
                }
                if(l_count >3){
                    result[i][j]=0;
                }
                
            }
        }
        //赋值
        for(int i =0;i<row;i++){
            for(int j=0;j<col;j++){
                board[i][j] = result[i][j];
            }
        }
        

    }
}
```