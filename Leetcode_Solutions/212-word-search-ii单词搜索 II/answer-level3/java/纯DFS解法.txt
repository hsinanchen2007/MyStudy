class Solution {
    private static int[] dx = {-1, 1, 0, 0};
    private static int[] dy = {0, 0, -1, 1};
    public List<String> findWords(char[][] board, String[] words) {
        List<String> result = new ArrayList<>();
        if (words == null || words.length == 0 || board == null || board.length == 0) {
            return result;
        }
        for (String word : words) {
            char[] wordArr = word.toCharArray();
            int index = 0;
            boolean contain = false;
            for (int i = 0; i < board.length; i++) {
                if (contain) {
                    break;
                }
                for (int j = 0; j < board[i].length; j++) {
                    if (board[i][j] != wordArr[index]) {
                        continue;
                    }
                    boolean[][] visted = new boolean[board.length][board[i].length];
                    visted[i][j] = true;
                    contain = dfs_helper(board, i, j, wordArr, index + 1, visted);
                    if (contain) {
                        break;
                    }
                }
            }
            if (contain) {
                result.add(word);
            }
        }

        return result;
    }

    private boolean dfs_helper(char[][] board, int i, int j, char[] wordArr, int index, boolean[][] visted) {
        if (index >= wordArr.length) {
            return true;
        }
        boolean contain = false;
        for (int k = 0; k < dx.length; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < board.length && y >= 0 && y < board[x].length && board[x][y] == wordArr[index] && !visted[x][y]) {
                visted[x][y] = true;
                contain = dfs_helper(board, x, y, wordArr, index + 1, visted);
                if (contain) {
                    break;
                }else{
                    visted[x][y] = false;
                }
            }
        }
        return contain;
    }


}