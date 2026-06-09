### 解题思路
使用排序数组的方式将相同的数字修改为前一个数不同
A已经排序，只需要将遇到A[i]<=A[i-1]的情况将A[i]修改为比前一个数A[i-1]大一的即可，但是需要修改count为count+=A[i-1]-A[i]+1。

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if (A.length <= 1) {
            return 0;
        }
        Arrays.sort(A);
        int count = 0;
        for (int i = 1; i < A.length; i++) {
            if (A[i] <= A[i - 1]) {
                count +=  A[i - 1] - A[i] + 1;
                A[i] += A[i - 1] - A[i] + 1;
            }
        }
        return count;
        
    }
}
```