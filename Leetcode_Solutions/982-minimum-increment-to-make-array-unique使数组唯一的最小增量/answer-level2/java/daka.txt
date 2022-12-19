### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
    Arrays.sort(A); // 先排序
    int curmax = -1; // 当前数组最大值
    int res = 0;
    for (int i = 0; i < A.length; i++) {
        if (A[i] <= curmax) {
            int ai = curmax + 1; // 当前元素 A[i] 需要增加到 curmax + 1
            res += (ai - A[i]); // 记录自增次数
            A[i] = ai; // 增加当前元素
        }
        curmax = Math.max(curmax, A[i]);
    }
    return res;
    }
}
```