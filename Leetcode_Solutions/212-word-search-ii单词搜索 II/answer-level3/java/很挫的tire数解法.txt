### 解题思路
tire数解决问题的，就是时间也太挫了
### 代码

```java
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        int[][] visited=new int[board.length][board[0].length];
        List<String>res=new ArrayList<>();
        for(int i=0;i<words.length;i++){
            if(findOK(words[i],board,visited)){
                res.add(words[i]);
            }
        }
        return res;
    }
    private boolean findOK(String word, char[][] board, int[][] visited) {
        for(int i=0;i<board[0].length;i++){
            for(int j=0;j<board.length;j++){
                if(board[j][i]==word.charAt(0)){
                    if(CheckOk(word,board,visited,i,j,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean CheckOk(String word, char[][] board, int[][] visited, int i, int j, int lever) {
        boolean res=false;
        if(lever==word.length())
            return true;
        visited[j][i]=1;
        if(i-1>=0&&!(visited[j][i-1]==1)&&board[j][i-1]==word.charAt(lever)){
            res|=CheckOk(word,board,visited,i-1,j,lever+1);
        }
        if(i+1<board[0].length&&!(visited[j][i+1]==1)&&board[j][i+1]==word.charAt(lever)){
            res|=CheckOk(word,board,visited,i+1,j,lever+1);
        }
        if(j-1>=0&&!(visited[j-1][i]==1)&&board[j-1][i]==word.charAt(lever)){
            res|=CheckOk(word,board,visited,i,j-1,lever+1);
        }
        if(j+1<board.length&&!(visited[j+1][i]==1)&&board[j+1][i]==word.charAt(lever)){
            res|=CheckOk(word,board,visited,i,j+1,lever+1);
        }
        visited[j][i]=0;
        return res;
    }
}
```