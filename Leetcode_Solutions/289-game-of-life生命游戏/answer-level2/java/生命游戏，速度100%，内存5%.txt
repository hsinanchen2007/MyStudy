### 解题思路
搞清楚JAVA的深度复制和浅度复制就没有什么问题了

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
//因为是同时改变的，所以不能直接在原来的改，不然就会出现异常，创建新二维数组copyBoard[][]
        int[][] copyBoard = new int[board.length][board[0].length];   
//下列循环为深度复制而非引用复制
        for(int i = 0;i<copyBoard.length;i++){     
            for(int j = 0;j<copyBoard[0].length;j++){
                copyBoard[i][j] = board[i][j];
            }
        }         
        for(int i = 0;i<board.length;i++){
            for(int j = 0;j<board[0].length;j++){
                int count = check(i,j,board);
                if(board[i][j] == 1 &&(count<2 ||count>3)){  //如果细胞本来是活的，就是如果周围多于3个或者小于2就死掉
                    copyBoard[i][j] = 0;
                    continue;
                }
                if(board[i][j]==0 && count == 3){   //如果本来是死的，刚好有三个就复活
                     copyBoard[i][j] = 1;
                     continue;
                }
            }
        }
      for(int i = 0;i<copyBoard.length;i++){   //深度复制修改board数组，因为这个方法是void，所以这个board应该是类里面的一个成员对象
          for(int j = 0;j<copyBoard[0].length;j++){
              board[i][j] = copyBoard[i][j];
          }
      }
    // board =  copyBoard;  这种是错的，我也不知道为啥，有么有大神教我一下！！！！
    }

    public int check(int x,int y,int[][] array){
        int count = 0;
        if(y-1>=0){  
            count += array[x][y-1];
        }
        if(x-1>=0){
            count += array[x-1][y];
        }
        if(y+1 <=array[0].length-1){ //注意这里是y+1,所以还是同一行的，y+1应该不超过列数array[0].length
            count += array[x][y+1];
        }
        if(x+1 <= array.length-1){
            count += array[x+1][y];
        }
        if(x-1>=0&&y-1>=0){
            count += array[x-1][y-1];
        }
        if(x-1>=0&&y+1<array[0].length){
            count += array[x-1][y+1];
        }
        if(x+1<array.length && y-1>=0){
            count += array[x+1][y-1];
        }
        if(x+1<array.length&&y+1<array[0].length){
            count += array[x+1][y+1];
        }
         return count;
    }
}
```