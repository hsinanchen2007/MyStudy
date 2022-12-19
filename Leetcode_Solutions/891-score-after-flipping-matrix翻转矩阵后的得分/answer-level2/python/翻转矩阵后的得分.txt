#### 方法一：枚举

**分析**

注意到将一行或者一列翻转两次及以上是没有意义的，因为翻转两次等价于没有进行任何翻转。因此每一行和每一列最多被翻转了一次。

我们首先枚举每一行是否被翻转，对于一个 `R` 行 `C` 列的矩阵，可能的翻转情况有 `2^R` 种。随后对于每一列，`1` 的个数应该越多越好。如果某一列当前有 `k` 个 `1`，那么翻转后将会有 `R - k` 个 `1`，我们比较 `k` 和 `R - k` 的大小，就可以判断这一列是否需要翻转。

**算法**

设矩阵有 `R` 行 `C` 列，我们用一个 `R` 位的二进制数 `state` 表示每一行是否被翻转，`state` 的范围是 `[0 .. 2^R)`。

我们从小到大枚举 `state`，并且直接在前一次的翻转结果上进行翻转。对于当前的 `state`，它相对于 `state - 1` 而言，`trans = state ^ (state - 1)` 就表示了 `state` 相对于前一次 `state - 1` 的翻转变化。

在进行了行的翻转之后，我们对于每一列统计 `1` 的个数 `col_sum`，在 `col_sum` 和 `R - col_sum` 中选择一个较大值。

这种方法可能会超出时间限制。

```Java [sol1]
class Solution {
    public int matrixScore(int[][] A) {
        int R = A.length, C = A[0].length;
        int[] colsums = new int[C];
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                colsums[c] += A[r][c];

        int ans = 0;
        for (int state = 0; state < (1<<R); ++state) {
            // Toggle the rows so that after, 'state' represents
            // the toggled rows.
            if (state > 0) {
                int trans = state ^ (state-1);
                for (int r = 0; r < R; ++r) {
                    if (((trans >> r) & 1) > 0) {
                        for (int c = 0; c < C; ++c) {
                            colsums[c] += A[r][c] == 1 ? -1 : 1;
                            A[r][c] ^= 1;
                        }
                    }
                }
            }

            // Calculate the score with the rows toggled by 'state'
            int score = 0;
            for (int c = 0; c < C; ++c)
                score += Math.max(colsums[c], R - colsums[c]) * (1 << (C-1-c));
            ans = Math.max(ans, score);
        }

        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def matrixScore(self, A):
        R, C = len(A), len(A[0])

        colsums = [0] * C
        for r in xrange(R):
            for c in xrange(C):
                colsums[c] += A[r][c]

        ans = 0
        for r in xrange(1<<R):
            if r:
                trans = r ^ (r-1)
                for bit in xrange(R):
                    if (trans >> bit) & 1:
                        for c in xrange(C):
                            colsums[c] += -1 if A[bit][c] else +1
                            A[bit][c] ^= 1
            
            score = sum(max(x, R - x) * (1 << (C-1-c))
                        for c, x in enumerate(colsums))
            ans = max(ans, score)

        return ans
```

**复杂度分析**

* 时间复杂度：$O(2^R * R * C)$，其中 $R$ 和 $C$ 是矩阵的行和列的大小。

* 空间复杂度：$O(C)$。

#### 方法二：贪心

**分析**

在方法一的基础上，我们可以想到：对于任意一行而言，如果这一行的第一个数 `1`，那么它的分数一定会比不是 `1` 要高。这是因为第一个 `1` 代表了 $2^{C-1}$，而如果第一位是 `0`，那么即使后面所有的位置都是 `1`，这一行的值最多也是 $2^{C-2} + \cdots + 2^1 + 2^0 = 2^{C-1}-1$，小于 $2^{C-1}$。因此我们不需要枚举每一行是否需要翻转，而是变为：如果该行的第一位是 `0`，则翻转，否则不翻转。

**算法**

代码中的实现和分析中的略有不同，在代码中，如果该行的第一位是 `0` 则翻转，否则不翻转（这可以通过代码 `A[r][c] ^= A[r][0]` 直接实现），并在行翻转完毕后，对第一列进行翻转，这样也使得每一行的第一位都是 `1`。

随后我们枚举每一列是否翻转，使用的方法与方法一中的完全相同。

```Java [sol2]
class Solution {
    public int matrixScore(int[][] A) {
        int R = A.length, C = A[0].length;
        int ans = 0;
        for (int c = 0; c < C; ++c) {
            int col = 0;
            for (int r = 0; r < R; ++r)
                col += A[r][c] ^ A[r][0];
            ans += Math.max(col, R - col) * (1 << (C-1-c));
        }
        return ans;
    }
}
```

```Python [sol2]
class Solution(object):
    def matrixScore(self, A):
        R, C = len(A), len(A[0])
        ans = 0
        for c in xrange(C):
            col = 0
            for r in xrange(R):
                col += A[r][c] ^ A[r][0]
            ans += max(col, R - col) * 2 ** (C - 1 - c)
        return ans
```

**复杂度分析**

* 时间复杂度：$O(R * C)$，其中 $R$ 和 $C$ 是矩阵的行和列的大小。

* 空间复杂度：$O(1)$。