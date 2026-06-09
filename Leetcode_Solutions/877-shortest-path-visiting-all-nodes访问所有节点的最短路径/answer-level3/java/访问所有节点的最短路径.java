#### 方法一：广度优先搜索【通过】

**思路**

路径 `state` 表示当前节点和已访问节点的子集。此问题可以简化为 `state` 的最短路径问题，那么就可以使用广度优先搜索解决。

**算法**

`cover` 表示一条路径上访问过的节点集合，`head` 表示当前节点。在 `cover` 中使用比特位表示节点的访问情况，如果 `cover` 的第 `k` 个比特位是 1，表示该路径经过了第 `k` 个节点。

对当前 `state = (cover, head)` 使用广度优先搜索，从当前节点 `head` 出发到达每个邻接点 `child` 的新路径为 `(cover | (1 << child), child)`。

根据广度优先搜索可知，如果找到一个 `state` 包含了全部顶点，那么该 `state` 一定代表最短路径的长度。

```java [solution1-Java]
class Solution {
    public int shortestPathLength(int[][] graph) {
        int N = graph.length;
        Queue<State> queue = new LinkedList();
        int[][] dist = new int[1<<N][N];
        for (int[] row: dist) Arrays.fill(row, N*N);

        for (int x = 0; x < N; ++x) {
            queue.offer(new State(1<<x, x));
            dist[1 << x][x] = 0;
        }

        while (!queue.isEmpty()) {
            State node = queue.poll();
            int d = dist[node.cover][node.head];
            if (node.cover == (1<<N) - 1) return d;

            for (int child: graph[node.head]) {
                int cover2 = node.cover | (1 << child);
                if (d + 1 < dist[cover2][child]) {
                    dist[cover2][child] = d + 1;
                    queue.offer(new State(cover2, child));

                }
            }
        }

        throw null;
    }
}

class State {
    int cover, head;
    State(int c, int h) {
        cover = c;
        head = h;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def shortestPathLength(self, graph):
        N = len(graph)
        queue = collections.deque((1 << x, x) for x in xrange(N))
        dist = collections.defaultdict(lambda: N*N)
        for x in xrange(N): dist[1 << x, x] = 0

        while queue:
            cover, head = queue.popleft()
            d = dist[cover, head]
            if cover == 2**N - 1: return d
            for child in graph[head]:
                cover2 = cover | (1 << child)
                if d + 1 < dist[cover2, child]:
                    dist[cover2, child] = d + 1
                    queue.append((cover2, child))
```

**复杂度分析**

* 时间复杂度：$O(2^N * N)$。

* 空间复杂度：$O(2^N * N)$。


#### 方法二：动态规划【通过】

**思路**

路径 `state` 表示当前节点和已访问节点的子集。与*方法一*相同，从当前节点 `head` 出发到达每个邻接点 `child` 的新路径 `answer(cover, head)` 为 `min(1 + answer(cover | (1<<child), child)`。所有的 `state` 形成了一个 DAG（无环有向图），可以使用动态规划解决。

**算法**

`cover` 表示一条路径上访问过的节点集合，`head` 表示当前节点。`dist[cover][head]` 存储路径 `(cover, head)` 的长度。

每条路径 `(cover, head)` 下一个可能的节点 `next` 来自于 `head` 的邻接点集合 `graph[head]`。新路径 `cover2` 是在旧路径 `cover` 的基础上添加 `next` 节点。

每次添加新节点时，都按照松弛法（与布里姆算法中添加新节点步骤相似）更新路径长度。如果 `dist[cover2][next] > dist[cover][head] + 1`，则更新路径长度 `dist[cover2][next] = dist[cover][head] + 1`。

如果 `cover = cover2`，则需要在同一 `cover` 上再次执行松弛法，重新更新最短路径。

迭代 `cover = 0 .. (1<<N) - 1` 时，产生的每条新路径 `cover2 = cover | 1 << x` 都满足条件 `cover2 >= cover`。因此这也是拓扑排序，所有的路径形成了 DAG。

```java [solution2-Java]
class Solution {
    public int shortestPathLength(int[][] graph) {
        int N = graph.length;
        int dist[][] = new int[1 << N][N];
        for (int[] row: dist) Arrays.fill(row, N*N);
        for (int x = 0; x < N; ++x) dist[1<<x][x] = 0;

        for (int cover = 0; cover < 1 << N; ++cover) {
            boolean repeat = true;
            while (repeat) {
                repeat = false;
                for (int head = 0; head < N; ++head) {
                    int d = dist[cover][head];
                    for (int next: graph[head]) {
                        int cover2 = cover | (1 << next);
                        if (d + 1 < dist[cover2][next]) {
                            dist[cover2][next] = d+1;
                            if (cover == cover2) repeat = true;
                        }
                    }
                }
            }
        }

        int ans = N*N;
        for (int cand: dist[(1<<N) - 1])
            ans = Math.min(cand, ans);
        return ans;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def shortestPathLength(self, graph):
        N = len(graph)
        dist = [[float('inf')] * N for i in xrange(1 << N)]
        for x in xrange(N):
            dist[1<<x][x] = 0

        for cover in xrange(1 << N):
            repeat = True
            while repeat:
                repeat = False
                for head, d in enumerate(dist[cover]):
                    for nei in graph[head]:
                        cover2 = cover | (1 << nei)
                        if d + 1 < dist[cover2][nei]:
                            dist[cover2][nei] = d + 1
                            if cover == cover2:
                                repeat = True

        return min(dist[2**N - 1])
```

**复杂度分析**

* 时间复杂度：$O(2^N * N)$。

* 空间复杂度：$O(2^N * N)$。