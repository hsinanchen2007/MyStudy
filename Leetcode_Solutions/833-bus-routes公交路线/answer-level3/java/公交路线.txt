#### 广度优先搜索：

我们将每一条公交路线（而不是每一个车站）看成图中的一个点，如果两条公交路线有交集，那么它们在图中对应的点之间就有一条边。此外，起点站 `S` 和终点站 `T` 也分别是图中的一个点，如果一条公交路线包含了 `S` 或 `T`，那么也需要和 `S` 或 `T` 对应的点连一条边。此时，在这个图上从 `S` 到 `T` 的最短路径长度即为答案，我们可以用广度优先搜索来找出最短路径。

在计算两条公交路线是否有交集时，可以用的方法有很多种。例如将公交路线放在集合中，检查两个集合的交集是否为空；或者将公交路线中的车站进行递增排序，并使用双指针的方法检查是否有相同的车站。

```Java [sol1]
import java.awt.Point;

class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        if (S==T) return 0;
        int N = routes.length;

        List<List<Integer>> graph = new ArrayList();
        for (int i = 0; i < N; ++i) {
            Arrays.sort(routes[i]);
            graph.add(new ArrayList());
        }
        Set<Integer> seen = new HashSet();
        Set<Integer> targets = new HashSet();
        Queue<Point> queue = new ArrayDeque();

        // Build the graph.  Two buses are connected if
        // they share at least one bus stop.
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                if (intersect(routes[i], routes[j])) {
                    graph.get(i).add(j);
                    graph.get(j).add(i);
                }

        // Initialize seen, queue, targets.
        // seen represents whether a node has ever been enqueued to queue.
        // queue handles our breadth first search.
        // targets is the set of goal states we have.
        for (int i = 0; i < N; ++i) {
            if (Arrays.binarySearch(routes[i], S) >= 0) {
                seen.add(i);
                queue.offer(new Point(i, 0));
            }
            if (Arrays.binarySearch(routes[i], T) >= 0)
                targets.add(i);
        }

        while (!queue.isEmpty()) {
            Point info = queue.poll();
            int node = info.x, depth = info.y;
            if (targets.contains(node)) return depth+1;
            for (Integer nei: graph.get(node)) {
                if (!seen.contains(nei)) {
                    seen.add(nei);
                    queue.offer(new Point(nei, depth+1));
                }
            }
        }

        return -1;
    }

    public boolean intersect(int[] A, int[] B) {
        int i = 0, j = 0;
        while (i < A.length && j < B.length) {
            if (A[i] == B[j]) return true;
            if (A[i] < B[j]) i++; else j++;
        }
        return false;
    }
}
```

```Python [sol1]
class Solution(object):
    def numBusesToDestination(self, routes, S, T):
        if S == T: return 0
        routes = map(set, routes)
        graph = collections.defaultdict(set)
        for i, r1 in enumerate(routes):
            for j in xrange(i+1, len(routes)):
                r2 = routes[j]
                if any(r in r2 for r in r1):
                    graph[i].add(j)
                    graph[j].add(i)

        seen, targets = set(), set()
        for node, route in enumerate(routes):
            if S in route: seen.add(node)
            if T in route: targets.add(node)

        queue = [(node, 1) for node in seen]
        for node, depth in queue:
            if node in targets: return depth
            for nei in graph[node]:
                if nei not in seen:
                    seen.add(nei)
                    queue.append((nei, depth+1))
        return -1
```

**复杂度分析**

* 时间复杂度：设 $N$ 为公交路线的总数，$b_i$ 为第 $i$ 条公交路线中的车站数目，则：

    * 在建图时，我们的时间集中在判断两条公交路线是否有交集上。在 `Python` 代码中，我们通过枚举一个集合中的元素，并检查是否在另一个集合中出现的方法判断，时间复杂度为 $O(\sum (N - i) b_i)$。在 `Java` 代码中，我们排序后通过双指针寻找相同的元素进行判断，时间复杂度为 $O(\sum b_i \log b_i + N \sum b_i)$。

    * 在广度优先搜索时，包含 $N$ 个点的图的边数最大可以达到 $O(N^2)$，因此时间复杂度为 $O(N^2)$。

* 空间复杂度：$O(N^2)$，用来存储图。在 `Python` 代码中，由于我们使用了额外的集合，因此空间复杂度需要加上 $\sum b_i$。