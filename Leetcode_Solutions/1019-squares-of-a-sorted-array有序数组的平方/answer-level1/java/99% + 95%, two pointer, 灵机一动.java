```
class Solution {
    public int[] sortedSquares(int[] A) {
        int[] rs = new int[A.length];
        int l = 0, r = A.length - 1, c = A.length - 1;
        while(l <= r && c >= 0) {
            if(A[l] > 0 && A[r] > 0 || A[l] == 0) {
                rs[c --] = A[r] * A[r];
                r --;
            }
            else if(A[l] < 0 && A[r] < 0 || A[r] == 0) {
                rs[c --] = A[l] * A[l];
                l ++;
            }
            else if(A[l] < 0 && A[r] > 0) {
                if(Math.abs(A[l]) > A[r]) {
                    rs[c --] = A[l] * A[l];
                    l ++;
                }
                else {
                    rs[c --] = A[r] * A[r];
                    r --;
                }
            }
            else {
                rs[c --] = 0;
            }
        }
        return rs;
    }
}
```
