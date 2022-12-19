### 解题思路

排序后，遍历数组A，如果遇到A[i] < 0，且此时K大于，那么就将A[i]反转为正数，K减1。

如果A[i] > 0,那么就先暂时不用反转。

同时在遍历的过程中维护一个最小值。

### 代码

```java
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        Arrays.sort(A);
        int sum = 0, min = Integer.MAX_VALUE;
        for (int i = 0; i < A.length; i++) {
            if (A[i] < 0 && K-- > 0) 
                A[i] = -1 * A[i];
            sum += A[i];
            min = Math.min(min, A[i]);
        }
        if (K > 0 && K % 2 == 1)
            sum = sum - min + (-1 * min);
        return sum;
    }
}
```