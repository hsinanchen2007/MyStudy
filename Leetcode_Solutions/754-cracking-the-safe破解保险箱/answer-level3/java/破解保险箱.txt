#### 方法一：Hierholzer 算法

Hierholzer 算法可以在一个欧拉图中找出欧拉回路。

我们将所有的 `k - 1` 位数作为节点，共有 $k^{n - 1}$ 个节点。每个节点有 `k` 条入边和出边，如果当前节点对应的数为 $a_1a_2\cdots a_k$，那么它的第 `k` 条出边连向 $a_2\cdots a_k k$，第 `k` 条入边由 $k a_1a_2\cdots a_{k-1}$ 连向它，这样我们从一个节点顺着一条边（编号为 `x`）走到另一个节点，就相当于输入了数字 `x`。我们的目标是要经过所有的边，这是因为每一个节点以及它们的出边都对应了 `k` 个数，例如 `k = 4, n = 3` 时，节点分别为 `00, 01, 02, ..., 32, 33`，边分别为 `0, 1, 2, 3`，那么 `00` 和它的出边对应了 `000, 001, 002, 003`，`32` 和它的出边对应了 `320, 321, 322, 323`。一共有 $k^{n-1} * k = k^n$ 个数，即为所有可能的密码。

由于这个图的每个节点都有 `k` 条入边和出边，因此它一定存在一个欧拉回路，即可以从任意一个节点开始，一次性不重复地走完所有的边且回到该节点。因此我们可以用 Hierholzer 算法找出这条欧拉回路，设开始的节点对应的数位 `init`，欧拉回路中每条边的编号为 `l1, l2, l3, ...`，那么最终的字符串即为 `init l1 l2 l3 ...`。Hierholzer 算法如下：

* 我们从任意节点 `u` 开始，任意地经过未经过的边，直到我们“无路可走”。可以发现，我们最终一定会停在节点 `u`，这是因为所有节点的入度和出度都相等。

* 我们得到了一条从 `u` 开始到 `u` 结束的回路，这条回路上仍然有些节点有未经过的出边。我么从某个这样的节点 `v` 开始，把 `v` 看成 `u`，继续得到一条从 `v` 开始到 `v` 结束的回路，再嵌入之前的回路中，即 `u -> ... -> v -> ... -> u` 变为 `u -> ... -> v -> ... -> v -> ... -> u`。以此类推，直到没有未经过的边，此时我们就找到了一条欧拉回路。

```Python [sol1]
class Solution(object):
    def crackSafe(self, n, k):
        seen = set()
        ans = []
        def dfs(node):
            for x in map(str, range(k)):
                nei = node + x
                if nei not in seen:
                    seen.add(nei)
                    dfs(nei[1:])
                    ans.append(x)

        dfs("0" * (n-1))
        return "".join(ans) + "0" * (n-1)
```

```Java [sol1]
class Solution {
    Set<String> seen;
    StringBuilder ans;

    public String crackSafe(int n, int k) {
        if (n == 1 && k == 1) return "0";
        seen = new HashSet();
        ans = new StringBuilder();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n-1; ++i)
            sb.append("0");
        String start = sb.toString();

        dfs(start, k);
        ans.append(start);
        return new String(ans);
    }

    public void dfs(String node, int k) {
        for (int x = 0; x < k; ++x) {
            String nei = node + x;
            if (!seen.contains(nei)) {
                seen.add(nei);
                dfs(nei.substring(1), k);
                ans.append(x);
            }
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n * k^n)$。

* 空间复杂度：$O(n * k^n)$。