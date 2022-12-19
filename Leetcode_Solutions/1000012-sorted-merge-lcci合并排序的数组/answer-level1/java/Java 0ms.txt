

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int[] Acopy = new int[m];
        System.arraycopy(A, 0, Acopy, 0, m);
        int i = 0, j = 0;
        int pos = 0;
        while (i < m && j < n)
            A[pos ++] = Acopy[i] < B[j] ? Acopy[i ++] : B[j ++];
        while (i < m)
            A[pos ++] = Acopy[i ++];
        while (j < n)
            A[pos ++] = B[j ++];
    }
}
```