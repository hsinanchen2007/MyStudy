#### 方法：二分查找

**思路**

如果珂珂能以 `K` 的进食速度最终吃完所有的香蕉（在 `H` 小时内），那么她也可以用更快的速度吃完。

当珂珂能以 `K` 的进食速度吃完香蕉时，我们令 `possible(K)` 为 `true`，那么就存在 `X` 使得当 `K >= X` 时， `possible(K) = True`。

举个例子，当初始条件为 `piles = [3, 6, 7, 11]` 和 `H = 8` 时，存在 `X = 4` 使得 `possible(1) = possible(2) = possible(3) = False`，且 `possible(4) = possible(5) = ... = True`。

**算法**

我们可以二分查找 `possible(K)` 的值来找到第一个使得 `possible(X)` 为 `True` 的 `X`：这将是我们的答案。我们的循环中，不变量 `possible(hi)` 总为 `True`， `lo` 总小于等于答案。有关二分查找的更多信息，请参阅[《力扣探索：二分查找》](https://leetcode-cn.com/explore/learn/card/binary-search/)。

为了找到 `possible(K)` 的值， (即`珂珂`是否能以 `K` 的进食速度在 `H` 小时内吃完所有的香蕉），我们模拟这一情景。对于每一堆（大小 `p > 0`），我们可以推断出珂珂将在 `Math.ceil(p / K) = ((p-1) // K) + 1` 小时内吃完这一堆，我们将每一堆的完成时间加在一起并与 `H` 进行比较。


```cpp [2q2E5AzB-C++]
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = pow(10, 9);
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (!possible(piles, H, mi))
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
    }

    // Can Koko eat all bananas in H hours with eating speed K?
    bool possible(vector<int>& piles, int H, int K) {
        int time = 0;
        for (int p: piles)
            time += (p - 1) / K + 1;
        return time <= H;
    }
};
```
```java [2q2E5AzB-Java]
class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        int lo = 1;
        int hi = 1_000_000_000;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (!possible(piles, H, mi))
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
    }

    // Can Koko eat all bananas in H hours with eating speed K?
    public boolean possible(int[] piles, int H, int K) {
        int time = 0;
        for (int p: piles)
            time += (p-1) / K + 1;
        return time <= H;
    }
}
```
```python [2q2E5AzB-Python]
class Solution(object):
    def minEatingSpeed(self, piles, H):
        # Can Koko eat all bananas in H hours with eating speed K?
        def possible(K):
            return sum((p-1) / K + 1 for p in piles) <= H

        lo, hi = 1, max(piles)
        while lo < hi:
            mi = (lo + hi) / 2
            if not possible(mi):
                lo = mi + 1
            else:
                hi = mi
        return lo
```


**复杂度分析**

* 时间复杂度：$O(N \log W)$，其中 $N$ 是香蕉堆的数量，$W$ 最大的香蕉堆的大小。

* 空间复杂度：$O(1)$。