### 解题思路
因为本身是初学者，可能初学者的思维是相近的。
1.将B 加入到A中
2.排序的时候注意不要对整个A排序，要排0-m+n区域内的。这个注意到了基本不会有问题。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        for (int i = m; i < m + n; i++) {
            A[i] = B[i - m];
        }
        Arrays.sort(A, 0, m + n);
    }
}
```