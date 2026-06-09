耗时有点长了，欢迎讨论优化方法~

执行用时 : 912 ms, 在所有 Java 提交中击败了5.18%的用户

内存消耗 :40.4 MB, 在所有 Java 提交中击败了98.65%的用户
```
class Solution {
    List<String> res=new ArrayList<>();
    int[][] directions={{0,1},{0,-1},{-1,0},{1,0}};
    public List<String> findWords(char[][] board, String[] words) {
        if(board==null||board.length==0||board[0].length==0||words==null||words.length==0){
            return res;
        }
        int r=board.length;
        int c=board[0].length;
        boolean[][] visit=new boolean[r][c];
        for(int i=0;i<words.length;++i){
            if(r*c<words[i].length()){
                continue;
            }
            for(int row=0;row<r;++row){
                if(res.contains(words[i])){
                    break;
                }
                
                for(int col=0;col<c;++col){
                    if(board[row][col]==words[i].charAt(0)){            
                        if(backTracing(words[i],board,row,col,visit,1)){
                            break;
                        }
                    }
                }
            }      
        }
        return res;
    }
    public boolean backTracing(String s, char[][] board,int r, int c,boolean[][] visit,int index){
        if(index==s.length()){
            if(!res.contains(s)){
                res.add(s);
            }
            return true;
        }
        visit[r][c]=true;
        for(int[] direct:directions){
            int x=r+direct[0];
            int y=c+direct[1];
            if(x<0||x>=board.length||y<0||y>=board[0].length||visit[x][y]){
                continue;
            }
            if(board[x][y]==s.charAt(index)){
                visit[x][y]=true;
                if(backTracing(s,board,x,y,visit,index+1)){
                    visit[x][y]=false;
                    break;
                }
                visit[x][y]=false;
            }
        }
        visit[r][c]=false;
        return false;
    }
}
```