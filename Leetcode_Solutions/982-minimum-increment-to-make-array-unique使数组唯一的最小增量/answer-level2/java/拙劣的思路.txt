### 解题思路
排序，前后相同强行加一，加到大于前边为止
简单粗暴，就是结果感人
### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int result = 0;
        for (int i = 0; i < A.length; i++) {
            if (i >= 1 && A[i] <= A[i - 1]) {
                while (A[i] <= A[i - 1]) {
                    A[i] = A[i] + 1;
                    result++;
                }
            }
        }
        return result;
    }
}
```