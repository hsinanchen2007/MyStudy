```
class Solution {
    public int[][] multiply(int[][] A, int[][] B) {
        //C[i][j] = sum(from  k is 0 - m)(A[i][k] * B[k][j])
        int kc = A[0].length;
        int rc = A.length;
        int cc = B[0].length;
        int[][] c = new int[rc][cc];
        for(int i = 0; i < rc; ++ i) {
            for(int j = 0; j < cc; ++ j) {
                for(int k = 0; k < kc; ++ k) {
                    c[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return c;
    }
}
```
