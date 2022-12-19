### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
private char[][] board;
    private String word;
    private int rowLen;
    private int colLen;
    private boolean[][] dp;

    private static final int[] xDic = new int[]{-1, 0, 1, 0};
    private static final int[] yDic = new int[]{0, -1, 0, 1};

    public boolean exist(char[][] board, String word) {
        boolean isWordNone = null == word || 0 == word.length();
        boolean isBoardNone = null == board || 0 == board.length;
        if (isBoardNone)
            return isWordNone;
        if (isWordNone)
            return true;

        this.board = board;
        this.word = word;
        rowLen = board.length;
        colLen = board[0].length;
        dp = new boolean[rowLen][colLen];

        for (int i=0; i<rowLen; ++i) {
            for (int j=0; j<colLen; ++j) {
                if (beginStep(i, j, 0))
                    return true;
            }
        }
        return false;
    }

    private boolean beginStep(int x, int y, int charIndex) {
        if (charIndex == word.length())
            return true;

        if (x < 0 || y < 0 || x >= rowLen || y >= colLen || dp[x][y] || board[x][y] != word.charAt(charIndex))
            return false;

        dp[x][y] = true;
        for (int i=0; i<4; ++i) {
            if (beginStep(x + xDic[i], y + yDic[i], charIndex+1))
                return true;
        }
        dp[x][y] = false;
        return false;
    }
}
```