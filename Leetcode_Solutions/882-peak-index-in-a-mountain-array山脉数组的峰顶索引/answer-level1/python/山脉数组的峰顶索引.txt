#### 方法一：线性扫描

**思路和算法**

从左往右扫描直到山的高度不再增长为止，停止增长点就是峰顶。

```java [solution1-Java]
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int i = 0;
        while (A[i] < A[i+1]) i++;
        return i;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def peakIndexInMountainArray(self, A):
        for i in xrange(len(A)):
            if A[i] > A[i+1]:
                return i
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。

* 空间复杂度：$O(1)$。

#### 方法二：二分查找

**思路和算法**

将山脉数组中所有满足  `A[i] < A[i+1]` 的 `i` 点标记为 `True`，不满足的点标记为 `False`。则一个山脉数组可以标记为：`[True, True, True, ..., True, False, False, ..., False]`。例如山脉数组 `[1, 2, 3, 4, 1]` 可以标记为 `True, True, True, False`。

在山脉数组上使用二分查找，找出满足 `A[i] < A[i+1]` 的最大 `i`。更多关于 *二分查找* 的知识，请访问 [Leetcode 探索](https://leetcode-cn.com/explore/learn/card/binary-search/)。

```java [solution2-Java]
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int lo = 0, hi = A.length - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (A[mi] < A[mi + 1])
                lo = mi + 1;
            else
                hi = mi;
        }
        return lo;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def peakIndexInMountainArray(self, A):
        lo, hi = 0, len(A) - 1
        while lo < hi:
            mi = (lo + hi) / 2
            if A[mi] < A[mi + 1]:
                lo = mi + 1
            else:
                hi = mi
        return lo
```

**复杂度分析**

* 时间复杂度：$O(\log N)$，其中 $N$ 是 `A` 的长度。

* 空间复杂度：$O(1)$。