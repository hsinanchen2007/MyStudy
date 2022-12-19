### 解题思路
此处撰写解题思路
执行用时 :
9 ms
, 在所有 Java 提交中击败了
35.91%
的用户
内存消耗 :
41.3 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    private int len1, len2;
    public boolean exist(char[][] board, String word) {
        char[] words = word.toCharArray();
        len1 = board.length;
        len2 = board[0].length;
        for (int i = 0; i < len1; i++){
            for (int j = 0; j < len2; j++){
                if (dfs(board, i, j, words, 0)) return true;
            }
        }
        return false;
    }
    private boolean dfs(char[][] board, int i, int j, char[] words, int cnt){
        if (i < 0 || j < 0 || i >= len1 || j >= len2 || words[cnt] != board[i][j]) return false;
        if (cnt == words.length - 1) return true;
        char tmp = board[i][j];
        board[i][j] = '0';
        boolean res = dfs(board, i + 1, j, words, cnt + 1) || dfs(board, i - 1, j, words, cnt + 1) || dfs(board, i, j + 1, words, cnt + 1) || dfs(board, i, j - 1, words, cnt + 1);
        board[i][j] = tmp;//一个起点失败后复原沉岛
        return res;
    }
}
```