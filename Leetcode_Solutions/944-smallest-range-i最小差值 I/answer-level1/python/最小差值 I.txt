#### 方法 1：数学

**想法和算法**

假设 `A` 是原始数组，`B` 是修改后的数组，我们需要最小化 `max(B) - min(B)`，也就是分别最小化 `max(B)` 和最大化 `min(B)`。

`max(B)` 最小可能为 `max(A) - K`，因为 `max(A)` 不可能再变得更小。同样，`min(B)` 最大可能为 `min(A) + K`。所以结果 `max(B) - min(B)` 至少为 `ans = (max(A) - K) - (min(A) + K)`。

我们可以用一下修改方式获得结果（如果 `ans >= 0`）：

* 如果 $A[i] \leq \min(A) + K$，那么 $B[i] = \min(A) + K$
* 如果 $A[i] \geq \max(A) - K$，那么 $B[i] = \max(A) - K$
* 否则 $B[i] = A[i]$。

如果 `ans < 0`，最终结果会有 `ans = 0`，同样利用上面的修改方式。

```Java []
class Solution {
    public int smallestRangeI(int[] A, int K) {
        int min = A[0], max = A[0];
        for (int x: A) {
            min = Math.min(min, x);
            max = Math.max(max, x);
        }
        return Math.max(0, max - min - 2*K);
    }
}
```

```Python []
class Solution(object):
    def smallestRangeI(self, A, K):
        return max(0, max(A) - min(A) - 2*K)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(1)$。