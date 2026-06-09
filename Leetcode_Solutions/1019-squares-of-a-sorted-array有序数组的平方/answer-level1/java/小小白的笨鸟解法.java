```
class Solution {
    public int[] sortedSquares(int[] A) {
        int[] res = new int[A.length];
        int index = A.length-1;
        for(int l=0,r=A.length-1; l<=r; ) {
            if( A[l]*A[l]>=A[r]*A[r] ) {
                res[index--] = A[l]*A[l++];
            } else {
                res[index--] = A[r]*A[r--];
            }
        }
        return res;
    }
}
```
