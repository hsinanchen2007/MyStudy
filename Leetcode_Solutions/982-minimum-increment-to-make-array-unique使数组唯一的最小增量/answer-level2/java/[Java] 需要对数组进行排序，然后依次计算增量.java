### 解题思路
想象成上台阶

每次move操作都是加1，所以如果要计算出最小增量，就要从数组中的最小数开始计算，这样可以保证不会出现浪费增量的情况。
比如[3,3,1]，如果不排序直接计算增量，就是5。=》[3,4,5]，它浪费了3以下的所有位置。
如果先排序，[3,3,1] => [1,3,3]，增量为1。=》[1,3,4]。
因此，最小增量为1。

用limit表示当前位置应该达到的高度
    1. 当前位置小于limit：没什么好说的，直接让它达到limit，中间的差值就是该位置的增量。
    2. 当前位置大于limit：不需要增量，因为是数组本身抬高了高度，将limit设置成高度+1即可
    3. 当前位置等于limit：limit高度已经被上一个位置占据了，所以当前位置只能被迫+1

时间复杂度 O(n*lgn)，主要是排序的消耗
空间复杂度 constant

大约击败了80%

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if (A.length < 2) {
            return 0;
        }
        Arrays.sort(A);
        int limit = A[0] + 1;
        int cnt = 0;
        for (int i = 1; i < A.length; i++) {
            if (A[i] < limit) {
                cnt += limit - A[i];
                limit++;
            } else if (A[i] > limit) {
                limit = A[i] + 1;
            } else {
                limit++;
            }
        }
        return cnt;
    }
}
```