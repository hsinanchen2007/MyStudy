### 解题思路
模仿大佬的代码，第一次写40多行那么长的代码，加油

### 代码

```java
class Solution {

    public boolean exist(char[][] board, String word) {
        int x=board.length;
        int y=board[0].length;
        if(board.length==0||board==null||board[0].length==0||board[0]==null||word==null||word.length()==0){
            return false;
        }
        int[][] flag=new int[x][y];
        char[] chs=word.toCharArray();
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                flag[i][j]=0;
            }
        }
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(board[i][j]==chs[0]){
                    if(bfs(board,i,j,flag,chs,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public boolean bfs(char[][] board,int i,int j,int[][] flag,char[] chs,int index){
        if(index==chs.length){
            return true;
        }
        if(i<0||j<0||i==board.length||j==board[0].length||flag[i][j]==1||board[i][j]!=chs[index]){
            return false;
        }
        flag[i][j]=1;
        boolean ans=false;
        ans=bfs(board,i+1,j,flag,chs,index+1)||
        bfs(board,i-1,j,flag,chs,index+1)||
        bfs(board,i,j+1,flag,chs,index+1)||
        bfs(board,i,j-1,flag,chs,index+1);
        flag[i][j]=0;
        return ans;
    }
}
```