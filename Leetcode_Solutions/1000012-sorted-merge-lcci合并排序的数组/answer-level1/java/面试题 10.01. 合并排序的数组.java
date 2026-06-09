### 解题思路
A数组尾部插入式。
如果最后还剩下A中的数，因为都是排序数组就不用管，如果还剩下B中的数，则需要将B中的数移动A中。
### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        while (m > 0 && n > 0) {
            A[m + n - 1] = A[m - 1] > B[n - 1] ? A[m-- - 1] : B[n-- - 1];
        }
        while (n > 0) {//B中如果还存在数，就移到A中。
            A[n - 1] = B[n - 1];
            n--;
        }
    }
}
```