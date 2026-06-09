#### 方法一：深度优先搜索 + 子树计数

**分析**

我们用 `ans` 数组表示答案，其中 `ans[x]` 表示节点 `x` 距离树中其它节点的距离之和。直接对于每个 `x` 并通过搜索的方式计算 `ans[x]` 的总时间复杂度是 $O(N^2)$，其中 $N$ 是树中的节点个数，这会超出时间限制。因此我们需要找到 `ans[x]` 之间的关系，减少重复搜索。

我们设两个节点为 `x` 和 `y`，它们在树中有一条边直接相连。如果将这条边删除，会得到一棵以 `x` 为根节点的子树 `X` 以及一棵以 `y` 为根节点的子树 `Y`。


如上图所示，`ans[x]` 的值由三部分组成。第一部分是子树 `X` 中所有节点到 `x` 的总距离，记为 `x@X`；第二部分是子树 `Y` 中所有节点到 `y` 的距离，记为 `y@Y`；第三部分是子树 `Y` 中所有节点从 `y` 到达 `x` 的总距离，它等于 `Y` 中的节点个数，记为 `#(Y)`。将这三部分进行累加，得到 `ans[x] = x@X + y@Y + #(Y)`。同理我们有 `ans[y] = y@Y + x@X + #(X)`，因此 `ans[x] - ans[y] = #(Y) - #(X)`。

**算法**

我们指定 `0` 号节点为树的根节点，对于每个节点 `node`，设 `S(node)` 为以 `node` 为根的子树（包括 `node` 本身）。我们用 `count[node]` 表示 `S(node)` 中节点的个数，并用 `stsum[node]`（subtree sum，子树和）表示 `S(node)` 中所有节点到 `node` 的总距离。

我们可以使用深度优先搜索计算出所有的 `count` 和 `stsum`。对于节点 `node`，我们计算出它的每个子节点的 `count` 和 `stsum` 值，那么就有 `count[node] = sum(count[child]) + 1` 以及 `stsum[node] = sum(stsum[child] + count[child])`，其中 `sum()` 表示对子节点进行累加。

当所有节点计算完之后，对于根节点，它的答案 `ans[root]` 即为 `stsum[root]`。我们再进行一次深度优先搜索，并且根据上文推出的两个相邻节点 `ans` 值的关系，得到其它节点的 `ans` 值，即：对于节点 `parent`（父节点）以及节点 `child`（子节点），有 `ans[child] = ans[parent] - count[child] + (N - count[child])`，与上文的 `ans[y] = ans[x] - #(Y) + #(X)` 相对应。


当第二次深度优先搜索结束后，我们就得到了所有节点对应的 `ans` 值。

```Java [sol1]
class Solution {
    int[] ans, count;
    List<Set<Integer>> graph;
    int N;
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        this.N = N;
        graph = new ArrayList<Set<Integer>>();
        ans = new int[N];
        count = new int[N];
        Arrays.fill(count, 1);

        for (int i = 0; i < N; ++i)
            graph.add(new HashSet<Integer>());
        for (int[] edge: edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }

    public void dfs(int node, int parent) {
        for (int child: graph.get(node))
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
    }

    public void dfs2(int node, int parent) {
        for (int child: graph.get(node))
            if (child != parent) {
                ans[child] = ans[node] - count[child] + N - count[child];
                dfs2(child, node);
            }
    }
}
```

```Python [sol1]
class Solution(object):
    def sumOfDistancesInTree(self, N, edges):
        graph = collections.defaultdict(set)
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)

        count = [1] * N
        ans = [0] * N
        def dfs(node = 0, parent = None):
            for child in graph[node]:
                if child != parent:
                    dfs(child, node)
                    count[node] += count[child]
                    ans[node] += ans[child] + count[child]

        def dfs2(node = 0, parent = None):
            for child in graph[node]:
                if child != parent:
                    ans[child] = ans[node] - count[child] + N - count[child]
                    dfs2(child, node)

        dfs()
        dfs2()
        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是树中的节点个数。

* 空间复杂度：$O(N)$。