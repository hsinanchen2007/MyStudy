```
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        int[][] a = new int[mat.length][mat[0].length];
        for(int r = 0; r < mat.length; ++ r) {
            for(int c = 0; c < mat[0].length; ++ c) {
                for(int rr = Math.max(0, r - K); 
                rr <= Math.min(mat.length - 1, r + K); ++ rr) {
                    for(int cc = Math.max(c - K, 0); 
                    cc <= Math.min(mat[0].length - 1, c + K); ++ cc) {
                        a[r][c] += mat[rr][cc];
                    }
                }
            }
        }
        return a;
    }
}
```
