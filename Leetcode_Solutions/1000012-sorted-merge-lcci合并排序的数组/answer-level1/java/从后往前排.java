```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        // 从后往前填充数组A
        if (A == null || B == null) return;
        while (m > 0 && n > 0) {
            if (A[m - 1] >= B[n - 1]) {
                A[m + n - 1] = A[m - 1];
                m --;
            } else {
                A[m + n - 1] = B[n - 1];
                n --;
            }
        }
        // n 为空的情况不用考虑，因为直接就在A中排序好了
        while (m == 0 && n > 0) {
            A[m + n - 1] = B[n - 1];
            n --;
        }
    }
}
```