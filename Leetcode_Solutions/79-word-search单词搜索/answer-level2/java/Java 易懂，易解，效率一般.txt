**1.单词搜索是回溯算法的经典例题,和迷宫、八皇后算法思想一样,想要真正的理解此题，必须debug走一圈;
2.首先 char 数组中的每一个字母都可能是 word 的起始字符,所以从 char 数组第一个开始进行 深度优先搜索;
3. dfs 方法中,首先终止条件的判断：当 start 对应的是 word 的最后一个字符,此时只要判断当前 board[i][j] 是否等于word的最后一个字符即可(`board[i][j] == word`),接着非终止条件的判断，首先判断当 `board[i][j] == word.charAt(start)` 为 true 时,先设置 mark[i][j] 为 true ,意思是假设当前能走,接着根据上右下左的顺序进行 dfs,条件是：i,j 要合法 && 即将要走的下一个点是未走过的点（即下一个点 mark 要为 false ）,如果上右下左都无法 dfs,那就标记 mark 为 false, 表示当前点走不通，需要回到上一个点;
4.完结。**


        int row;
        int col;
        char[][] board;
        String word;
        boolean[][] marked;

        public boolean exist(char[][] board, String word) {
            row = board.length;
            col = board[0].length;
            if (row == 0)
                return false;

            marked = new boolean[row][col];
            this.board = board;
            this.word = word;

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (dfs(i, j, 0))
                        return true;
                }
            }
            return false;
        }

        public boolean dfs(int i, int j, int start) {
            if (start == word.length() - 1)
                return board[i][j] == word.charAt(start);

            if (board[i][j] == word.charAt(start)) {
                marked[i][j] = true;
                if (isVaild(i - 1, j) && !marked[i - 1][j] && dfs(i - 1, j, start + 1)) {
                    return true;
                } else if (isVaild(i, j + 1) && !marked[i][j + 1] && dfs(i, j + 1, start + 1)) {
                    return true;
                } else if (isVaild(i + 1, j) && !marked[i + 1][j] && dfs(i + 1, j, start + 1)) {
                    return true;
                } else if (isVaild(i, j - 1) && !marked[i][j - 1] && dfs(i, j - 1, start + 1)) {
                    return true;
                } else{
                    marked[i][j] = false;
                }
            }
            return false;
        }

        public boolean isVaild(int i, int j) {
            return i >= 0 && i < row && j >= 0 && j < col;
        }