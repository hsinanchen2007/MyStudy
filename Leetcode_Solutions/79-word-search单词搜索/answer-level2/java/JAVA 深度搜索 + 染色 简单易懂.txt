### 解题思路
深度搜索 + 染色 
思路挺简单的，就是遍历 board 找到可以进行搜索的格子进行尝试搜索

搜索的时候记得吧当前走过的格子染色，我这里染成了 '0'，最后染回来，还原。

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        int col = board[0].length;
        int row = board.length;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                char cur = board[i][j];
                if(cur == word.charAt(0)){
                    //若找到了则返回
                   if(search(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }

    // i,j：当前 board 中的坐标， k：word 中搜索到哪里了
   boolean search(char[][] board, String word, int i, int j, int k){
        char cur = board[i][j];
        if(cur != word.charAt(k)) return false;
        if(k == word.length()-1) return true;
        //染色
        board[i][j] = '0';

        int col = board[0].length;
        int row = board.length;
        boolean left, right, top, down;
        left = i-1>=0 ? search(board, word, i-1, j, k+1) : false; if(left) return true;
        right = i+1<row ? search(board, word, i+1, j, k+1) : false; if(right) return true;
        top = j-1>=0 ? search(board, word, i, j-1, k+1) : false; if(top) return true;
        down = j+1<col ? search(board, word, i, j+1, k+1) : false; if(down) return true;

        //还原
        board[i][j] = cur;
        return left || right || top || down;
    }
}
```