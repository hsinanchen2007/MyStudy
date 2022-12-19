### 解题思路
因为面板上所有格子需要同时被更新,所以要知道细胞的原有状态,不能使用更新之后的状态,所以创建一个临时数组,用于保存更新之后的状态,原数组继续使用原有状态
### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int row=board.length;
        int column=board[0].length;
        //临时数组
        int[][]temp=new int[row][column];
        for(int x=0;x<board.length;x++){
            for(int y=0;y<board[x].length;y++){
                //记录八个方向中生存与死亡的细胞个数liveCount是生存deadCount是死亡
                int liveCount=0,deadCount=0;
                //上
                if(x-1>=0){
                    if(board[x-1][y]==0){
                        deadCount++;
                    }else{
                        liveCount++;
                    }
                }
                //下
                if(x+1<row){
                    if(board[x+1][y]==0){
                        deadCount++;
                    }else{
                        liveCount++;
                    }
                }
                //左
                if(y-1>=0){
                    if(board[x][y-1]==0){
                        deadCount++;
                    }else{
                        liveCount++;
                    }
                }
                //右
                if(y+1<column){
                    if(board[x][y+1]==0){
                        deadCount++;
                    }else{
                        liveCount++;
                    }
                }
                //左上
                if(x-1>=0&&y-1>=0){
                    if(board[x-1][y-1]==0){
                        deadCount++;
                    }else{
                        liveCount++;
                    }
                }
                //右下
                if(x+1<row&&y+1<column){
                    if(board[x+1][y+1]==0){
                        deadCount++;
                    }else{
                        liveCount++;
                    }
                }
                //右上
                if(x-1>=0&&y+1<column){
                    if(board[x-1][y+1]==0){
                        deadCount++;
                    }else{
                        liveCount++;
                    }
                }
                //左下
                if(x+1<row&&y-1>=0){
                    if(board[x+1][y-1]==0){
                        deadCount++;
                    }else{
                        liveCount++;
                    }
                }
                //统计完八个方向的生存与死亡的细胞数之后按题目生存定律处理
                if(board[x][y]==0){
                    if(liveCount==3){
                        temp[x][y]=1;
                    }else{
                        temp[x][y]=0;
                    }
                }else{
                   if(liveCount==2 ||liveCount==3){
                        temp[x][y]=1;
                   }else {
                        temp[x][y]=0;
                   }
                }
            }
        }
        //赋值给原数组
        for(int x=0;x<board.length;x++){
            for(int y=0;y<board[x].length;y++){
                board[x][y]=temp[x][y];
            }
        }
    }
}
```