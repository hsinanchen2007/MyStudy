#### Kanade 算法介绍

**方法介绍**

在方法 1 和方法 2 中，“grindy” 的解决方法需要很少的思考，但对于那些熟知这种方法的人而言，非常直观。如果没有经验，这些方法很难被发现。

方法 3 和方法 4 更容易实现，但需要更多的思考。

**Kadane 算法解释**

为了理解本文的算法，我们需要熟悉 Kadane 算法。在这个章节，我们解释算法背后的核心逻辑。

对于一个给定数组 `A`，Kadane 算法可以用来找到 `A` 的最大子段和。这里，我们只考虑非空子段。

Kadane 算法基于动态规划。令 `dp[j]` 为以 `A[j]` 结尾的最大子段和。也就是，

$$
\text{dp}[j] = \max\limits_i (A[i] + A[i+1] + \cdots + A[j])
$$

那么，以 `j+1` j结尾的子段（例如 `A[i], A[i+1] + ... + A[j+1]`）最大化了 `A[i] + ... + A[j]` 的和，当这个子段非空那么就等于 `dp[j]` 否则就等于 `0`。所以，有以下递推式：

$$
\text{dp}[j+1] = A[j+1] + \max(\text{dp}[j], 0)
$$

由于一个子段一定从某个位置截止，所以 $\max\limits_j dp[j]$ 就是需要的答案。

为了计算 `dp` 数组更快，Kadane 算法通常节约空间复杂度的形式表示。我们只维护两个变量 `ans` 等于 $\max\limits_j dp[j]$ 和 `cur` 等于 $dp[j]$。随着 `j` 从 $0$ 到 $A.\text{length}-1$ 遍历。

Kadane 算法的伪代码如下：

```python [-Python]
#Kadane's algorithm
ans = cur = None
for x in A:
    cur = x + max(cur, 0)
    ans = max(ans, cur)
return ans
```

#### 方法 1：邻接数组

**想法和算法**

循环数组的子段可以被分成 *单区间* 子段或者 *双区间* 子段，取决于定长数组 `A` 需要多少区间去表示。

例如，如果 `A = [0, 1, 2, 3, 4, 5, 6]` 是给定的循环数组，我们可以表示子段 `[2, 3, 4]` 为单区间 $[2, 4]$；如果我们希望表示子段 `[5, 6, 0, 1]`，那就是双区间 $[5, 6], [0, 1]$。

使用 Kadane 算法，我们知道如何计算一个单区间子段的最大值，所以剩下的问题是双区间子段。

考虑区间为 $[0, i], [j, A\text{.length} - 1]$。计算第 $i$ 个参数，对于固定 $i$ 两区间子串的最大值。计算 $[0, i]$ 的和很简单，考虑，

$$
T_j = A[j] + A[j+1] + \cdots + A[A\text{.length} - 1]
$$

和，

$$
R_j = \max\limits_{k \geq j} T_k
$$

所以期望的第 $i$ 个候选结果为：

$$
(A[0] + A[1] + \cdots + A[i]) + R_{i+2}
$$

由于我们可以限行时间计算 $T_j$ 和 $R_j$，结果是显然的。

```Java []
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int N = A.length;

        int ans = A[0], cur = A[0];
        for (int i = 1; i < N; ++i) {
            cur = A[i] + Math.max(cur, 0);
            ans = Math.max(ans, cur);
        }

        // ans is the answer for 1-interval subarrays.
        // Now, let's consider all 2-interval subarrays.
        // For each i, we want to know
        // the maximum of sum(A[j:]) with j >= i+2

        // rightsums[i] = A[i] + A[i+1] + ... + A[N-1]
        int[] rightsums = new int[N];
        rightsums[N-1] = A[N-1];
        for (int i = N-2; i >= 0; --i)
            rightsums[i] = rightsums[i+1] + A[i];

        // maxright[i] = max_{j >= i} rightsums[j]
        int[] maxright = new int[N];
        maxright[N-1] = A[N-1];
        for (int i = N-2; i >= 0; --i)
            maxright[i] = Math.max(maxright[i+1], rightsums[i]);

        int leftsum = 0;
        for (int i = 0; i < N-2; ++i) {
            leftsum += A[i];
            ans = Math.max(ans, leftsum + maxright[i+2]);
        }

        return ans;
    }
}
```

```Python []
class Solution(object):
    def maxSubarraySumCircular(self, A):
        N = len(A)

        ans = cur = None
        for x in A:
            cur = x + max(cur, 0)
            ans = max(ans, cur)

        # ans is the answer for 1-interval subarrays.
        # Now, let's consider all 2-interval subarrays.
        # For each i, we want to know
        # the maximum of sum(A[j:]) with j >= i+2

        # rightsums[i] = sum(A[i:])
        rightsums = [None] * N
        rightsums[-1] = A[-1]
        for i in xrange(N-2, -1, -1):
            rightsums[i] = rightsums[i+1] + A[i]

        # maxright[i] = max_{j >= i} rightsums[j]
        maxright = [None] * N
        maxright[-1] = rightsums[-1]
        for i in xrange(N-2, -1, -1):
            maxright[i] = max(maxright[i+1], rightsums[i])

        leftsum = 0
        for i in xrange(N-2):
            leftsum += A[i]
            ans = max(ans, leftsum + maxright[i+2])
        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(N)$。

#### 方法 2：前缀和 + 单调队列

**想法**

首先，我们可以在一个定长数组上完成这个问题。

我们可以认为循环数组 `A` 的任意子段，一定是定长数组 `A+A` 的任一个子段。

例如，对于循环数组 `A = [0,1,2,3,4,5]`，那么它的子段 `[4,5,0,1]` 一定也是定长数组 `[0,1,2,3,4,5,0,1,2,3,4,5]` 的子段。令 `B = A + A` 就是这个定长数组。

假定 $N = A\text{.length}$，考虑前缀和

$$
P_k = B[0] + B[1] + \cdots + B[k-1]
$$

然后，考虑最大的 $P_j - P_i$ 其中 $j - i \leq N$。

考虑第 $j$ 个候选答案：对于固定 $j$ 的最优结果 $P_j - P_i$。我们希望一个 $i$ 使得 $P_i$ 尽量小 并且满足 $j - N \leq i < j$，称对于第 $j$  个候选答案的的*最优 $i$*。我们可以用优先队列实现它。

**算法**

迭代 $j$，每次计算第 $j$ 个候选答案。我们维护一个 `queue` 保存可能的最优 $i$。

核心想法是如果 $i_1 < i_2$ 且 $P_{i_1} \geq P_{i_2}$，那么就不再需要考虑 $i_1$。

查看代码了解更多实现细节。

```Java []
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int N = A.length;

        // Compute P[j] = B[0] + B[1] + ... + B[j-1]
        // for fixed array B = A+A
        int[] P = new int[2*N+1];
        for (int i = 0; i < 2*N; ++i)
            P[i+1] = P[i] + A[i % N];

        // Want largest P[j] - P[i] with 1 <= j-i <= N
        // For each j, want smallest P[i] with i >= j-N
        int ans = A[0];
        // deque: i's, increasing by P[i]
        Deque<Integer> deque = new ArrayDeque();
        deque.offer(0);

        for (int j = 1; j <= 2*N; ++j) {
            // If the smallest i is too small, remove it.
            if (deque.peekFirst() < j-N)
                deque.pollFirst();

            // The optimal i is deque[0], for cand. answer P[j] - P[i].
            ans = Math.max(ans, P[j] - P[deque.peekFirst()]);

            // Remove any i1's with P[i2] <= P[i1].
            while (!deque.isEmpty() && P[j] <= P[deque.peekLast()])
                deque.pollLast();

            deque.offerLast(j);
        }

        return ans;
    }
}
```

```Python []
class Solution(object):
    def maxSubarraySumCircular(self, A):
        N = len(A)

        # Compute P[j] = sum(B[:j]) for the fixed array B = A+A
        P = [0]
        for _ in xrange(2):
            for x in A:
                P.append(P[-1] + x)

        # Want largest P[j] - P[i] with 1 <= j-i <= N
        # For each j, want smallest P[i] with i >= j-N
        ans = A[0]
        deque = collections.deque([0]) # i's, increasing by P[i]
        for j in xrange(1, len(P)):
            # If the smallest i is too small, remove it.
            if deque[0] < j-N:
                deque.popleft()

            # The optimal i is deque[0], for cand. answer P[j] - P[i].
            ans = max(ans, P[j] - P[deque[0]])

            # Remove any i1's with P[i2] <= P[i1].
            while deque and P[j] <= P[deque[-1]]:
                deque.pop()

            deque.append(j)

        return ans
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(N)$。


#### 方法 3：Kadane 算法（符号变种）

**想法和算法**

如方法 1 所示，一个循环数组的子段可以分成*单区间*子段和*双区间*子段。

使用 Kadane 算法 `kadane` 找到非空最大子段和，单区间子段的结果是 `kadane(A)`。

令 $N = A.\text{length}$。对于双区间子段，如：

$$
(A_0 + A_1 + \cdots + A_i) + (A_j + A_{j+1} + \cdots + A_{N - 1})
$$

我们可以写成：

$$
(\sum_{k=0}^{N-1} A_k) - (A_{i+1} + A_{i+2} + \cdots + A_{j-1})
$$

对于双区间子段，令 $B$ 是数组 $A$ 所有元素乘以 $-1$ 的结果。那么双区间子段的结果就是 $\text{sum}(A) + \text{kadane}(B)$。

但是，这并不是完全正确的，如果我们选择了 $B$ 的完整数组，双区间子段 $[0, i] + [j, N-1]$ 为空。

我们可以做出如下补救：做 Kadane 算法两次，一次去掉 $B$  的第一个元素，一次去掉 $B$ 的最后一个元素。

```Java []
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int S = 0;  // S = sum(A)
        for (int x: A)
            S += x;

        int ans1 = kadane(A, 0, A.length-1, 1);
        int ans2 = S + kadane(A, 1, A.length-1, -1);
        int ans3 = S + kadane(A, 0, A.length-2, -1);
        return Math.max(ans1, Math.max(ans2, ans3));
    }

    public int kadane(int[] A, int i, int j, int sign) {
        // The maximum non-empty subarray for array
        // [sign * A[i], sign * A[i+1], ..., sign * A[j]]
        int ans = Integer.MIN_VALUE;
        int cur = Integer.MIN_VALUE;
        for (int k = i; k <= j; ++k) {
            cur = sign * A[k] + Math.max(cur, 0);
            ans = Math.max(ans, cur);
        }
        return ans;
    }
}
```

```Python []
class Solution(object):
    def maxSubarraySumCircular(self, A):
        def kadane(gen):
            # Maximum non-empty subarray sum
            ans = cur = None
            for x in gen:
                cur = x + max(cur, 0)
                ans = max(ans, cur)
            return ans

        S = sum(A)
        ans1 = kadane(iter(A))
        ans2 = S + kadane(-A[i] for i in xrange(1, len(A)))
        ans3 = S + kadane(-A[i] for i in xrange(len(A) - 1))
        return max(ans1, ans2, ans3)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(1)$。

#### 方法 4：Kadane 算法（最小值变种）

**想法和算法**

如方法 3，循环数组的子段可以分成*单区间*子段（直接使用 Kanade 算法）和*双区间*子段.

我们可以改进 Kadane 算法，用 `min` 代替 `max`。所有 Kadane 算法的解释依然相同，但是算法可以让我们找到最小子段和。

对于双区间子段形如 $(\sum_{k=0}^{N-1} A_k) - (\sum_{k=i+1}^{j-1} A_k)$，我们可以使用 `kadane-min` 算法最小化”内部“ $(\sum_{k=i+1}^{j-1} A_k)$ 和。

同理，由于区间 $[i+1, j-1]$ 必须非空，我们将搜索分成 `A[1:]` 和 `A[:-1]` 两个区间考虑。


```Java []
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        // S: sum of A
        int S = 0;
        for (int x: A)
            S += x;

        // ans1: answer for one-interval subarray
        int ans1 = Integer.MIN_VALUE;
        int cur = Integer.MIN_VALUE;
        for (int x: A) {
            cur = x + Math.max(cur, 0);
            ans1 = Math.max(ans1, cur);
        }

        // ans2: answer for two-interval subarray, interior in A[1:]
        int ans2 = Integer.MAX_VALUE;
        cur = Integer.MAX_VALUE;
        for (int i = 1; i < A.length; ++i) {
            cur = A[i] + Math.min(cur, 0);
            ans2 = Math.min(ans2, cur);
        }
        ans2 = S - ans2;

        // ans3: answer for two-interval subarray, interior in A[:-1]
        int ans3 = Integer.MAX_VALUE;
        cur = Integer.MAX_VALUE;
        for (int i = 0; i < A.length - 1; ++i) {
            cur = A[i] + Math.min(cur, 0);
            ans3 = Math.min(ans3, cur);
        }

        return Math.max(ans1, Math.max(ans2, ans3));
    }
}
```

```Python []
class Solution(object):
    def maxSubarraySumCircular(self, A):
        # ans1: answer for one-interval subarray
        ans1 = cur = None
        for x in A:
            cur = x + max(cur, 0)
            ans1 = max(ans1, cur)

        # ans2: answer for two-interval subarray, interior in A[1:]
        ans2 = cur = float('inf')
        for i in xrange(1, len(A)):
            cur = A[i] + min(cur, 0)
            ans2 = min(ans2, cur)
        ans2 = sum(A) - ans2

        # ans3: answer for two-interval subarray, interior in A[:-1]
        ans3 = cur = float('inf')
        for i in xrange(len(A)-1):
            cur = A[i] + min(cur, 0)
            ans3 = min(ans3, cur)
        ans3 = sum(A) - ans3
        
        return max(ans1, ans2, ans3)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(1)$。