#### 方法 1：辅助数组

**想法**

不检验 `all(L <= R for L in left for R in right)`，而是检验 `max(left) <= min(right)`。

**算法**

找出对于所有子集 `left = A[:1], left = A[:2], left =  A[:3], ...` 的最大值 `max(left)`，也就是用 `maxleft[i]` 记录子集 `A[:i]` 的最大值。两两之间是相互关联的：`max(A[:4]) = max(max(A[:3]), A[3])` 所以有 `maxleft[4] = max(maxleft[3], A[3])`。

同理，所有可能的 `right` 子集最小值 `min(right)` 也可以在线性时间内获得。

最后只需要快速扫描一遍 `max(left)` 和 `min(right)`，答案非常明显。

```Java []
class Solution {
    public int partitionDisjoint(int[] A) {
        int N = A.length;
        int[] maxleft = new int[N];
        int[] minright = new int[N];

        int m = A[0];
        for (int i = 0; i < N; ++i) {
            m = Math.max(m, A[i]);
            maxleft[i] = m;
        }

        m = A[N-1];
        for (int i = N-1; i >= 0; --i) {
            m = Math.min(m, A[i]);
            minright[i] = m;
        }

        for (int i = 1; i < N; ++i)
            if (maxleft[i-1] <= minright[i])
                return i;

        throw null;
    }
}
```

```Python []
class Solution(object):
    def partitionDisjoint(self, A):
        N = len(A)
        maxleft = [None] * N
        minright = [None] * N

        m = A[0]
        for i in xrange(N):
            m = max(m, A[i])
            maxleft[i] = m

        m = A[-1]
        for i in xrange(N-1, -1, -1):
            m = min(m, A[i])
            minright[i] = m

        for i in xrange(1, N):
            if maxleft[i-1] <= minright[i]:
                return i
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(N)$。