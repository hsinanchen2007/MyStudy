### 解题思路
对每个数组中的元素都可以作为单词的起点，首字母不相等可以直接跳过，而行进方向为上下左右，用 directions 数组表示，
在回溯过程中，判断下一个字符是否相等，来进行减枝。

另外是会出现环的情况，需要使用 used 数组来记录已经走过的点
```
[["a"], ["a"]]
"aaa"
```

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length == 0 || word == null || word.length() < 0) {
            return false;
        } 
        
        boolean[][] used = new boolean[board.length][board[0].length];
        ArrayList<Character> route = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] != word.charAt(0)) continue;
                route.add(board[i][j]);
                used[i][j] = true;
                if (backtrace(board, route, word, i, j, used)) return true;
                route.clear();
                used[i][j] = false;
            }
        }

        return false; 
    }

    public boolean backtrace(char[][] board, List<Character> route, String word, int row, int col, boolean[][] used) {
        if (route.size() == word.length()) return true;
        int[][] directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        for (int k = 0; k < directions.length; k++) {
            int i = row + directions[k][0];
            int j = col + directions[k][1];
            if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || used[i][j]) continue;
            if (board[i][j] != word.charAt(route.size())) continue;
            route.add(board[i][j]);
            used[i][j] = true;
            if (backtrace(board, route, word, i, j, used)) return true;
            route.remove(route.size() - 1);
            used[i][j] = false;
        }

        return false;
    }
}
```