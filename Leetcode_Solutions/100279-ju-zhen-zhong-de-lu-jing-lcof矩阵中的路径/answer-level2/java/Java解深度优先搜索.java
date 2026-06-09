参数释义:
1. 二维布尔数组isGone:主要记录在一次深度优先搜索中可能会已经访问过该节点,如果为true则表示已经访问过
2. m,n:分别代表行数和列数
3. word:目标字符串
4. board:目标字符数组
5. i,j:当前的行索引和列索引
6. currentIndex:当前要匹配的字符在字符串中的索引


```
class Solution {
    boolean[][] isGone;
    int m,n;
    String word;
    char[][]board;
    public boolean exist(char[][] board, String word) {
        this.isGone = new boolean[board.length][board[0].length];
        this.m = board.length-1;
        this.n = board[0].length-1;
        this.word = word;
        this.board = board;
        for(int i = 0;i<board.length;i++){
            for(int j =0;j<board[0].length;j++){
                if(dfs(i,j,0)==true) return true;
            }
        }
        return false;
    }

    public boolean dfs(int i,int j,int currentIndex){
        if(i>m||i<0||j>n||j<0||isGone[i][j]||board[i][j]!=this.word.charAt(currentIndex)) return false;
        currentIndex++;
        isGone[i][j] = true;//过滤已经来过的
        if(currentIndex == word.length()){//说明已经完全匹配了字符串
            return true;
        }
        boolean res =dfs(i+1,j,currentIndex)||dfs(i-1,j,currentIndex)||dfs(i,j-1,currentIndex)||dfs(i,j+1,currentIndex);
        isGone[i][j] = false;//还原
        return res;
    }
}
```
