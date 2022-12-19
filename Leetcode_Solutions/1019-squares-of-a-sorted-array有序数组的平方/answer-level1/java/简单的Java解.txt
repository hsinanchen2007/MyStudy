O(n) 的 Java 解：

``` java
class Solution {
    public int[] sortedSquares(int[] A) {
        int left = 0, right = A.length - 1;
        int curr = A.length - 1;
        int[] buf = new int[A.length];
        while(left <= right) {
            if (Math.abs(A[left]) <= Math.abs(A[right])) {
                buf[curr--] = A[right] * A[right];
                right--;
            } else {
                buf[curr--] = A[left] * A[left];
                left++;
            }
        }
        return buf;
    }
}
```