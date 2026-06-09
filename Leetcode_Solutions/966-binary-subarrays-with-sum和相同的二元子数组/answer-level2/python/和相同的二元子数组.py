#### Approach 1: 枚举子数组中 1 的位置

我们设数组 `A` 中有 `k` 个 `1`，它们的位置从小到大分别为 $x_1, x_2, \cdots, x_k$。对于一个和为 `S` 的子数组，它包含的 `1` 一定是 $x_1, x_2, \cdots, x_k$ 中的某一个连续的段 $x_i, x_{i+1}, \cdots, x_{i+S-1}$。因此我们可以枚举这个连续段的起始位置 `i`，并计算出包含该连续段的所有和为 `S` 的非空子数组。

对于某一个连续的段 $x_i, x_{i+1}, \cdots, x_{i+S-1}$，包含该连续段的所有和为 `S` 的非空子数组个数为：

$$
(x_i - x_{i-1}) * (x_{i+S} - x_{i+S-1})
$$

形象地说，$x_i$ 左侧有 $x_i - x_{i-1} - 1$ 个 `0`，选择任意数量的 `0` 都不会改变子数组的和（也可以不选择任何 `0`)，因此左侧有 $x_i - x_{i-1}$ 种选择方法。同理，右侧有 $x_{i+S} - x_{i+S-1}$ 种选择方法。

例如当 `S` 的值为 `2`，`A` 为 `[1,0,1,0,1,0,0,1]` 时，我们尝试计算包含中间（即位置 `2` 和 `4`）两个 `1` 的子数组数目。子数组的左侧有 `1` 个 `0`，因此有 `2` 种选择（即位置 `1` 和 `2`）；右侧有 `2` 个 `0`，因此有 `3` 种选择（即位置 `4`，`5` 和 `6`）。总共有 `2 * 3 = 6` 种选择。

此外，需要注意考虑边界情况和特殊情况，例如 `S = 0`，`i = 1` 以及 `i + S - 1 = k`。

```Java [sol1]
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int su = 0;
        for (int x: A) su += x;

        // indexes[i] = location of i-th one (1 indexed)
        int[] indexes = new int[su + 2];
        int t = 0;
        indexes[t++] = -1;
        for (int i = 0; i < A.length; ++i)
            if (A[i] == 1)
                indexes[t++] = i;
        indexes[t] = A.length;

        int ans = 0;
        if (S == 0) {
            for (int i = 0; i < indexes.length - 1; ++i) {
                // w: number of zeros between consecutive ones
                int w = indexes[i+1] - indexes[i] - 1;
                ans += w * (w + 1) / 2;
            }
            return ans;
        }

        for (int i = 1; i < indexes.length - S; ++i) {
            int j = i + S - 1;
            int left = indexes[i] - indexes[i-1];
            int right = indexes[j+1] - indexes[j];
            ans += left * right;
        }

        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def numSubarraysWithSum(self, A, S):
        indexes = [-1] + [ix for ix, v in enumerate(A) if v] + [len(A)]
        ans = 0

        if S == 0:
            for i in xrange(len(indexes) - 1):
                # w: number of zeros between two consecutive ones
                w = indexes[i+1] - indexes[i] - 1
                ans += w * (w+1) / 2
            return ans

        for i in xrange(1, len(indexes) - S):
            j = i + S - 1
            left = indexes[i] - indexes[i-1]
            right = indexes[j+1] - indexes[j]
            ans += left * right
        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(N)$。

#### 方法二：前缀和

**分析**

设数组 `P` 为数组 `A` 的前缀和，即：

`P[i] = A[0] + A[1] + ... + A[i - 1]`

这样就可以通过 `P[j + 1] - P[i] = A[i] + A[i + 1] + ... + A[j]` 快速计算出 `A[i..j]` 的和。

我们可以对数组 `P` 进行一次线性扫描，当扫描到 `P[j]` 时，我们需要得到的是满足 `P[j] = P[i] + S` 且 `i < j` 的 `i` 的数目，使用计数器（`map` 或 `dict`）可以满足要求。

```Java [sol2]
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int N = A.length;
        int[] P = new int[N + 1];
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + A[i];

        Map<Integer, Integer> count = new HashMap();
        int ans = 0;
        for (int x: P) {
            ans += count.getOrDefault(x, 0);
            count.put(x+S, count.getOrDefault(x+S, 0) + 1);
        }

        return ans;
    }
}
```

```Python [sol2]
class Solution(object):
    def numSubarraysWithSum(self, A, S):
        P = [0]
        for x in A: P.append(P[-1] + x)
        count = collections.Counter()

        ans = 0
        for x in P:
            ans += count[x]
            count[x + S] += 1

        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(N)$。

#### 方法三：三指针

在方法二中，我们在固定区间的右端点 `j` 时，用计数器求出满足要求的左端点 `i` 的数目。而由于此题的特殊性，前缀和数组 `P` 是单调不降的，因此左端点的位置一定是连续的，即可以用 `[i_lo, i_hi]` 表示，并且随着 `j` 的增加，`i_lo` 和 `i_hi` 也单调不降，因此可以用类似双指针的方法，使用三个指针维护左端点的区间。

我们遍历区间的右端点 `j`，同时维护四个变量：

* `sum_lo`：`A[i_lo..j]` 的值；

* `sum_hi`：`A[i_hi..j]` 的值；

* `i_lo`：最小的满足 `sum_lo <= S` 的 `i`；

* `i_hi`：最大的满足 `sum_hi <= S` 的 `i`。

例如，当数组 `A` 为 `[1,0,0,1,0,1]`，`S` 的值为 `2` 。当 `j = 5` 时，`i_lo` 的值为 `1`，`i_hi` 的值为 `3`。对于每一个 `j`，和为 `S` 的非空子数组的数目为 `i_hi - i_lo + 1`。

```Java [sol3]
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int iLo = 0, iHi = 0;
        int sumLo = 0, sumHi = 0;
        int ans = 0;

        for (int j = 0; j < A.length; ++j) {
            // While sumLo is too big, iLo++
            sumLo += A[j];
            while (iLo < j && sumLo > S)
                sumLo -= A[iLo++];

            // While sumHi is too big, or equal and we can move, iHi++
            sumHi += A[j];
            while (iHi < j && (sumHi > S || sumHi == S && A[iHi] == 0))
                sumHi -= A[iHi++];

            if (sumLo == S)
                ans += iHi - iLo + 1;
        }

        return ans;
    }
}
```

```Python [sol3]
class Solution(object):
    def numSubarraysWithSum(self, A, S):
        i_lo = i_hi = 0
        sum_lo = sum_hi = 0
        ans = 0
        for j, x in enumerate(A):
            # Maintain i_lo, sum_lo:
            # While the sum is too big, i_lo += 1
            sum_lo += x
            while i_lo < j and sum_lo > S:
                sum_lo -= A[i_lo]
                i_lo += 1

            # Maintain i_hi, sum_hi:
            # While the sum is too big, or equal and we can move, i_hi += 1
            sum_hi += x
            while i_hi < j and (
                    sum_hi > S or sum_hi == S and not A[i_hi]):
                sum_hi -= A[i_hi]
                i_hi += 1

            if sum_lo == S:
                ans += i_hi - i_lo + 1

        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(1)$。