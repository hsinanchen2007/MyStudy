#### 方法 1：前驱 / 后继数组

**想法**

考虑所有满足 `A[j]` 为最右且最小的元素的子序列个数 `#(j)`，那么结果就是 `sum #(j) * A[j]`。（我们必须考虑*最右*这样才可以构造互不相交的子序列，否则会出现多次计算，因为一个数组的最小值可能不唯一。）

这就变成考虑最小的下标 `i <= j` 满足 `A[i], A[i+1], ..., A[j]` 都 `>= A[j]` 以及最大的下标 `k >= j` 满足 `A[j+1], A[j+2], ..., A[k]` 都 `> A[j]`。

**算法**

例如，`A = [10, 3, 4, 5, _3_, 2, 3, 10]` 我们需要计算 `#(j = 4)`，也就是第二个数字 `3` ，被标记的那个，我们会发现 `i = 1` 和 `k = 5`。

由此，实际的总数为 `#(j) = (j - i + 1) * (k - j + 1)` 其中 `j - i + 1` 选择子序列的左端点 `i, i+1, ..., j`，而 `k - j + 1` 选择子序列的右端点 `j, j+1, ..., k`。

对于每个询问（也就是根据 `j` 计算出 `(i, k)`）是一个经典问题，可以用一个栈来解决。我们会重点解答如何找到 `i`，而找到 `k` 的做法与之类似。

**构造前序数组**

做法是维护一个`栈`，`A` 的单调下降子序列（事实上是维护一个 `A` 的下标索引）。对于下一个询问，候选界限为 `i* - 1`，其中 `A[i*]` 以递增顺序存储。

现在考虑升序下标 `j` ，我们可以按照 `i*` 递减顺序移走所有 `A[i*] <= A[j]`。

例如，假设 `A = [10, 5, 3, 7, 0, 4, 5, 2, 1, _8_]` 那么当考虑 `j = 9` `(A[j] = 8)`，我们有一个存储边界的栈类似于 `[-1, 0, 3, 6]`（代表 `A[i*] = -inf, 10, 7, 5`）。我们从栈中弹出 `6` 和 `3` 因为 `5 <= 8` 且 `7 <= 8`，因此得到询问的边界为 `i* - 1 = 0`。

注意这个过程线性的，因为只进行了线性次的入栈和出栈。

这种办法很难想到，但在很多地方都有用到，所以很值得学习其细节。


```Java []
class Solution {
    public int sumSubarrayMins(int[] A) {
        int MOD = 1_000_000_007;
        int N = A.length;

        // prev has i* - 1 in increasing order of A[i* - 1]
        // where i* is the answer to query j
        Stack<Integer> stack = new Stack();
        int[] prev = new int[N];
        for (int i = 0; i < N; ++i) {
            while (!stack.isEmpty() && A[i] <= A[stack.peek()])
                stack.pop();
            prev[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        // next has k* + 1 in increasing order of A[k* + 1]
        // where k* is the answer to query j
        stack = new Stack();
        int[] next = new int[N];
        for (int k = N-1; k >= 0; --k) {
            while (!stack.isEmpty() && A[k] < A[stack.peek()])
                stack.pop();
            next[k] = stack.isEmpty() ? N : stack.peek();
            stack.push(k);
        }

        // Use prev/next array to count answer
        long ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += (i - prev[i]) * (next[i] - i) % MOD * A[i] % MOD;
            ans %= MOD;
        }
        return (int) ans;

    }
}
```

```Python []
class Solution(object):
    def sumSubarrayMins(self, A):
        MOD = 10**9 + 7
        N = len(A)

        # prev has i* - 1 in increasing order of A[i* - 1]
        # where i* is the answer to query j
        stack = []
        prev = [None] * N
        for i in xrange(N):
            while stack and A[i] <= A[stack[-1]]:
                stack.pop()
            prev[i] = stack[-1] if stack else -1
            stack.append(i)

        # next has k* + 1 in increasing order of A[k* + 1]
        # where k* is the answer to query j
        stack = []
        next_ = [None] * N
        for k in xrange(N-1, -1, -1):
            while stack and A[k] < A[stack[-1]]:
                stack.pop()
            next_[k] = stack[-1] if stack else N
            stack.append(k)

        # Use prev/next array to count answer
        return sum((i - prev[i]) * (next_[i] - i) * A[i]
                   for i in xrange(N)) % MOD
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(N)$。

#### 方法 2：维护最小值栈

**想法**

对于每个 `j`，考虑所有子序列 `[i, j]` 的最小值。想法是每当我们增加 `j`，这些最小值可能会有关联，事实上，`min(A[i:j+1]) = min(A[i:j], A[j+1])`。

模拟数组 `A = [1,7,5,2,4,3,9]`，当 `j = 6` 事所有子序列 `[i, j]` 的最小值为 `B = [1,2,2,2,3,3,9]`，可以发现重要点是 `i = 0, i = 3, i = 5, i = 6` ，分别是从 `j` 开始向左移动遇到的最小值的位置。

**算法**

维护关于重要点的编码 `B`，对于上面提到的 `(A, j)` 维护 `stack = [(val=1, count=1), (val=2, count=3), (val=3, count=2), (val=9, count=1)]`，这表示最小值的编码为 `B = [1,2,2,2,3,3,9]`。对于每个 `j` 我们需要计算 `sum(B)`。

当我们增加 `j`，我们用最新的元素 `(val=x, count=1)` 更新栈。弹出所有值 `>= x` 的元素，因为当前子序列 `[i, j]` 的最小值将是 `A[j]` 而不是之前的值。

最后，结果是栈元素的点积 $\sum\limits_{e\text{ } \in \text{ stack}} e\text{.val} * e\text{.count}$，我们同时会用变量 `dot` 来维护。

```Java []
class Solution {
    public int sumSubarrayMins(int[] A) {
        int MOD = 1_000_000_007;

        Stack<RepInteger> stack = new Stack();
        int ans = 0, dot = 0;
        for (int j = 0; j < A.length; ++j) {
            // Add all answers for subarrays [i, j], i <= j
            int count = 1;
            while (!stack.isEmpty() && stack.peek().val >= A[j]) {
                RepInteger node = stack.pop();
                count += node.count;
                dot -= node.val * node.count;
            }
            stack.push(new RepInteger(A[j], count));
            dot += A[j] * count;
            ans += dot;
            ans %= MOD;
        }

        return ans;
    }
}

class RepInteger {
    int val, count;
    RepInteger(int v, int c) {
        val = v;
        count = c;
    }
}
```

```Python []
class Solution(object):
    def sumSubarrayMins(self, A):
        MOD = 10**9 + 7

        stack = []
        ans = dot = 0
        for j, y in enumerate(A):
            # Add all answers for subarrays [i, j], i <= j
            count = 1
            while stack and stack[-1][0] >= y:
                x, c = stack.pop()
                count += c
                dot -= x * c

            stack.append((y, count))
            dot += y * count
            ans += dot
        return ans % MOD
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(N)$。
