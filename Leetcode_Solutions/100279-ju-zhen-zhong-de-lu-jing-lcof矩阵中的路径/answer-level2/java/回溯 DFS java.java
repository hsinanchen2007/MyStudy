### 解题思路
DFS 标准的回溯算法

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        char[] w = word.toCharArray();
        boolean[][] visited = new boolean[board.length][board[0].length];
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(dfs(board,i,j,w,0,visited)){
                    return true;
                }
            }
        }
        return false;
    }

    boolean dfs(char[][] board,int i,int j,char[] word,int pos,boolean[][] visited){
        if(pos == word.length) return true;
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length || visited[i][j]) return false;
        if(board[i][j] != word[pos]) return false;
        visited[i][j] = true;
        boolean rs = dfs(board,i+1,j,word,pos+1,visited) ||
                    dfs(board,i-1,j,word,pos+1,visited) ||
                    dfs(board,i,j+1,word,pos+1,visited) ||
                    dfs(board,i,j-1,word,pos+1,visited);
        visited[i][j] = false;
        return rs;
    }
}
```