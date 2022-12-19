### 解题思路
关键点是从后往前遍历。
如果从index为0开始处理，则需要频繁的移动A数组元素的位置！！！

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if (A == null) {
            A = B;
            return;
        }
        if (B == null) {
            return;
        }
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
}
```