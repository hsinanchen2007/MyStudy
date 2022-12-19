#### 方法一：两次遍历

**思路**

如果数组单调递增或单调递减，那么该数组是*单调的*。由于 `a <= b` 和 `b <= c` 暗示着 `a <= c`，我们只需要检查相邻元素以确定数组是单调递增（或是递减）。我们可以在一次遍历中检查每个属性。

**算法**

要检查数组 `A` 是否单调递增，我们将检查每个 `i` 是否对应有 `A[i] <= A[i+1]`。对单调检查是类似的。

```java [3M273HV5-Java]
class Solution {
    public boolean isMonotonic(int[] A) {
        return increasing(A) || decreasing(A);
    }

    public boolean increasing(int[] A) {
        for (int i = 0; i < A.length - 1; ++i)
            if (A[i] > A[i+1]) return false;
        return true;
    }

    public boolean decreasing(int[] A) {
        for (int i = 0; i < A.length - 1; ++i)
            if (A[i] < A[i+1]) return false;
        return true;
    }
}
```
```python [3M273HV5-Python]
class Solution(object):
    def isMonotonic(self, A):
        return (all(A[i] <= A[i+1] for i in xrange(len(A) - 1)) or
                all(A[i] >= A[i+1] for i in xrange(len(A) - 1)))
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。

* 空间复杂度：$O(1)$。






---
#### 方法二：一次遍历

**思路**

要在一次遍历中执行该检查，我们将会处理由 $\{-1, 0, 1\}$ 组成的比较流，分别对应  `<`，`==`，或 `>`。例如，对于数组 `[1, 2, 2, 3, 0]`，我们将会看到数据流 `(-1, 0, -1, 1)`。

**算法**

跟踪 `store`，它的值等于所看到的第一个非零比较值（如果存在）。一旦我们看到与之相反的比较值，那么答案就变成了 `False`。

否则，每次比较值都必定在集合 $\{-1, 0\}$ 中或是在 $\{0, 1\}$ 中，此时数组是单调的。

```java [qMnnemXy-Java]
class Solution {
    public boolean isMonotonic(int[] A) {
        int store = 0;
        for (int i = 0; i < A.length - 1; ++i) {
            int c = Integer.compare(A[i], A[i+1]);
            if (c != 0) {
                if (c != store && store != 0)
                    return false;
                store = c;
            }
        }

        return true;
    }
}
```
```python [qMnnemXy-Python]
class Solution(object):
    def isMonotonic(self, A):
        store = 0
        for i in xrange(len(A) - 1):
            c = cmp(A[i], A[i+1])
            if c:
                if c != store != 0:
                    return False
                store = c
        return True
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。

* 空间复杂度：$O(1)$。