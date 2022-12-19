#### 方法一：数位动态规划

**分析**

我们称满足 `X <= N` 且仅包含 `D` 中出现的数字的 `X` 为合法的。我们的目标是找出所有合法的 `X` 的个数。

设 `N` 是一个 `K` 位数，那么对于任意一个小于 `K`（假设有 `k` 位，即 `k < K`）的数，如果它仅包含 `D` 中出现的数字，那么它就是合法的，并且 `k` 位数中，合法的数一共有 $|D|^k$ 个。

考虑完位数小于 `K` 的数，我们接下来考虑位数等于 `K` 的数，我们用 `N = 2345` 作为例子来考虑所有合法的 `K = 4` 位数。

* 如果第 `1` 个数位比 `N` 中对应的第 `1` 个数位（即 `2`）小，那么剩下的 `3` 个数位我们可以使用 `D` 中的任何一个数字，因此有 $|D|^{k-1}$ 个合法的数。

* 如果第 `1` 个数位和 `N` 中对应的第 `1` 个数位（即 `2`）相等，那么从第 `2` 个数位开始，它既可以比 `N` 中对应的第 `2` 个数位（即 `3`）小，也可以相等。此时相当于我们在考虑一个 `K - 1` 位数的问题。

**算法**

我们用 `dp[i]` 表示小于等于 `N` 中最后 `|N| - i` 位数的合法数的个数，例如当 `N = 2345` 时，`dp[0], dp[1], dp[2], dp[3]` 分别表示小于等于 `2345, 345, 45, 5` 的合法数的个数。我们从大到小计算 `dp[i]`，状态转移方程为：

`dp[i] = (number of d in D with d < S[i]) * ((|D|) ** (|N| - i - 1))`

即我们枚举第 `|N| - i` 位数，后面的 `|N| - i - 1` 位数可以在 `D` 中任选。如果 `N` 的第 `|N| - i` 位数在 `D` 中，上述的状态转移方程还需要加上一项 `dp[i + 1]`。

最终的答案为 `dp[0]` 加上所有 `k < K` 位的合法的数。

```Java [sol1]
class Solution {
    public int atMostNGivenDigitSet(String[] D, int N) {
        String S = String.valueOf(N);
        int K = S.length();
        int[] dp = new int[K+1];
        dp[K] = 1;

        for (int i = K-1; i >= 0; --i) {
            // compute dp[i]
            int Si = S.charAt(i) - '0';
            for (String d: D) {
                if (Integer.valueOf(d) < Si)
                    dp[i] += Math.pow(D.length, K-i-1);
                else if (Integer.valueOf(d) == Si)
                    dp[i] += dp[i+1];
            }
        }

        for (int i = 1; i < K; ++i)
            dp[0] += Math.pow(D.length, i);
        return dp[0];
    }
}
```

```Python [sol1]
class Solution:
    def atMostNGivenDigitSet(self, D, N):
        S = str(N)
        K = len(S)
        dp = [0] * K + [1]
        # dp[i] = total number of valid integers if N was "N[i:]"

        for i in xrange(K-1, -1, -1):
            # Compute dp[i]

            for d in D:
                if d < S[i]:
                    dp[i] += len(D) ** (K-i-1)
                elif d == S[i]:
                    dp[i] += dp[i+1]

        return dp[0] + sum(len(D) ** i for i in xrange(1, K))
```

**复杂度分析**

* 时间复杂度：$O(|N|)$，也可以写作 $O(\log N)$，它们只相差一个常数，是等价的。

* 空间复杂度：$O(|N|)$。

#### 方法二：数学

**分析**

我们令 `B = |D|`，一个合法的数仅包含 `D` 中的数字，如果我们把 `D` 中数字从小到大映射为 `[1 .. B]`，那么将对我们的计数有很大的便利。例如，当 `D` 包含 `[1, 3, 5, 7]` 时，我们将它映射为 `[1, 2, 3, 4]`，那么合法的数也从 `1, 3, 5, 7, 11, 13, 15, 17, 31, ...` 映射为 `1, 2, 3, 4, 11, 12, 13, 14, 21, ...`。这样的好处是，对于任何一个映射好的数，我们可以用类似进制转换的方式，得到它是第一个合法的数，例如 `34` 就是第 `3 * B + 4 = 3 * 4 + 4 = 16` 个合法的数。

有了这样的性质，我们可以先求出小于等于 `N` 的最大的合法的数，随后对它进行映射，如果它为第 `m` 个合法的数，就说明小于等于 `N` 的合法的数一共有 `m` 个。

**算法**

如果求出了小于等于 `N` 的最大的合法的数 `X`，后面的两步（映射，进制转换）的方法就都比较显然了，因此我们只重点说明求出 `X` 的方法。

我们从 `X` 的最高位开始，每次参考 `N` 中对应的数字，写下一个数位，直到写完最低位的数字。在写某一个数位时，会遇到下面的若干种情况（假设 `D` 为 `[2, 4, 6, 8]`）：

* 如果 `N` 中对应的数字在 `D` 中出现，那么在 `X` 的这一位写下与 `N` 相同的数字。例如当 `N` 为 `25123` 时，我们要参考最高位的数字 `2`，它在 `D` 中出现，因此我们也在 `X` 的最高位写下 `2`。

* 如果 `N` 中对应的数字没有在 `D` 中出现，但它大于 `D` 中最小的数字，那么就在 `X` 这一位写下 `D` 中比该数字小的最大的数字。例如当 `N` 为 `5123` 时，我们要参考最高位的数字 `5`，它没有在 `D` 中出现，我们就在 `X` 的最高位写下 `D` 中比 `5` 小的最大的数字 `4`。

* 如果 `N` 中对应的数字没有在 `D` 中出现，并且它小于 `D` 中最小的数字，那么我们需要把上一个写下的数字替换成 `D` 中一个更小的数字，如果 `D` 中没有更小的数字，那么就延续到再上一个写下的数字，只要某个数字可以替换成 `D` 中一个更小的数字，或者没有可以替换的数字。如果是前者，我们就从被替换的数字的下一位开始，将之后的所有数位都写下 `D` 中最大的数字；如果是后者，说明最大的合法的数 `X` 的位数比 `N` 小，那么我们写下一个 `|N| - 1` 位的，每一位都是 `D` 中最大的数字的数即可。下面给出了一个更加具体的例子：

    当 `N` 为 `123` 时，我们发现最高位的 `1` 比 `D` 中最小的 `2` 还要小，因为它是最高位，所以说明最大的合法的数 `X` 应该只有 `2` 位，因此 `X` 为 `88`；当 `N` 为 `4123` 时，我们在最高位填了 `4` 之后，次高位的 `1` 小于 `2`，因此将最高位换成更小的数字 `2`，再在后面都写下 `8`，得到 `2888`；当 `N` 为 `22123` 时Z，我们在前两位填了 `22` 之后，第三位的 `1` 小于 `2`，并且前两位都无法换成更小的数字，因此 `X` 应该只有 `4` 位，即 `8888`。

```Java [sol2]
class Solution {
    public int atMostNGivenDigitSet(String[] D, int N) {
        int B = D.length; // bijective-base B
        char[] ca = String.valueOf(N).toCharArray();
        int K = ca.length;
        int[] A = new int[K];
        int t = 0;

        for (char c: ca) {
            int c_index = 0;  // Largest such that c >= D[c_index - 1]
            boolean match = false;
            for (int i = 0; i < B; ++i) {
                if (c >= D[i].charAt(0))
                    c_index = i+1;
                if (c == D[i].charAt(0))
                    match = true;
            }

            A[t++] = c_index;
            if (match) continue;

            if (c_index == 0) { // subtract 1
                for (int j = t-1; j > 0; --j) {
                    if (A[j] > 0) break;
                    A[j] += B;
                    A[j-1]--;
                }
            }

            while (t < K)
                A[t++] = B;
            break;
        }

        int ans = 0;
        for (int x: A)
            ans = ans * B + x;
        return ans;
    }
}
```

```Python [sol2]
class Solution(object):
    def atMostNGivenDigitSet(self, D, N):
        B = len(D) # bijective-base B
        S = str(N)
        K = len(S)
        A = []  #  The largest valid number in bijective-base-B.

        for c in S:
            if c in D:
                A.append(D.index(c) + 1)
            else:
                i = bisect.bisect(D, c)
                A.append(i)
                # i = 1 + (largest index j with c >= D[j], or -1 if impossible)
                if i == 0:
                    # subtract 1
                    for j in xrange(len(A) - 1, 0, -1):
                        if A[j]: break
                        A[j] += B
                        A[j-1] -= 1

                A.extend([B] * (K - len(A)))
                break

        ans = 0
        for x in A:
            ans = ans * B + x
        return ans
```

**复杂度分析**

* 时间复杂度：$O(|N|)$，也可以写作 $O(\log N)$，它们只相差一个常数，是等价的。

* 空间复杂度：$O(|N|)$。