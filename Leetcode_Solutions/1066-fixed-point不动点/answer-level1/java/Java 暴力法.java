```
class Solution {
    public int fixedPoint(int[] A) {
        for (int i = 0; i < A.length; i++) {
            if (i == A[i]) {
                return i;
            }
        }
        return -1;
    }
}
```
