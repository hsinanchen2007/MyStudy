```
class Solution {
    public int numRookCaptures(char[][] board) {
        int res = 0;
        for(int i = 0; i < 8;i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == 'R') {
                    int p = i,q=j;
                    while(p < 8) {
                        if(board[p][q] == 'B') {
                            break;
                        }else if(board[p][q] == 'p') {
                            res++;
                            break;
                        }
                        p++;
                    }
                    p = i;
                    while(p >= 0) {
                        if(board[p][q] == 'B') {
                            break;
                        }else if(board[p][q] == 'p') {
                            res++;
                            break;
                        }
                        p--;
                    }
                    p = i;
                    while(q < 8) {
                        if(board[p][q] == 'B') {
                            break;
                        }else if(board[p][q] == 'p') {
                            res++;
                            break;
                        }
                        q++;
                    }
                    q = j;
                    while(q >= 0) {
                        if(board[p][q] == 'B') {
                            break;
                        }else if(board[p][q] == 'p') {
                            res++;
                            break;
                        }
                        q--;
                    }
                    break;
                }
            }
        }
        return res;
    }
}
```
