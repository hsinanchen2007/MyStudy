#### 方法一：滑动窗口

**分析**

我们用数组 `P` 表示数组 `A` 的前缀和，即 `P[i] = A[0] + A[1] + ... + A[i - 1]`。我们需要找到 `x` 和 `y`，使得 `P[y] - P[x] >= K` 且 `y - x` 最小。

我们用 `opt(y)` 表示对于固定的 `y`，最大的满足 `P[x] <= P[y] - K` 的 `x`，这样所有 `y - opt(y)` 中的最小值即为答案。我们可以发现两条性质：

* 如果 `x1 < x2` 且 `P[x2] <= P[x1]`，那么 `opt(y)` 的值不可能为 `x1`，这是因为 `x2` 比 `x1` 大，并且如果 `x1` 满足了 `P[x1] <= P[y] - K`，那么 `P[x2] <= P[x1] <= P[y] - K`，即 `x2` 同样满足 `P[x2] <= P[y] - K`。

* 如果 `opt(y1)` 的值为 `x`，那么我们以后就不用再考虑 `x` 了。这是因为如果有 `y2 > y1` 且 `opt(y2)` 的值也为 `x`，但此时 `y2 - x` 显然大于 `y1 - x`，不会作为所有 `y - opt(y)` 中的最小值。

**算法**

我们维护一个关于前缀和数组 `P` 的单调队列，它是一个双端队列（deque），其中存放了下标 `x`：`x0, x1, ...` 满足 `P[x0], P[x1], ...` 单调递增。这是为了满足性质一。

当我们遇到了一个新的下标 `y` 时，我们会在队尾移除若干元素，直到 `P[x0], P[x1], ..., P[y]` 单调递增。这同样是为了满足性质一。

同时，我们会在队首也移除若干元素，如果 `P[y] >= P[x0] + K`，则将队首元素移除，直到该不等式不满足。这是为了满足性质二。

```Java [sol1]
class Solution {
    public int shortestSubarray(int[] A, int K) {
        int N = A.length;
        long[] P = new long[N+1];
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + (long) A[i];

        // Want smallest y-x with P[y] - P[x] >= K
        int ans = N+1; // N+1 is impossible
        Deque<Integer> monoq = new LinkedList(); //opt(y) candidates, as indices of P

        for (int y = 0; y < P.length; ++y) {
            // Want opt(y) = largest x with P[x] <= P[y] - K;
            while (!monoq.isEmpty() && P[y] <= P[monoq.getLast()])
                monoq.removeLast();
            while (!monoq.isEmpty() && P[y] >= P[monoq.getFirst()] + K)
                ans = Math.min(ans, y - monoq.removeFirst());

            monoq.addLast(y);
        }

        return ans < N+1 ? ans : -1;
    }
}
```

```Python [sol1]
class Solution(object):
    def shortestSubarray(self, A, K):
        N = len(A)
        P = [0]
        for x in A:
            P.append(P[-1] + x)

        #Want smallest y-x with Py - Px >= K
        ans = N+1 # N+1 is impossible
        monoq = collections.deque() #opt(y) candidates, represented as indices of P
        for y, Py in enumerate(P):
            #Want opt(y) = largest x with Px <= Py - K
            while monoq and Py <= P[monoq[-1]]:
                monoq.pop()

            while monoq and Py - P[monoq[0]] >= K:
                ans = min(ans, y - monoq.popleft())

            monoq.append(y)

        return ans if ans < N+1 else -1
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(N)$。