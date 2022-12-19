### 解题思路
首先不用把它想的有多难，主要就两步：
1.遍历二维数组，看里面是要查找的字符串的第一个字符是否存在，不存在就不用找了，存在的会就记住第一个字符的位置；
2.根据第一个字符的位置，在该位置的上下左右继续查找下一个字符，这里采用递归；
  2.1 这一步主要注意下递归结束条件，以及已经查到的字符不要再回去找了
### 代码

```java
class Solution {
    private int row;
    private int col;
    public boolean exist(char[][] board, String word) {
       if(board==null||board.length==0||(board.length==1&&board[0].length==0)||word==null){
           return false;
       } 
        row =board.length;
        col =board[0].length;

     for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
             if(board[i][j]==word.charAt(0)&&dfs(board,word,i,j,0)){
                return true;
             }
         }
     }
     return false;
    }

public boolean dfs(char[][] board,String charw,int i,int j,int index){
  
if(i<0||i>=row||j<0||j>=col||board[i][j]!=charw.charAt(index)){
    return false;
}
if(index==charw.length()-1){
    return true;
}
index++;

char temp = board[i][j];
board[i][j]='$';

boolean ret=dfs(board,charw,i-1,j,index)||
dfs(board,charw,i+1,j,index)||
dfs(board,charw,i,j-1,index)||
dfs(board,charw,i,j+1,index);

board[i][j]=temp;
return ret;
}







}
```