### 解题思路
双指针
### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        System.arraycopy(A, 0, A, n, m);

        int index = 0;
        int i, j;
        for (i = n, j = 0; i < m + n && j < n;) {
            if (A[i] <= B[j]) {
                A[index++] = A[i++];
            } else {
                A[index++] = B[j++];
            }
        }

        while (i < m + n) {
            A[index++] = A[i++];
        }

        while (j < n) {
            A[index++] = B[j++];
        }
    }
}
```