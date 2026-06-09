```java
class Solution {
    public boolean isIdealPermutation(int[] A) {
        int n = A.length;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n - 2; i ++) {
            max = Math.max(max, A[i]);
            if (A[i + 2] < max) return false;
        }
        return true;
    }
}
```