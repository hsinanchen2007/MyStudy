class Solution {
   public int numRookCaptures(char[][] board) {
        int ans = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if(board[i][j] == 'R') {
                    for (int k = j - 1; k >= 0; k--) {
                        if (board[i][k] == 'B') break;
                        if (board[i][k] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    
                    for (int k = j + 1; k < 8; k++) {
                        if (board[i][k] == 'B') break;
                        if (board[i][k] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    
                    for (int k = i - 1; k >= 0; k--) {
                        //if (board[k][j] == '.') continue;
                        if (board[k][j] == 'B') break;
                        if (board[k][j] == 'p') {
                            ans++;
                            break;
                        }
                    }

                    for (int k = i + 1; k < 8; k++) {
                        if (board[k][j] == 'B') break;
                        if (board[k][j] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    
                    break;
                }
            }
        }
        return ans;
    }

}