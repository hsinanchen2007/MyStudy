```
class Solution {
   boolean[][] marks;
    public boolean exist(char[][] board, String word) {
        char[] words = word.toCharArray();
   marks= new boolean[board.length][board[0].length];
         for (int x = 0; x < board.length; x++) {
            for (int y = 0; y < board[0].length; y++) {
                marks[x][y]=false;
            }
            }
        for (int x = 0; x < board.length; x++) {
            for (int y = 0; y < board[0].length; y++) {
                if (words[0] == board[x][y] && isRight(x, y, board, words, 1)) {
                    return true;
                }
            }
        }
        return false;
    }


    public boolean isRight(int x, int y, char[][] board, char[] words, int index) {
  
        if (index >= words.length) {
            return true;
        }
      char c = words[index];
        marks[x][y] = true;

        if (x - 1 >= 0&&!marks[x-1][y]) {
            if (c == (board[x - 1][y]) && getChars(x - 1, y, board, words, index + 1)) {
                return true;
            }
            
        }
        if (x + 1 < board.length&&!marks[x+1][y]) {
            if (c == (board[x + 1][y]) && getChars(x + 1, y, board, words, index + 1)) {
                return true;
            }
        }
        if (y - 1 >= 0&&!marks[x][y-1]) {
            if (c == (board[x][y - 1]) && getChars(x, y - 1, board, words, index + 1)) {
                return true;
            }
        }
        if (y + 1 < board[0].length&&!marks[x][y+1]) {
            if (c == (board[x][y + 1]) && getChars(x, y + 1, board, words, index + 1)) {
                return true;
            }
        }
                marks[x][y] = false;

        return false;
    }
}
```
