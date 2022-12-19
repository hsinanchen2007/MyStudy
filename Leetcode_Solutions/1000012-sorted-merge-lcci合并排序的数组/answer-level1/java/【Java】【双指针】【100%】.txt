为了减少移动次数，从序列尾部开始遍历，最后再把剩下的b里的数据放到a前面即可。

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        while (m > 0 && n > 0) {
            if (A[m - 1] > B[n - 1]) {
                A[m + n - 1] =  A[m - 1];
                m--;
            } else {
                A[m + n - 1] =  B[n - 1];
                n--;
            }
            
        }
        while (n > 0) {
            A[n - 1] = B[n - 1];
            n--;
        }
    }
}
```
