### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        // 一次遍历，找到所有的原点
        // 从每个原点开始出发，上下左右寻找word中的下一位。
        // 当word全部找完，则成功，否则不存在 n*n*m
        for( int i=0; i<board.length; i++ ){
            for( int j=0; j<board[i].length; j++ ){
                if ( board[i][j] == word.charAt(0) ){
                    //这是一个原点，进行dfs
                    if(word.length()==1) return true;
                    if( dfs(board,word,i,j,0) ) return true;
                }
            }
        }
        return false;
    }

    boolean dfs( char[][] board,String word,int i, int j,int w_index ){
         if( word.length()==w_index ) return true;
            if( word.charAt(w_index)!=board[i][j] ) return false;

            char tmp = board[i][j]; //保存下来，本次路径寻找后还原。如果路径中经过它，置为-1(就不会在这一次遍历被再次访问了)
            board[i][j] = 0;
            if( ( (i+1)<board.length && dfs( board,word,i+1,j,w_index+1 )) ||
                ( (i-1)>=0 ) && dfs( board,word,i-1,j,w_index+1 ) ||
                (( (j+1)<board[i].length) && dfs( board,word,i,j+1,w_index+1 ) ) ||
                ( (j-1)>=0 ) &&  dfs( board,word,i,j-1,w_index+1 ) ){
                board[i][j] = tmp;
                return true;
            }
            board[i][j] = tmp;
            return false;
    }

    
}
```