### 解题思路
将数组从小到大排序，要使数组中没有重复的数字，那么后一个数至少要比前一个数大1。如果当前数字大于前一个数，则不进行操作，若小于等于前一个数，则把当前数的值置为前一个数加1，并累加移动的步数。代码还是比较简洁易懂的，不占用额外存储空间。

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int len = A.length, move = 0;
        for (int i = 1; i < len; i ++) {
            if (A[i] <= A[i - 1]) {
                move += A[i - 1] - A[i] + 1;
                A[i] = A[i - 1] + 1;
            }
        }
        return move;
    }
}
```