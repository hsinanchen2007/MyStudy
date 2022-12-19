```
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int[][] ret = new int[A.length][A.length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A.length/2f; j++) {
                ret[i][j] = 1 - A[i][A.length - 1 - j];
                ret[i][A.length - 1 - j] = 1 - A[i][j];
            }
        }
        return ret;
    }
}
```
