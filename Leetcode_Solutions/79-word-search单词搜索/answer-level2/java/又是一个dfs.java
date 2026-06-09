### 解题思路
此处撰写解题思路
感觉dfs快把我搞疯了.
用一个visit[][]来记录是否访问过。如果得到的字符串的长度等于给定字符的长度，就return true。
每一次走一个方向后进行一次dfs；
### 代码

```java
class Solution {
    private int m,n;
    private int[][]move={{0,1},{0,-1},{-1,0},{1,0}};
    private boolean[][]visit;
    public boolean exist(char[][] board, String word) {
        if(word==null||word.length()==0) return true;
        if(board==null||board.length==0||board[0].length==0) return false;
        m=board.length;
        n=board[0].length;
        visit=new boolean[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
    private boolean dfs(char[][] b,String w,int s,int i,int j){
        if(s==w.length()) return true;
        if(i<0||i>=m||j<0||j>=n||visit[i][j]||b[i][j]!=w.charAt(s)) return false;
        visit[i][j]=true;
        for(int k=0;k<4;k++){
            int ni=i+move[k][0];
            int nj=j+move[k][1];
            if(dfs(b,w,s+1,ni,nj)) return true;
        }
        visit[i][j]=false;
        return false;
    }
}
```