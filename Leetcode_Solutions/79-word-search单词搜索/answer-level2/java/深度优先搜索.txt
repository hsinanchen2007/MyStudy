### 解题思路
认真分析问题，会发现是一个深度优先搜索问题。
首要找到根节点，然后进行深度优先搜索。
退出条件为字符不匹配或者字符已经使用。

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        if(board == null || board.length == 0){
            return false;
        }
        int m = board.length, n = board[0].length;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word.charAt(0) == board[i][j]){
                    if(search(board,i,j,word,0,new boolean[m][n])){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean search(char[][] board, int i, int j, String word,int wIndex,boolean[][] flags){
        if(wIndex < word.length() && board[i][j] != word.charAt(wIndex)){
            return false;
        }
        if(flags[i][j]){
            return false;
        }
        if(wIndex + 1 == word.length()){
            return true;
        }
        //标记为使用
        flags[i][j] = true;
        if(i - 1 >= 0 && search(board,i - 1,j,word,wIndex+1,flags)){
            return true;
        }
        if(j - 1 >= 0 && search(board,i ,j - 1,word,wIndex+1,flags)){
            return true;
        }
        if(i + 1 < board.length && search(board,i + 1,j,word,wIndex+1,flags)){
            return true;
        }
        if(j + 1 < board[0].length && search(board,i,j + 1,word,wIndex+1,flags)){
            return true;
        }
        //释放使用标记
        flags[i][j] = false;
        return false;
    }
}
```