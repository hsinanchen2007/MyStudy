### 解题思路
把数组A , B合并，然后对整个数组进行排序

### 代码

```java
import java.util.Arrays;
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        for (int i = 0 , j = m; j < A.length; j++ , i++) {
            A[j] = B[i];
        }
        Arrays.sort(A);
    }
}
```