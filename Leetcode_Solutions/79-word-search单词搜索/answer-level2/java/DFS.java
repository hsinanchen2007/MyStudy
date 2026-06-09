### 解题思路
1. 设置二维数组表示四个方向
2. 设置访问状态visited，避免探测的时候往回探测

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        if (board.length == 0)
            return false;
        int[][] vector = new int[][]{{-1,0}, {1,0}, {0,1}, {0,-1}};
        int[][] visited = new int[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                boolean res = findWord(i, j, board, word, 0, vector, visited);
                if (res)
                    return true;
            }
        }
        return false;
    }

    private boolean findWord(int i, int j, char[][] board,String word,int index, int[][] vector, int[][] visited){
        //当前单词匹配
        if (board[i][j] == word.charAt(index)){
            visited[i][j] = 1;
            if (index == word.length() - 1)
                return true;
            for (int[] ints : vector) {
                int a = i +ints[0];
                int b = j +ints[1];
                if (a >= 0 && a < board.length && b >=0 && b < board[0].length){
                    if (visited[a][b] == 0){
                        visited[a][b] = 1;
                        boolean res = findWord(a, b, board, word, index + 1, vector, visited);
                        visited[a][b] = 0;
                        if (res)
                            return true;
                    }
                }
            }
        }
        visited[i][j] = 0;
        return false;
    }
}
```