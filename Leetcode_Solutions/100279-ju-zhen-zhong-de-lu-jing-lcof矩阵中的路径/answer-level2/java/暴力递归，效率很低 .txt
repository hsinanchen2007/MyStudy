### 解题思路
暴力解法
先找到第一个字符，然后递归从四个方向查找剩下的字符
注意：因为每个节点不能重入，所以还要记录走过哪些节点

执行用时 :108 ms, 在所有 Java 提交中击败了5.08%的用户
### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        boolean res = false;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    List<int[]> locations = new ArrayList<>();
                    res = exist(locations, board, word, i, j);
                }
                if (res) {
                    return true;
                }
            }
        }
        return false;
    }
    
    public boolean exist(List<int[]> locations, char[][] board, String word, int x, int y) {
        if (x < 0 || x >= board.length || y < 0 || y >= board[x].length) {
            return false;
        }
        
        if (word.length() == 1) {
            if (!locationHas(locations, x, y) && board[x][y] == word.charAt(0)) {
                return true;
            }
            return false;
        }
        
        if (locationHas(locations, x, y) || board[x][y] != word.charAt(0)) {
            return false;
        }

        List<int[]> newLocations = new ArrayList<>();
        for (int i = 0; i < locations.size(); i++) {
            newLocations.add(locations.get(i));
        }
        newLocations.add(new int[] {x, y});
        return exist(newLocations, board, word.substring(1), x+1, y)
                || exist(newLocations, board, word.substring(1), x-1, y)
                || exist(newLocations, board, word.substring(1), x, y+1)
                || exist(newLocations, board, word.substring(1), x, y-1);
    }
    
    public boolean locationHas(List<int[]> locations, int x, int y) {
        for (int i = 0; i < locations.size(); i++) {
            if (locations.get(i)[0] == x && locations.get(i)[1] == y) {
                return true;
            }
        }
        return false;
    }
}
```