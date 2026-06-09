```
class Solution {
    int sc = 0;
    public int totalNQueens(int n) {
        // diagonal line can only contains one queen
        // recursive
        int[][] b = new int[n][n];
        help(0, b);
        return sc; 
    }

    private void help(int r, int[][] b) {
        if(r == b.length) {
            sc ++;
            return;
        }
            
        for(int i = 0; i < b.length; ++ i) {
            if(check(r, i, b)) {
                b[r][i] = 1;
                help(r + 1, b);
                b[r][i] = 0;
            }
        }
    }

    private boolean check(int r, int c, int[][] b) {
        for(int i = r; i > 0; -- i)
            if(b[r - i][c] == 1)
                return false;
        for(int i = Math.min(r, c); i > 0; -- i) {
            if(b[r - i][c - i] == 1)
                return false;
        }
        for(int i = Math.min(b.length - c - 1, r); i > 0; -- i) {
            if(b[r - i][c + i] == 1)
                return false;
        }
        return true;
    }
}
```
