# 解题

> 思路

1. 目标字符串 $S = "ABCCED"$
2. 从棋盘中找到S的第一个字符`A`, 即搜索`起点`.
3. 找到起点后 **递归** 深入下一层, 找起点之后的字符`B`,找到后继续递归深入. 深入递归时, 题目有一个要求, 棋盘上已经访问过的元素, 不可以再次访问. 因此需要把当前正在访问的元素进行标记.
4. 第`3,4`步任意一步搜索失败, 均直接返回false.

> 代码

```java
class Solution {
    
    int r, c;
    
    // 上, 右, 下, 左四个方向
    int[] r_dir = {-1, 0, 1, 0};
    int[] c_dir = { 0, 1, 0,-1};
    
    public boolean exist(char[][] board, String word) {
        
        if(board.length <= 0 || board[0].length <= 0) return false;
        
        r = board.length;
        c = board[0].length;
        
        // System.out.println("r=="+r+",c=="+c);
        
        for(int dr = 0; dr < r; dr++){
            for(int dc = 0; dc < c; dc++){
                if(search(board, dr, dc, word, 0)) return true;
            }
        }
        
        return false;
        
    }
    
    public boolean search(char[][] board, int dr, int dc, String word, int char_index){
        if(word.charAt(char_index) != board[dr][dc]) return false;
        if(char_index == word.length() - 1) return true;
        
        // 标记已经访问过的元素
        board[dr][dc] = '*';
        for(int i = 0; i < 4; i++){
            int nr = dr + r_dir[i];
            int nc = dc + c_dir[i];
            if(nr >= 0 && nr < r && nc >= 0 && nc < c){
                if(search(board, nr, nc, word, char_index+1)) return true;
            }
        } 
        board[dr][dc] = word.charAt(char_index);
        
        return false;
    }
}
```

> 复杂度

- 时间复杂度: O($N * M * 3^K$), 其中N, M为棋盘行与列, K为目标字符串长度, 3为递归深入的方向, 由于不能回头搜索, 所以深入方向只有3个. 
- 空间复杂度: O($N * M$), 目标串的起点没找到, 遍历了整个棋盘.