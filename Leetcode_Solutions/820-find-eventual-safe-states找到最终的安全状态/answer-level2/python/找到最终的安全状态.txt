#### 方法一：拓扑排序

**分析**

对于一个节点 `u`，如果我们从 `u` 开始任意行走能够走到一个环里，那么 `u` 就不是一个安全的节点。换句话说，`u` 是一个安全的节点，当且仅当 `u` 直接相连的节点（`u` 的出边相连的那些节点）都是安全的节点。

因此我们可以首先考虑没有任何出边的节点，它们一定都是安全的。随后我们再考虑仅与这些节点直接相连的节点，它们也一定是安全的，以此类推。这样我们可以将所有的边全部反向，首先所有没有任何入边的节点都是安全的，我们把这些节点全部移除。随后新的图中没有任何入边的节点都是安全的，以此类推。我们发现这种做法实际上就是对图进行拓扑排序。

**算法**

我们将所有的边反向，得到反向图 `rgraph`，随后将 `rgraph` 中所有没有入边的节点加入队列中。每一次我们取出队列中的一个节点 `u`，将它从图中删除，如果此时某个节点 `v` 存在从 `u` 到 `v` 的一条边，并且在删掉了这条边后，`v` 变成了没有入边的节点，那么就把 `v` 加入队列。以此类推，直到队列为空。最后所有加入过队列的节点即为安全的节点。

```Java [sol1]
class Solution {
    public List<Integer> eventualSafeNodes(int[][] G) {
        int N = G.length;
        boolean[] safe = new boolean[N];

        List<Set<Integer>> graph = new ArrayList();
        List<Set<Integer>> rgraph = new ArrayList();
        for (int i = 0; i < N; ++i) {
            graph.add(new HashSet());
            rgraph.add(new HashSet());
        }

        Queue<Integer> queue = new LinkedList();

        for (int i = 0; i < N; ++i) {
            if (G[i].length == 0)
                queue.offer(i);
            for (int j: G[i]) {
                graph.get(i).add(j);
                rgraph.get(j).add(i);
            }
        }

        while (!queue.isEmpty()) {
            int j = queue.poll();
            safe[j] = true;
            for (int i: rgraph.get(j)) {
                graph.get(i).remove(j);
                if (graph.get(i).isEmpty())
                    queue.offer(i);
            }
        }

        List<Integer> ans = new ArrayList();
        for (int i = 0; i < N; ++i) if (safe[i])
            ans.add(i);

        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def eventualSafeNodes(self, graph):
        N = len(graph)
        safe = [False] * N

        graph = map(set, graph)
        rgraph = [set() for _ in xrange(N)]
        q = collections.deque()

        for i, js in enumerate(graph):
            if not js:
                q.append(i)
            for j in js:
                rgraph[j].add(i)

        while q:
            j = q.popleft()
            safe[j] = True
            for i in rgraph[j]:
                graph[i].remove(j)
                if len(graph[i]) == 0:
                    q.append(i)

        return [i for i, v in enumerate(safe) if v]
```

**复杂度分析**

* 时间复杂度：$O(N + E)$，其中 $N$ 是图中的节点数，$E$ 是图中的边数。

* 空间复杂度：$O(N)$。


#### 方法二：深度优先搜索

我们同样可以使用深度优先搜索的方法判断图中的每个节点是否能走到环中。对于每个节点，我们有三种染色的方法：白色表示该节点还没有被访问过；灰色表示该节点在栈中（这一轮搜索中被访问过）或者在环中；黑色表示该节点的所有相连的节点都被访问过，且该节点不在环中。

当我们第一次访问一个节点时，我们把它从白色变成灰色，并继续搜索与它相连的节点。如果在搜索过程中我们遇到一个灰色的节点，那么说明找到了一个环，此时退出搜索，所有的灰色节点保持不变（即从任意一个灰色节点开始，都能走到环中），如果搜索过程中，我们没有遇到灰色的节点，那么在回溯到当前节点时，我们把它从灰色变成黑色，即表示它是一个安全的节点。

```Java [sol2]
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int N = graph.length;
        int[] color = new int[N];
        List<Integer> ans = new ArrayList();

        for (int i = 0; i < N; ++i)
            if (dfs(i, color, graph))
                ans.add(i);
        return ans;
    }

    // colors: WHITE 0, GRAY 1, BLACK 2;
    public boolean dfs(int node, int[] color, int[][] graph) {
        if (color[node] > 0)
            return color[node] == 2;

        color[node] = 1;
        for (int nei: graph[node]) {
            if (color[node] == 2)
                continue;
            if (color[nei] == 1 || !dfs(nei, color, graph))
                return false;
        }

        color[node] = 2;
        return true;
    }
}
```

```Python [sol2]
class Solution(object):
    def eventualSafeNodes(self, graph):
        WHITE, GRAY, BLACK = 0, 1, 2
        color = collections.defaultdict(int)

        def dfs(node):
            if color[node] != white:
                return color[node] == BLACK

            color[node] = GRAY
            for nei in graph[node]:
                if color[nei] == BLACK:
                    continue
                if color[nei] == GRAY or not dfs(nei):
                    return False
            color[node] = BLACK
            return True

        return filter(dfs, range(len(graph)))
```

**复杂度分析**

* 时间复杂度：$O(N + E)$，其中 $N$ 是图中的节点数，$E$ 是图中的边数。

* 空间复杂度：$O(N)$。