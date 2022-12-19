#### 方法：数学

**思路**

让我们试着统计具有最小值 `A[i]` 和最大值 `A[j]` 的子序列的数量。

**算法**

我们可以对数组进行排序，因为这并不会改变答案。对数组进行排序后，我们可以得知有最小值 `A[i]` 和最大值 `A[j]` 的子序列的数目是 $2^{j-i-1}$。因此，期望的答案为：

$$
\sum\limits_{j > i} (2^{j-i-1}) (A_j - A_i)
$$

$$
= \big( \sum\limits_{i = 0}^{n-2} \sum\limits_{j = i+1}^{n-1} (2^{j-i-1}) (A_j) \big) - \big( \sum\limits_{i = 0}^{n-2} \sum\limits_{j = i+1}^{n-1} (2^{j-i-1}) (A_i) \big)
$$

$$
= \big( (2^0 A_1 + 2^1 A_2 + 2^2 A_3 + \cdots) + (2^0 A_2 + 2^1 A_3 + \cdots) + (2^0 A_3 + 2^1 A_4 + \cdots) + \cdots \big)
$$
$$
 - \big( \sum\limits_{i = 0}^{n-2} (2^0 + 2^1 + \cdots + 2^{N-i-2}) (A_i) \big)
$$

$$
= \big( \sum\limits_{j = 1}^{n-1} (2^j - 1) A_j \big) - \big( \sum\limits_{i = 0}^{n-2} (2^{N-i-1} - 1) A_i \big)
$$

$$
= \sum\limits_{i = 0}^{n-1} \big(((2^i - 1) A_i) - ((2^{N-i-1} - 1) A_i)\big)
$$

$$
= \sum\limits_{i = 0}^{n-1} (2^i - 2^{N-i-1}) A_i
$$

```java [DorYCcF2-Java]
class Solution {
    public int sumSubseqWidths(int[] A) {
        int MOD = 1_000_000_007;
        int N = A.length;
        Arrays.sort(A);

        long[] pow2 = new long[N];
        pow2[0] = 1;
        for (int i = 1; i < N; ++i)
            pow2[i] = pow2[i-1] * 2 % MOD;

        long ans = 0;
        for (int i = 0; i < N; ++i)
            ans = (ans + (pow2[i] - pow2[N-1-i]) * A[i]) % MOD;

        return (int) ans;
    }
}
```
```python [DorYCcF2-Python]
class Solution(object):
    def sumSubseqWidths(self, A):
        MOD = 10**9 + 7
        N = len(A)
        A.sort()

        pow2 = [1]
        for i in xrange(1, N):
            pow2.append(pow2[-1] * 2 % MOD)

        ans = 0
        for i, x in enumerate(A):
            ans = (ans + (pow2[i] - pow2[N-1-i]) * x) % MOD
        return ans
```


**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是 `A` 的长度。

* 空间复杂度：$O(N)$，`pow2` 所用的空间。（我们可以通过动态地计算这些乘方将其改进到 $O(1)$）。