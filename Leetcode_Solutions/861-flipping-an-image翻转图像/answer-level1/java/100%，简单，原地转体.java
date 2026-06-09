```
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int i = 0; i < A.length; ++ i) {
            int l = 0, r = A[0].length - 1;
            while(l < r) {
                int tmp = 0;
                tmp = A[i][l];
                A[i][l] = A[i][r];
                A[i][r] = tmp;
                A[i][l] ^= 1;
                A[i][r] ^= 1;
                l ++;
                r --;
            }
            if(l == r) {
                A[i][r] ^= 1;
            }
        }
        return A;
    }
}
```
