### 解题思路
本来想用栈实现,但是实在不知道栈如何回溯回去,求大神指点

### 代码

```java
class Solution {
    //用于标记是否找到结果
    private boolean flag;
    private int row;
    private int column;
    public boolean exist(char[][] board, String word) {
        if(board == null || board.length == 0 || board[0].length == 0 ) {
            return false;
        }
        row=board.length;
        column=board[0].length;
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                if(dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, int i, int j, String word, int cur) {
        if(cur==word.length()){
            flag=true;
            return true;
        }
        if(i<0||i>=row||j<0||j>=column||board[i][j]!=word.charAt(cur)||board[i][j]=='.'){
            return false;
        }
        char c=board[i][j];
        //如果已经发现满足的了直接返回结果
        if(!flag){
            //替换
            board[i][j]='.';
            boolean result=dfs(board,i+1,j,word,cur+1)||dfs(board,i-1,j,word,cur+1)
            ||dfs(board,i,j-1,word,cur+1)||dfs(board,i,j+1,word,cur+1);
            //回溯
            board[i][j]=c;
            return result;
        }else{
            return true;
        }
    }
}
```