#### 方法一： 广度优先搜索 【通过】

**思路**

可以把这道题看成一个找出图中最短路径的问题。每个节点都是棋盘的一个状态，如果两个状态之间可以通过一步操作来完成转换，就用一条边将这两个节点相连。用 *广度优先搜索* 来解决最短路径问题。

**算法**

在广度优先搜索实现中，需要将节点表示成可以哈希的数据结构，同时还需要找到每个节点的邻居节点。之后套一个下面这样的广度优先搜索模板就可以了。

```python [solution1-Python]
queue = collections.deque([(start, 0)])
seen = {start}
while queue:
    node, depth = queue.popleft()
    if node == target: return depth
    for nei in neighbors(node):
        if nei not in seen:
            seen.add(nei)
            queue.append((nei, depth+1))
```

为了将节点表示成可以哈希的数据结构，在 Python 实现中，将棋盘转化成一维 tuple。在 Java 实现中，可以将棋盘转化成一个整数或者直接用 `Arrays.deepToString`。

为了枚举节点的邻居，需要记住 `0` 的位置。对于每个节点，最多有 4 个的邻居，将棋盘用一维数组表示，当前节点的邻居距离当前节点 `(1, -1, C, -C)` 距离，其中 `C` 是棋盘的列数。

```java [solution1-Java]
class Solution {
    public int slidingPuzzle(int[][] board) {
        int R = board.length, C = board[0].length;
        int sr = 0, sc = 0;
        search:
            for (sr = 0; sr < R; sr++)
                for (sc = 0; sc < C; sc++)
                    if (board[sr][sc] == 0)
                        break search;

        int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        Queue<Node> queue = new ArrayDeque();
        Node start = new Node(board, sr, sc, 0);
        queue.add(start);

        Set<String> seen = new HashSet();
        seen.add(start.boardstring);

        String target = Arrays.deepToString(new int[][]{{1,2,3}, {4,5,0}});

        while (!queue.isEmpty()) {
            Node node = queue.remove();
            if (node.boardstring.equals(target))
                return node.depth;

            for (int[] di: directions) {
                int nei_r = di[0] + node.zero_r;
                int nei_c = di[1] + node.zero_c;

                if ((Math.abs(nei_r - node.zero_r) + Math.abs(nei_c - node.zero_c) != 1) ||
                        nei_r < 0 || nei_r >= R || nei_c < 0 || nei_c >= C)
                    continue;

                int[][] newboard = new int[R][C];
                int t = 0;
                for (int[] row: node.board)
                    newboard[t++] = row.clone();
                newboard[node.zero_r][node.zero_c] = newboard[nei_r][nei_c];
                newboard[nei_r][nei_c] = 0;

                Node nei = new Node(newboard, nei_r, nei_c, node.depth+1);
                if (seen.contains(nei.boardstring))
                    continue;
                queue.add(nei);
                seen.add(nei.boardstring);
            }
        }

        return -1;
    }
}

class Node {
    int[][] board;
    String boardstring;
    int zero_r;
    int zero_c;
    int depth;
    Node(int[][] B, int r, int c, int d) {
        board = B;
        boardstring = Arrays.deepToString(board);
        zero_r = r;
        zero_c = c;
        depth = d;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def slidingPuzzle(self, board):
        R, C = len(board), len(board[0])
        start = tuple(itertools.chain(*board))
        queue = collections.deque([(start, start.index(0), 0)])
        seen = {start}

        target = tuple(range(1, R*C) + [0])

        while queue:
            board, posn, depth = queue.popleft()
            if board == target: return depth
            for d in (-1, 1, -C, C):
                nei = posn + d
                if abs(nei/C - posn/C) + abs(nei%C - posn%C) != 1:
                    continue
                if 0 <= nei < R*C:
                    newboard = list(board)
                    newboard[posn], newboard[nei] = newboard[nei], newboard[posn]
                    newt = tuple(newboard)
                    if newt not in seen:
                        seen.add(newt)
                        queue.append((newt, nei, depth+1))

        return -1
```


**复杂度分析**

* 时间复杂度：$O(R * C * (R * C)!)$，其中 $R, C$ 为棋盘的行数和列数。最多有 $O((R * C)!)$ 种可能的棋盘状态。

* 空间复杂度：$O(R * C * (R * C)!)$。

#### 方法二： A* 搜索 【通过】

**思路**

同方法一的思路一样，还是一个图的搜索问题。用 *A\* 搜索算法* 来搜索最优答案。

对于每个节点，定义一个预估代价 `node.priority = node.depth + node.heuristic`，其中 `node.depth` 为已经走过的距离，`node.heuristic` 为预估的剩余距离。

对于熟悉 *Dijkstra 算法* 的读者来说，可以把 *Dijkstra 算法* 当成一种在 `node.heuristic = 0` 情况下 *A\* 搜索算法* 的特例。在一些特定的图中，*A\* 搜索算法* 是要比深度优先搜索更快的。

**算法**

同方法一相同，每个节点代表一种棋盘的状态。保持一个优先队列，根据 `node.depth + node.heuristic` 排序。预估的剩余距离为每个节点到终点的曼哈顿距离。

对于初始状态的棋盘，有可能解开谜题，也有可能解不开谜题。为了加快算法，定义 `targetWrong`，如果进入这种状态是一定不能到达终点的，也就不用继续搜便下去了。这里其实是可以证明，除了最后两块其他块是一定能放到正确的位置上的。具体证明可以看这个链接 [link](http://kevingong.com/Math/SixteenPuzzle.html).

```java [solution2-Java]
class Solution {
    public int slidingPuzzle(int[][] board) {
        int R = board.length, C = board[0].length;
        int sr = 0, sc = 0;

        //Find sr, sc
        search:
            for (sr = 0; sr < R; sr++)
                for (sc = 0; sc < C; sc++)
                    if (board[sr][sc] == 0)
                        break search;

        int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        PriorityQueue<Node> heap = new PriorityQueue<Node>((a, b) ->
            (a.heuristic + a.depth) - (b.heuristic + b.depth));
        Node start = new Node(board, sr, sc, 0);
        heap.add(start);

        Map<String, Integer> cost = new HashMap();
        cost.put(start.boardstring, 9999999);

        String target = Arrays.deepToString(new int[][]{{1,2,3}, {4,5,0}});
        String targetWrong = Arrays.deepToString(new int[][]{{1,2,3}, {5,4,0}});

        while (!heap.isEmpty()) {
            Node node = heap.poll();
            if (node.boardstring.equals(target))
                return node.depth;
            if (node.boardstring.equals(targetWrong))
                return -1;
            if (node.depth + node.heuristic > cost.get(node.boardstring))
                continue;

            for (int[] di: directions) {
                int nei_r = di[0] + node.zero_r;
                int nei_c = di[1] + node.zero_c;

                // If the neighbor is not on the board or wraps incorrectly around rows/cols
                if ((Math.abs(nei_r - node.zero_r) + Math.abs(nei_c - node.zero_c) != 1) ||
                        nei_r < 0 || nei_r >= R || nei_c < 0 || nei_c >= C)
                    continue;

                int[][] newboard = new int[R][C];
                int t = 0;
                for (int[] row: node.board)
                    newboard[t++] = row.clone();

                // Swap the elements on the new board
                newboard[node.zero_r][node.zero_c] = newboard[nei_r][nei_c];
                newboard[nei_r][nei_c] = 0;

                Node nei = new Node(newboard, nei_r, nei_c, node.depth+1);
                if (nei.depth + nei.heuristic >= cost.getOrDefault(nei.boardstring, 9999999))
                    continue;
                heap.add(nei);
                cost.put(nei.boardstring, nei.depth + nei.heuristic);
            }
        }

        return -1;
    }
}

class Node {
    int[][] board;
    String boardstring;
    int heuristic;
    int zero_r;
    int zero_c;
    int depth;
    Node(int[][] B, int zr, int zc, int d) {
        board = B;
        boardstring = Arrays.deepToString(board);

        //Calculate heuristic
        heuristic = 0;
        int R = B.length, C = B[0].length;
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c) {
                if (board[r][c] == 0) continue;
                int v = (board[r][c] + R*C - 1) % (R*C);
                // v/C, v%C: where board[r][c] should go in a solved puzzle
                heuristic += Math.abs(r - v/C) + Math.abs(c - v%C);
            }
        heuristic /= 2;
        zero_r = zr;
        zero_c = zc;
        depth = d;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def slidingPuzzle(self, board):
        R, C = len(board), len(board[0])
        start = tuple(itertools.chain(*board))
        target = tuple(range(1, R*C) + [0])
        target_wrong = tuple(range(1, R*C-2) + [R*C-1, R*C-2, 0])
        pq = [(0, 0, start, start.index(0))]
        cost = {start: 0}

        expected = {(C*r+c+1) % (R*C) : (r, c)
                    for r in xrange(R) for c in xrange(C)}
        def heuristic(board):
            ans = 0
            for r in xrange(R):
                for c in xrange(C):
                    val = board[C*r + c]
                    if val == 0: continue
                    er, ec = expected[val]
                    ans += abs(r - er) + abs(c - ec)
            return ans

        while pq:
            #f = estimated distance (priority)
            #g = actual distance travelled (depth)
            f, g, board, zero = heapq.heappop(pq)
            if board == target: return g
            if board == target_wrong: return -1
            if f > cost[board]: continue

            for delta in (-1, 1, -C, C):
                nei = zero + delta
                if abs(zero / C - nei / C) + abs(zero % C - nei % C) != 1:
                    continue
                if 0 <= nei < R*C:
                    board2 = list(board)
                    board2[zero], board2[nei] = board2[nei], board2[zero]
                    board2t = tuple(board2)
                    ncost = g + 1 + heuristic(board2t)
                    if ncost < cost.get(board2t, float('inf')):
                        cost[board2t] = ncost
                        heapq.heappush(pq, (ncost, g+1, board2t, nei))

        return -1
```


**复杂度分析**

* 时间复杂度：$O(R * C * (R * C)!)$，其中 $R, C$ 为棋盘的行数和列数。有更准确的复杂度，但比较难以证明所以不做展开。

* 空间复杂度：$O(R * C * (R * C)!)$。