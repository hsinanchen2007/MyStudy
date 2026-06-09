#### 方法一：二分查找【通过】

**思路**

 `under(x)` 用于求解小于 `x` 的分数数量，这是一个关于 `x` 的单调增函数，因此可以使用二分查找求解。

**算法**

使用二分查找找出一个 `x`，使得小于 `x` 的分数恰好有 `K` 个，并且记录其中最大的一个分数。

我们的二分搜索与其他的二分搜索方法类似：初始有区间 `[lo, hi]`，中心点 `mi = (lo + hi) / 2.0`。如果小于 `mi` 的分数数量小于 `K`，更新区间为 `[mi, hi]`，否则更新为 `[lo, mi]`。更多关于二分搜索的内容，请访问 LeetCode 探索[这里](https://leetcode-cn.com/explore/learn/card/binary-search/)。

`under(x)` 函数有两个目的：返回小于 `x` 的分数数量以及小于 `x` 的最大分数。在 `under(x)` 函数中使用滑动窗口的方法：对于每个 `primes[j]`，找出最大的 `i` 使得 `primes[i] / primes[j] < x`。随着 `j` （和 `primes[j]`）的增加， `i` 也会随之增加。 

```java [solution1-Java]
class Solution {
    public int[] kthSmallestPrimeFraction(int[] primes, int K) {
        double lo = 0, hi = 1;
        int[] ans = new int[]{0, 1};

        while (hi - lo > 1e-9) {
            double mi = lo + (hi - lo) / 2.0;
            int[] res = under(mi, primes);
            if (res[0] < K) {
                lo = mi;
            } else {
                ans[0] = res[1];
                ans[1] = res[2];
                hi = mi;
            }
        }
        return ans;
    }

    public int[] under(double x, int[] primes) {
        // Returns {count, numerator, denominator}
        int numer = 0, denom = 1, count = 0, i = -1;
        for (int j = 1; j < primes.length; ++j) {
            // For each j, find the largest i so that primes[i] / primes[j] < x
            // It has to be at least as big as the previous i, so reuse it ("two pointer")
            while (primes[i+1] < primes[j] * x) ++i;

            // There are i+1 fractions: (primes[0], primes[j]),
            // (primes[1], primes[j]), ..., (primes[i], primes[j])
            count += i+1;
            if (i >= 0 && numer * primes[j] < denom * primes[i]) {
                numer = primes[i];
                denom = primes[j];
            }
        }
        return new int[]{count, numer, denom};
    }
}
```

```python [solution1-Python]
class Solution(object):
    def kthSmallestPrimeFraction(self, primes, K):
        from fractions import Fraction
        def under(x):
            # Return the number of fractions below x,
            # and the largest such fraction
            count = best = 0
            i = -1
            for j in xrange(1, len(primes)):
                while primes[i+1] < primes[j] * x:
                    i += 1
                count += i+1
                if i >= 0:
                    best = max(best, Fraction(primes[i], primes[j]))
            return count, best

        # Binary search for x such that there are K fractions
        # below x.
        lo, hi = 0.0, 1.0
        while hi - lo > 1e-9:
            mi = (lo + hi) / 2.0
            count, best = under(mi)
            if count < K:
                lo = mi
            else:
                ans = best
                hi = mi

        return ans.numerator, ans.denominator
```


**复杂度分析**

* 时间复杂度：$O(N \log W)$，其中 $N$ 是 `primes` 的长度，`W` 是二分查找的区间宽度，`(hi - lo) / 1e-9` 等于 $10^9$。

* 空间复杂度：$O(1)$。

####方法二：堆【通过】

**思路**

使用一个堆记录所有以 `primes[j]` 为分母且未被弹出的最小分数。依次从堆中弹出 `K-1` 个元素，此时堆顶的分数就是结果。


**算法**

在 Python 中，使用 `(fraction, i, j)` 表示分数 `fraction = primes[i] / primes[j]`。如果下一个分数有效（即 `i+1 < j`），那么使用当前分数时，将下一个分数压入堆中。

在Java中，使用记录  `{i, j}` （`i` 和 `j` 是索引，不是 `A` 中的元素）的 `int[2]` 表示分数，自定义比较器确保所有分数按照正确顺序存储。

```java[solution2-Java]
class Solution {
    public int[] kthSmallestPrimeFraction(int[] A, int K) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) ->
                A[a[0]] * A[b[1]] - A[a[1]] * A[b[0]]);

        for (int i = 1; i < A.length; ++i)
            pq.add(new int[]{0, i});

        while (--K > 0) {
            int[] frac = pq.poll();
            if (frac[0]++ < frac[1])
                pq.offer(frac);
        }

        int[] ans = pq.poll();
        return new int[]{A[ans[0]], A[ans[1]]};
    }
}
```

```python[solution2-Python]
class Solution(object):
    #Note - this solution may TLE.
    def kthSmallestPrimeFraction(self, A, K):
        pq = [(A[0] / float(A[i]), 0, i) for i in xrange(len(A) - 1, 0, -1)]

        for _ in xrange(K-1):
            frac, i, j = heapq.heappop(pq)
            i += 1
            if i < j:
                heapq.heappush(pq, (A[i] / float(A[j]), i, j))

        return A[pq[0][1]], A[pq[0][2]]
```

**复杂度分析**

* 时间复杂度：$O(K \log N)$，其中 $N$ 是 `A` 的长度，堆中最多压入 $N$ 个元素，每次弹出为 $O(\log N)$，需要 $O(K)$ 次弹出操作。

* 空间复杂度：$O(N)$，堆的大小。

#### 方法三：分治法【通过】

**说明**

除此之外，使用分治法也能解答此问题，时间复杂度可以达到 $O(N)$。将所有由素数组成的分数写到一个行和列都增长的矩阵中，然后查找其中第 `K` 个元素。它的主要思想与删除原始矩阵中所有奇数行和列，然后求其中的第 `K/4` 个元素非常相似。