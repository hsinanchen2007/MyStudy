### 解题思路
对于n个数字，最小的移动次数也是按照自然数来排列。因此，先对数组进行排序，又由于move运动是单向的，所以不管数字处于什么位置，后面重复的数字，只能是递增，也就是说，我们可以猜出后面的数字应该如何排列，因此设置一个suppose变量，如果实际的数字小于suppose，就需要移动的suppose - A[i]步。

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int move = 0;
        int suppose = 0;
        for (int i = 0; i < A.length; i++) {
            if (A[i] > suppose) {
                suppose = A[i];
            }
            move += suppose - A[i];
            suppose++;
        }
        return move;
    }
}

```