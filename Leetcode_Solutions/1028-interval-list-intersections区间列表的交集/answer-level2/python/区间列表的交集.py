#### 方法：归并区间

**思路**

我们称 `b` 为区间 `[a, b]` 的末端点。

在两个数组给定的所有区间中，考虑拥有最小末端点的区间 `A[0]`。（为了不失一般性，假设 `A[0]`出现在数组 `A` 中)

然后，在数组 `B` 的区间中， `A[0]` 只可能与数组 `B` 中的至多一个区间相交。（如果 `B` 中存在两个区间均与 `A[0]` 相交，那么它们将共同包含 `A[0]` 的末端点，但是 `B` 中的区间应该是不相交的，所以导出矛盾）

**算法**

如果 `A[0]` 拥有最小的末端点，那么它只可能与 `B[0]` 相交。然后我们就可以删除区间 `A[0]` 了，因为它不能与其他任何区间再相交了。

相似的，如果 `B[0]` 拥有最小的末端点，那么它只可能与区间 `A[0]` 相交，然后我们就可以将 `B[0]` 删除了，因为它无法再与其他区间相交了。

我们用两个指针 `i` 与 `j` 来虚拟地完成删除 `A[0]` 或 `B[0]` 的操作。

```java [yoDCKCGP-Java]
class Solution {
    public Interval[] intervalIntersection(Interval[] A, Interval[] B) {
        List<Interval> ans = new ArrayList();
        int i = 0, j = 0;

        while (i < A.length && j < B.length) {
            // Let's check if A[i] intersects B[j].
            // lo - the startpoint of the intersection
            // hi - the endpoint of the intersection
            int lo = Math.max(A[i].start, B[j].start);
            int hi = Math.min(A[i].end, B[j].end);
            if (lo <= hi)
                ans.add(new Interval(lo, hi));

            // Remove the interval with the smallest endpoint
            if (A[i].end < B[j].end)
                i++;
            else
                j++;
        }

        return ans.toArray(new Interval[ans.size()]);
    }
}
```
```python [yoDCKCGP-Python]
class Solution(object):
    def intervalIntersection(self, A, B):
        ans = []
        i = j = 0

        while i < len(A) and j < len(B):
            # Let's check if A[i] intersects B[j].
            # lo - the startpoint of the intersection
            # hi - the endpoint of the intersection
            lo = max(A[i].start, B[j].start)
            hi = min(A[i].end, B[j].end)
            if lo <= hi:
                ans.append(Interval(lo, hi))

            # Remove the interval with the smallest endpoint
            if A[i].end < B[j].end:
                i += 1
            else:
                j += 1

        return ans
```


**复杂度分析**

* 时间复杂度：$O(M + N)$，其中 $M, N$ 分别是数组 `A` 与 `B` 的长度。

* 空间复杂度：$O(M + N)$，也是答案区间数量的上限。



