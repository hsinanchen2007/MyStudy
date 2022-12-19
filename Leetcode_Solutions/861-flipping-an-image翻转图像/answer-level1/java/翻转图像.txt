```
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for (int[] B: A) {
            int len = B.length;
            for(int j = 0; j < (len+1)/2; j++) {
                int tmp = 1- B[j];
                B[j] = 1 - B[len-j-1];
                B[len-j-1] = tmp;
            }
        }
        return A;
    }
}
```
