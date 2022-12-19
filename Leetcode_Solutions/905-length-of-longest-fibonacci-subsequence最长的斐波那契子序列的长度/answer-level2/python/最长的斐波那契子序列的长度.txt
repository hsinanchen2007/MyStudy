#### 方法一：使用 Set 的暴力法

**思路**

每个斐波那契式的子序列都依靠两个相邻项来确定下一个预期项。例如，对于 `2, 5`，我们所期望的子序列必定以 `7, 12, 19, 31` 等继续。

我们可以使用 `Set` 结构来快速确定下一项是否在数组 `A` 中。由于这些项的值以指数形式增长，最大值 $\leq 10^9$ 的斐波那契式的子序列最多有 43 项。

**算法**

对于每个起始对 `A[i], A[j]`，我们保持下一个预期值 `y = A[i] + A[j]` 和此前看到的最大值 `x = A[j]`。如果 `y` 在数组中，我们可以更新这些值 `(x, y) -> (y, x+y)`。

此外，由于子序列的长度大于等于 3 只能是斐波那契式的，所以我们必须在最后进行检查 `ans >= 3 ? ans : 0`。

```cpp [RGECz9nf-C++]
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int N = A.size();
        unordered_set<int> S(A.begin(), A.end());

        int ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j) {
                /* With the starting pair (A[i], A[j]),
                 * y represents the future expected value in
                 * the fibonacci subsequence, and x represents
                 * the most current value found. */
                int x = A[j], y = A[i] + A[j];
                int length = 2;
                while (S.find(y) != S.end()) {
                    int z = x + y;
                    x = y;
                    y = z;
                    ans = max(ans, ++length);
                }
            }

        return ans >= 3 ? ans : 0;
    }
};
```
```java [RGECz9nf-Java]
class Solution {
    public int lenLongestFibSubseq(int[] A) {
        int N = A.length;
        Set<Integer> S = new HashSet();
        for (int x: A) S.add(x);

        int ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j) {
                /* With the starting pair (A[i], A[j]),
                 * y represents the future expected value in
                 * the fibonacci subsequence, and x represents
                 * the most current value found. */
                int x = A[j], y = A[i] + A[j];
                int length = 2;
                while (S.contains(y)) {
                    // x, y -> y, x+y
                    int tmp = y;
                    y += x;
                    x = tmp;
                    ans = Math.max(ans, ++length);
                }
            }

        return ans >= 3 ? ans : 0;
    }
}
```
```python [RGECz9nf-Python]
class Solution(object):
    def lenLongestFibSubseq(self, A):
        S = set(A)
        ans = 0
        for i in xrange(len(A)):
            for j in xrange(i+1, len(A)):
                """
                With the starting pair (A[i], A[j]),
                y represents the future expected value in
                the fibonacci subsequence, and x represents
                the most current value found.
                """
                x, y = A[j], A[i] + A[j]
                length = 2
                while y in S:
                    x, y = y, x + y
                    length += 1
                ans = max(ans, length)
        return ans if ans >= 3 else 0
```


**复杂度分析**

* 时间复杂度：$O(N^2 \log M)$，其中 $N$ 是 `A` 的长度，$M$ 是 `A` 中的最大值。
* 空间复杂度：$O(N)$，集合（set）`S` 使用的空间。






---
#### 方法二：动态规划

**思路**

将斐波那契式的子序列中的两个连续项 `A[i], A[j]` 视为单个结点 `(i, j)`，整个子序列是这些连续结点之间的路径。

例如，对于斐波那契式的子序列 `(A[1] = 2, A[2] = 3, A[4] = 5, A[7] = 8, A[10] = 13)`，结点之间的路径为 `(1, 2) <-> (2, 4) <-> (4, 7) <-> (7, 10)`。

这样做的动机是，只有当 `A[i] + A[j] == A[k]` 时，两结点 `(i, j)` 和 `(j, k)` 才是连通的，我们需要这些信息才能知道这一连通。现在我们得到一个类似于 *最长上升子序列* 的问题。

**算法**

设 `longest[i, j]` 是结束在 `[i, j]` 的最长路径。那么 如果 `(i, j)` 和 `(j, k)` 是连通的， `longest[j, k] = longest[i, j] + 1`。

由于 `i` 由 `A.index(A[k] - A[j])` 唯一确定，所以这是有效的：我们在 `i` 潜在时检查每组 `j < k`，并相应地更新 `longest[j, k]`。

```cpp [UNSjQ9SB-C++]
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int N = A.size();
        unordered_map<int, int> index;
        for (int i = 0; i < N; ++i)
            index[A[i]] = i;

        unordered_map<int, int> longest;
        int ans = 0;
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < k; ++j) {
                if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
                    int i = index[A[k] - A[j]];
                    longest[j * N + k] = longest[i * N + j] + 1;
                    ans = max(ans, longest[j * N + k] + 2);
                }
            }

        return ans >= 3 ? ans : 0;
    }
};
```
```java [UNSjQ9SB-Java]
class Solution {
    public int lenLongestFibSubseq(int[] A) {
        int N = A.length;
        Map<Integer, Integer> index = new HashMap();
        for (int i = 0; i < N; ++i)
            index.put(A[i], i);

        Map<Integer, Integer> longest = new HashMap();
        int ans = 0;

        for (int k = 0; k < N; ++k)
            for (int j = 0; j < k; ++j) {
                int i = index.getOrDefault(A[k] - A[j], -1);
                if (i >= 0 && i < j) {
                    // Encoding tuple (i, j) as integer (i * N + j)
                    int cand = longest.getOrDefault(i * N + j, 2) + 1;
                    longest.put(j * N + k, cand);
                    ans = Math.max(ans, cand);
                }
            }

        return ans >= 3 ? ans : 0;
    }
}
```
```python [UNSjQ9SB-Python]
class Solution(object):
    def lenLongestFibSubseq(self, A):
        index = {x: i for i, x in enumerate(A)}
        longest = collections.defaultdict(lambda: 2)

        ans = 0
        for k, z in enumerate(A):
            for j in xrange(k):
                i = index.get(z - A[j], None)
                if i is not None and i < j:
                    cand = longest[j, k] = longest[i, j] + 1
                    ans = max(ans, cand)

        return ans if ans >= 3 else 0
```


**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(N \log M)$，其中 $M$ 是 `A` 中最大的元素。我们可以证明子序列中的元素数量是有限的（复杂度 $O(\log \frac{M}{a})$，其中 $a$ 是子序列中最小的元素）。