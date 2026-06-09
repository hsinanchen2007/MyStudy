##  解决方法：
####  框架：
- 从 `(0, 0)` 开始，对于每棵树，按照高度顺序，我们将计算我们到下一棵树（并移动到那里）的距离，并将该距离添加到答案中。 
- 我们定义距离函数 `dist(forest, sr, sc, tr, tc)`，该函数计算从源 `(sr, sc)` 到目标 `(tr, tc)` 通过障碍物 `dist[i][j]==0` 的路径距离。（如果路径不可能，此距离函数将返回 `-1`）。
- 接下来是代码和复杂性分析，这三种方法都很常见。之后，我们的方法中给出的算法将只关注提供 `dist` 函数。 

```Python [ ]
class Solution(object):
    def cutOffTree(self, forest):
        trees = sorted((v, r, c) for r, row in enumerate(forest)
                       for c, v in enumerate(row) if v > 1)
        sr = sc = ans = 0
        for _, tr, tc in trees:
            d = dist(forest, sr, sc, tr, tc)
            if d < 0: return -1
            ans += d
            sr, sc = tr, tc
        return ans
```

```Java [ ]
class Solution {
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};

    public int cutOffTree(List<List<Integer>> forest) {
        List<int[]> trees = new ArrayList();
        for (int r = 0; r < forest.size(); ++r) {
            for (int c = 0; c < forest.get(0).size(); ++c) {
                int v = forest.get(r).get(c);
                if (v > 1) trees.add(new int[]{v, r, c});
            }
        }

        Collections.sort(trees, (a, b) -> Integer.compare(a[0], b[0]));

        int ans = 0, sr = 0, sc = 0;
        for (int[] tree: trees) {
            int d = dist(forest, sr, sc, tree[1], tree[2]);
            if (d < 0) return -1;
            ans += d;
            sr = tree[1]; sc = tree[2];
        }
        return ans;
    }
}
```

**复杂度分析**
这三种算法都具有相似的最坏情况复杂度.
* 时间复杂度：$O((RC)^2)$，在给定的 `forest` 中有 $R$ 行和 $C$ 列。我们步行到 $RC$ 树，每一次步行都可以花费 $O(RC)$ 时间搜索树。 
* 空间复杂度：$O(R*C)$，所用数据结构的最大大小。 


####  方法一：宽度优先搜索(BFS)
**算法：**
- 我们执行宽度优先搜索，处理队列中的节点（网格位置）。`seen` 跟踪在某个时间点已经添加到队列中的节点，这些节点已被处理或在等待处理的队列中。 
- 对于下一个要处理的每个节点，我们查看它的周围。如果他们在森林（网格）中，他们没有排队，而且他们不是障碍，我们将把那个相邻节点排队。 
- 我们还对每个节点的行驶距离进行计数。如果我们正在处理的节点是我们的 “目标” `(tr, tc)`，我们将返回答案。 

```Python [ ]
def bfs(forest, sr, sc, tr, tc):
    R, C = len(forest), len(forest[0])
    queue = collections.deque([(sr, sc, 0)])
    seen = {(sr, sc)}
    while queue:
        r, c, d = queue.popleft()
        if r == tr and c == tc:
            return d
        for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
            if (0 <= nr < R and 0 <= nc < C and
                    (nr, nc) not in seen and forest[nr][nc]):
                seen.add((nr, nc))
                queue.append((nr, nc, d+1))
    return -1
```

```Java [ ]
public int bfs(List<List<Integer>> forest, int sr, int sc, int tr, int tc) {
    int R = forest.size(), C = forest.get(0).size();
    Queue<int[]> queue = new LinkedList();
    queue.add(new int[]{sr, sc, 0});
    boolean[][] seen = new boolean[R][C];
    seen[sr][sc] = true;
    while (!queue.isEmpty()) {
        int[] cur = queue.poll();
        if (cur[0] == tr && cur[1] == tc) return cur[2];
        for (int di = 0; di < 4; ++di) {
            int r = cur[0] + dr[di];
            int c = cur[1] + dc[di];
            if (0 <= r && r < R && 0 <= c && c < C &&
                    !seen[r][c] && forest.get(r).get(c) > 0) {
                seen[r][c] = true;
                queue.add(new int[]{r, c, cur[2]+1});
            }
        }
    }
    return -1;
}
```

####  方法二：A*搜索 
**算法：**
- A*算法是另一种路径查找算法。对于位置 `(r, c)` 的每个节点，我们使 `node.f = node.g + node.h`，其中 `node.g` 是从 `(sr, sc)` 到 `(r, c)` 的实际距离， `node.h` 是从 `(r, c)` 到 `(tr, tc)` 的距离的启发式（猜测）。在这种情况下，我们的猜测将是 `node.h = abs(r-tr) + abs(c-tc)`。 
- 我们保留一个优先队列来决定下一个搜索(扩展)的节点。我们可以证明，如果我们找到目标节点，我们一定走了尽可能短的距离  `node.g`。例如，通过考虑最后一次两条反向路径是相同的，在不失去一般性的情况下，我们可以假设两条路径的倒数第二个方格是不同的，然后在这种情况下，没有 `node.f = node.g + 1`，根据需要首先扩展显示实际行驶距离较小的路径。 
- 对于熟悉 `Dijkstra` 算法的人来说，知道一个 A*搜索是 `Dijkstra` 的一个特例，且 `node.h` 总是 0。

```Python [ ]
def astar(forest, sr, sc, tr, tc):
    R, C = len(forest), len(forest[0])
    heap = [(0, 0, sr, sc)]
    cost = {(sr, sc): 0}
    while heap:
        f, g, r, c = heapq.heappop(heap)
        if r == tr and c == tc: return g
        for nr, nc in ((r-1,c), (r+1,c), (r,c-1), (r,c+1)):
            if 0 <= nr < R and 0 <= nc < C and forest[nr][nc]:
                ncost = g + 1 + abs(nr - tr) + abs(nc - tc)
                if ncost < cost.get((nr, nc), 9999):
                    cost[nr, nc] = ncost
                    heapq.heappush(heap, (ncost, g+1, nr, nc))
    return -1
```

```Java [ ]
public int cutOffTree(List<List<Integer>> forest, int sr, int sc, int tr, int tc) {
    int R = forest.size(), C = forest.get(0).size();
    PriorityQueue<int[]> heap = new PriorityQueue<int[]>(
        (a, b) -> Integer.compare(a[0], b[0]));
    heap.offer(new int[]{0, 0, sr, sc});

    HashMap<Integer, Integer> cost = new HashMap();
    cost.put(sr * C + sc, 0);

    while (!heap.isEmpty()) {
        int[] cur = heap.poll();
        int g = cur[1], r = cur[2], c = cur[3];
        if (r == tr && c == tc) return g;
        for (int di = 0; di < 4; ++di) {
            int nr = r + dr[di], nc = c + dc[di];
            if (0 <= nr && nr < R && 0 <= nc && nc < C && forest.get(nr).get(nc) > 0) {
                int ncost = g + 1 + Math.abs(nr-tr) + Math.abs(nc-tr);
                if (ncost < cost.getOrDefault(nr * C + nc, 9999)) {
                    cost.put(nr * C + nc, ncost);
                    heap.offer(new int[]{ncost, g+1, nr, nc});
                }
            }
        }
    }
    return -1;
}
```

####  方法三：Hadlock 算法
没有任何障碍物，从 `source = (sr, sc)` 到 `target = (tr, tc)` 的距离就是 `taxi(source, target) = abs(sr-tr) + abs(sc-tc)`。这表示必须行驶的最小距离。每当我们离开目标时，我们都会将这个最小值增加2，因为我们一步一个移动，再加上 taxicab 离我们新位置的距离增加了 1。 

我们称 `detour` 为一次绕开目标的移动，可以证明，从源到目标的距离仅为 `taxi(source, target) + 2 * detours`，其中，从 `source` 到 `target` 的任何路径中，`detours` 的数量最小。 

算法：
- 对于一个 `source` 和 `target`，称一个方格的迂回数为从 `source` 到该方格的任何路径中可能出现的最小迂回数。（这里，迂回道是针对 `target` 定义的——距离目标的步数。） 
- 我们将按照 `detour` 编号的顺序执行优先级优先搜索。如果找到目标，则找到最低的 `detour` ，因此相应距离最低。同时使用 `processed` 跟踪节点，防止节点被访问两次。 
- 由于每个相邻节点只能有相同的 `detour` 编号或更高的 `detour` 编号，因此一次最多只能考虑两个优先级。因此，我们可以使用 `deque`（双端队列）来执行此实现。我们将首先放置具有相同要展开的 `detour` 编号的节点，在完成所有具有当前编号的节点之后，将展开具有更高迂回道编号的节点。 

```Python [ ]
def hadlocks(forest, sr, sc, tr, tc):
    R, C = len(forest), len(forest[0])
    processed = set()
    deque = collections.deque([(0, sr, sc)])
    while deque:
        detours, r, c = deque.popleft()
        if (r, c) not in processed:
            processed.add((r, c))
            if r == tr and c == tc:
                return abs(sr-tr) + abs(sc-tc) + 2*detours
            for nr, nc, closer in ((r-1, c, r > tr), (r+1, c, r < tr),
                                   (r, c-1, c > tc), (r, c+1, c < tc)):
                if 0 <= nr < R and 0 <= nc < C and forest[nr][nc]:
                    if closer:
                        deque.appendleft((detours, nr, nc))
                    else:
                        deque.append((detours+1, nr, nc))
    return -1
```

```Java [ ]
public int hadlocks(List<List<Integer>> forest, int sr, int sc, int tr, int tc) {
    int R = forest.size(), C = forest.get(0).size();
    Set<Integer> processed = new HashSet();
    Deque<int[]> deque = new ArrayDeque();
    deque.offerFirst(new int[]{0, sr, sc});
    while (!deque.isEmpty()) {
        int[] cur = deque.pollFirst();
        int detours = cur[0], r = cur[1], c = cur[2];
        if (!processed.contains(r*C + c)) {
            processed.add(r*C + c);
            if (r == tr && c == tc) {
                return Math.abs(sr-tr) + Math.abs(sc-tc) + 2 * detours;
            }
            for (int di = 0; di < 4; ++di) {
                int nr = r + dr[di];
                int nc = c + dc[di];
                boolean closer;
                if (di <= 1) closer = di == 0 ? r > tr : r < tr;
                else closer = di == 2 ? c > tc : c < tc;
                if (0 <= nr && nr < R && 0 <= nc && nc < C && forest.get(nr).get(nc) > 0) {
                    if (closer) deque.offerFirst(new int[]{detours, nr, nc});
                    else deque.offerLast(new int[]{detours+1, nr, nc});
                }
            }
        }
    }
    return -1;
}
```