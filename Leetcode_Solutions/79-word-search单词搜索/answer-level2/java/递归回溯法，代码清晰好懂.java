### 解题思路
1. `way[][]`数组，记录走过的路程;
2. 递归回溯函数：`searchNext(row,col,rights);`
- `row,col`:当前开始查找的位置
- `rights`：与`word`相匹配的字符正确数，也是当前需要匹配的`word`的字符的位置。
3. 递归函数开始，四个方向依次遍历，如果未走过且字符匹配，就去遍历一次。
### 代码

```java
class Solution {

    private String word;
    private char[][] board;
    private boolean[][] way;//way[i][j]==true means this way has been pass.
    private boolean searchNext(int row,int col,int rights)
    {
        if(rights==word.length())
            return true;
        
        way[row][col]=true;
        //up search
        if(row>0&&!way[row-1][col]&&board[row-1][col]==word.charAt(rights))
            if(searchNext(row-1,col,rights+1))return true;
        //down search
        if(row<board.length-1&&!way[row+1][col]&&board[row+1][col]==word.charAt(rights))
            if(searchNext(row+1,col,rights+1))return true;
        //left search
        if(col>0&&!way[row][col-1]&&board[row][col-1]==word.charAt(rights))
            if(searchNext(row,col-1,rights+1))return true;
        //right search
        if(col<board[0].length-1&&!way[row][col+1]&&board[row][col+1]==word.charAt(rights))
            if(searchNext(row,col+1,rights+1))return true;
        
        way[row][col]=false;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        if(board.length==0||board[0].length==0||word.length()==0)
            return false;
        
        this.word=word;
        this.board=board;
        int r=board.length,c=board[0].length;
        way=new boolean[r][c];
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(board[i][j]==word.charAt(0)&&searchNext(i,j,1))
                    return true;
        
        return false;
    }
}
```