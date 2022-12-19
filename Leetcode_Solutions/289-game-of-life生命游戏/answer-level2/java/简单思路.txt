### 解题思路
先保存当前状态，每一次计算旧格子时，就从保存的矩阵中算出周围的存活数。
![image.png](https://pic.leetcode-cn.com/16c6c68d915052b5a6f2444d048f3ba69e4d66db4ff8352c3872d8e91ee991eb-image.png)

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int[][] oldState=new int[board.length][board[0].length];
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                oldState[i][j]=board[i][j];
            }
        }
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                int count=countAlive(oldState,i,j);
                if(board[i][j]==1&&count<2||count>3) board[i][j]=0;
                if(board[i][j]==0&&count==3) board[i][j]=1;
            }
        }
    }
    public int countAlive(int[][] state,int x,int y){
        int count=0;
        if(y-1>=0&&state[x][y-1]==1) count++;
        if(y+1<state[x].length&&state[x][y+1]==1) count++;
        if(x-1>=0){
            if(state[x-1][y]==1) count++;
            if(y-1>=0&&state[x-1][y-1]==1) count++;
            if(y+1<state[x-1].length&&state[x-1][y+1]==1) count++;
        }
        if(x+1<state.length){
            if(state[x+1][y]==1) count++;
            if(y-1>=0&&state[x+1][y-1]==1) count++;
            if(y+1<state[x+1].length&&state[x+1][y+1]==1) count++;
        }
        return count;
    }
}
```