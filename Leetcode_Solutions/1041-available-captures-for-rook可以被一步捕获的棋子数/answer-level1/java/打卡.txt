    // 简单的搜索
    class Solution {
        public int numRookCaptures(char[][] board) {
            if(board.length == 0) {
                return 0;
            }
            int m = board.length;
            int n = board[0].length;
            int p = 0, q = 0;
            for(int i = 0;i < m;i++) {
                for(int j = 0;j < n;j++) {
                    if(board[i][j] == 'R') {
                        p = i;
                        q = j;
                        break;
                    }
                }
            }
            int res = 0;
            // up
            for(int i = p - 1;i >= 0;i--) {
                if(board[i][q] == '.') {
                    continue;
                }
                res += board[i][q] == 'p' ? 1 : 0;
                break;
            }
            // down
            for(int i = p + 1;i < m;i++) {
                if(board[i][q] == '.') {
                    continue;
                }
                res += board[i][q] == 'p' ? 1 : 0;
                break;
            }
            // left
            for(int i = q - 1;i >= 0;i--) {
                if(board[p][i] == '.') {
                    continue;
                }
                res += board[p][i] == 'p' ? 1 : 0;
                break;
            }
            // right
            for(int i = q + 1;i < n;i++) {
                if(board[p][i] == '.') {
                    continue;
                }
                res += board[p][i] == 'p' ? 1 : 0;
                break;
            }
            return res;
        }
    }