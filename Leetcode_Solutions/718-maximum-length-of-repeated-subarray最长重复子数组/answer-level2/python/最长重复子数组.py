#### 方法一：穷举 + 哈希表 [超出时间限制]

在最简单的穷举法中，我们穷举数组 `A` 中的起始位置 `i` 和数组 `B` 中的起始位置 `j`，随后超出最大的满足 `A[i: i + k] == B[j: j + k]` 的 `k`。这个过程的伪代码如下：

    ans = 0
    for i in [0 .. A.length - 1]:
        for j in [0 .. B.length - 1]:
            k = 0
            while (A[i+k] == B[j+k]): k += 1 #and i+k < A.length etc.
            ans = max(ans, k)

在多数情况下，`A[i]` 和 `B[j]` 不相等，因此我们可以将 `B` 中所有的字符存入哈希表 `Bstarts`，哈希表的键为字符，值为字符在 `B` 中出现的位置。那么在穷举 `i` 时，我们只需要穷举 `Bstarts[A[i]]` 中的所有位置作为 `j` 即可。但这样做并不能减少时间复杂度。

```Python [sol1]
class Solution(object):
    def findLength(self, A, B):
        ans = 0
        Bstarts = collections.defaultdict(list)
        for j, y in enumerate(B):
            Bstarts[y].append(j)

        for i, x in enumerate(A):
            for j in Bstarts[x]:
                k = 0
                while i+k < len(A) and j+k < len(B) and A[i+k] == B[j+k]:
                    k += 1
                ans = max(ans, k)
        return ans
```

```Java [sol1]
class Solution {
    public int findLength(int[] A, int[] B) {
        int ans = 0;
        Map<Integer, ArrayList<Integer>> Bstarts = new HashMap();
        for (int j = 0; j < B.length; j++) {
            Bstarts.computeIfAbsent(B[j], x -> new ArrayList()).add(j);
        }

        for (int i = 0; i < A.length; i++) if (Bstarts.containsKey(A[i])) {
            for (int j: Bstarts.get(A[i])) {
                int k = 0;
                while (i+k < A.length && j+k < B.length && A[i+k] == B[j+k]) {
                    k++
                }
                ans = Math.max(ans, k);
            }
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(M*N\min(M，N))$，其中 $M$ 和 $N$ 分别是数组 `A` 和 `B` 的长度。
* 空间复杂度：$O(N)$。

#### 方法二：二分查找 + 简单判断 [超出时间限制]

如果数组 `A` 和 `B` 有一个长度为 `k` 的公共子数组，那么它们一定有长度为 `j <= k` 的公共子数组。这样我们可以通过二分查找的方法找到最大的 `k`。

二分查找的下界为 0，上界为 `min(len(A), len(B))`。在二分查找的每一步中，我们仍然使用最简单的判断方法，即找出数组 `A` 和 `B` 中所有长度为 `mid` 的子数组，判断是否存在一个子数组在 `A` 和 `B` 中都出现过。

```Python [sol2]
class Solution(object):
    def findLength(self, A, B):
        def check(length):
            seen = set(tuple(A[i:i+length])
                       for i in xrange(len(A) - length + 1))
            return any(tuple(B[j:j+length]) in seen
                       for j in xrange(len(B) - length + 1))

        lo, hi = 0, min(len(A), len(B)) + 1
        while lo < hi:
            mi = (lo + hi) / 2
            if check(mi):
                lo = mi + 1
            else:
                hi = mi
        return lo - 1
```

```Java [sol2]
class Solution {
    public boolean check(int length, int[] A, int[] B) {
        Set<String> seen = new HashSet();
        for (int i = 0; i + length <= A.length; ++i) {
            seen.add(Arrays.toString(Arrays.copyOfRange(A, i, i+length)));
        }
        for (int j = 0; j + length <= B.length; ++j) {
            if (seen.contains(Arrays.toString(Arrays.copyOfRange(B, j, j+length)))) {
                return true;
            }
        }
        return false;
    }

    public int findLength(int[] A, int[] B) {
        int lo = 0, hi = Math.min(A.length, B.length) + 1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (check(mi, A, B)) lo = mi + 1;
            else hi = mi;
        }
        return lo - 1;
    }
}
```

**复杂度分析**

* 时间复杂度：$O\big((M + N) \min(M, N) \log{(\min(M, N))}\big)$。其中 $M$ 和 $N$ 是数组 `A` 和 `B` 的长度。对于 $L$，简单判断是否有长度为 $L$ 的子数组的时间复杂度为 $O((M+N)*L)$，二分查找为对数时间复杂度。
* 空间复杂度：$O(M^2)$。

#### 方法三：动态规划 [通过]

设 `dp[i][j]` 为 `A[i:]` 和 `B[j:]` 的最长公共前缀，那么答案就为所有 `dp[i][j]` 中的最大值 `max(dp[i][j])`。如果 `A[i] == B[j]`，那么状态转移方程为 `dp[i][j] = dp[i + 1][j + 1] + 1`，否则状态转移方程为 `dp[i][j] = 0`。

```Python [sol3]
class Solution(object):
    def findLength(self, A, B):
        memo = [[0] * (len(B) + 1) for _ in range(len(A) + 1)]
        for i in range(len(A) - 1, -1, -1):
            for j in range(len(B) - 1, -1, -1):
                if A[i] == B[j]:
                    memo[i][j] = memo[i+1][j+1]+1
        return max(max(row) for row in memo)
```

```Java [sol3]
class Solution {
    public int findLength(int[] A, int[] B) {
        int ans = 0;
        int[][] memo = new int[A.length + 1][B.length + 1];
        for (int i = A.length - 1; i >= 0; --i) {
            for (int j = B.length - 1; j >= 0; --j) {
                if (A[i] == B[j]) {
                    memo[i][j] = memo[i+1][j+1] + 1;
                    if (ans < memo[i][j]) ans = memo[i][j];
                }
            }
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(M* N)$，其中 $M$ 和 $N$ 是数组 `A` 和 `B` 的长度。
* 空间复杂度：$O(M* N)$，即为数组 `dp` 使用的空间。

#### 方法四：二分查找 + 哈希 [通过]

**分析**

方法二中的简单判断显得过于简单，在二分查找的每一步中，我们可以考虑使用哈希的方法来判断数组 `A` 和 `B` 中是否存在相同的长度为 `mid` 的子数组。

**算法**

我们使用 Rabin-Karp 算法求出一个序列的哈希值。具体地，我们制定一个素数 $p$，那么序列 $S$ 的哈希值为：

$$
\mathrm{hash}(S) = \sum_{i=0}^{|S|-1} p^i * S[i]
$$

形象地来说，就是把 $S$ 看成一个类似 $p$ 进制的数（但左侧为低位，右侧为高位），它的十进制值就是这个它的哈希值。由于这个值一般会非常大，因此会将它对另一个素数 $M$ 取模。

当我们要在一个序列 $S$ 中算出所有长度为 $l$ 的子序列的哈希值时，我们可以用类似滑动窗口的方法，在线性时间内得到这些子序列的哈希值。例如，如果我们当前得到了 $S[0:l]$ 的哈希值，希望算出 $S[1:l+1]$ 的哈希值，可以通过

$$
S[1:l+1] = \frac{S[0:l] - S[0]}{p} + p^{n-1}*S[l]
$$

得到。由于分子上的 $S[0:l] - S[0]$ 已经对 $M$ 取模，我们无法知道它除以 $p$ 的值，因此我们需要使用 Fermat 小定理的推论：

$$
p^{-1} \equiv p^{M-2}\pmod{M}
$$

将除法变为乘法，这样原式变为

$$
S[1:l+1] = (S[0:l] - S[0]) * p^{M-2} + p^{n-1}*S[l]
$$

为了保证百分百的正确性，当两个字符串的哈希值相等时，我们会判断它们对应的字符串是否相等，防止哈希碰撞。

```Python [sol4]
class Solution(object):
    def findLength(self, A, B):
        P, MOD = 113, 10**9 + 7
        Pinv = pow(P, MOD-2, MOD)
        def check(guess):
            def rolling(A, length):
                if length == 0:
                    yield 0, 0
                    return

                h, power = 0, 1
                for i, x in enumerate(A):
                    h = (h + x * power) % MOD
                    if i < length - 1:
                        power = (power * P) % MOD
                    else:
                        yield h, i - (length - 1)
                        h = (h - A[i - (length - 1)]) * Pinv % MOD

            hashes = collections.defaultdict(list)
            for ha, start in rolling(A, guess):
                hashes[ha].append(start)
            for ha, start in rolling(B, guess):
                iarr = hashes.get(ha, [])
                if any(A[i:i+guess] == B[start:start+guess] for i in iarr):
                    return True
            return False

        lo, hi = 0, min(len(A), len(B)) + 1
        while lo < hi:
            mi = (lo + hi) / 2
            if check(mi):
                lo = mi + 1
            else:
                hi = mi
        return lo - 1
```

```Java [sol4]
import java.math.BigInteger;

class Solution {
    int P = 113;
    int MOD = 1_000_000_007;
    int Pinv = BigInteger.valueOf(P).modInverse(BigInteger.valueOf(MOD)).intValue();

    private int[] rolling(int[] source, int length) {
        int[] ans = new int[source.length - length + 1];
        long h = 0, power = 1;
        if (length == 0) return ans;
        for (int i = 0; i < source.length; ++i) {
            h = (h + source[i] * power) % MOD;
            if (i < length - 1) {
                power = (power * P) % MOD;
            } else {
                ans[i - (length - 1)] = (int) h;
                h = (h - source[i - (length - 1)]) * Pinv % MOD;
                if (h < 0) h += MOD;
            }
        }
        return ans;
    }

    private boolean check(int guess, int[] A, int[] B) {
        Map<Integer, List<Integer>> hashes = new HashMap();
        int k = 0;
        for (int x: rolling(A, guess)) {
            hashes.computeIfAbsent(x, z -> new ArrayList()).add(k++);
        }
        int j = 0;
        for (int x: rolling(B, guess)) {
            for (int i: hashes.getOrDefault(x, new ArrayList<Integer>()))
                if (Arrays.equals(Arrays.copyOfRange(A, i, i+guess),
                                  Arrays.copyOfRange(B, j, j+guess))) {
                    return true;
                }
            j++;
        }
        return false;
    }

    public int findLength(int[] A, int[] B) {
        int lo = 0, hi = Math.min(A.length, B.length) + 1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (check(mi, A, B)) lo = mi + 1;
            else hi = mi;
        }
        return lo - 1;
    }
}
```

**复杂度分析**

* 时间复杂度：$O\big((M+N) \log{(\min(M, N))}\big)$，其中 $M$ 和 $N$ 是数组 `A` 和 `B` 的长度。二分查找为对数时间复杂度，计算哈希值的时间复杂度为 $O(M+N)$，哈希检测的时间复杂度为 $O(1)$。如果我们在哈希值相等时仍然判断它们对应的字符串是否相等，则时间复杂度需要加上 $O(\min(M,N))$ 一项，由于它小于 $O(M+N)$，因此总的时间复杂度不变。
* 空间复杂度：$O(M)$。