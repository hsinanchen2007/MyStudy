#### 方法一： 堆【通过】

**思路和算法**

用优先队列保存下一步可以游向的平台，每次都选择高度最小的平台。以这种方式到达终点时，路径中遇到的最高平台就是答案。

```java [solution1-Java]
class Solution {
    public int swimInWater(int[][] grid) {
        int N = grid.length;
        Set<Integer> seen = new HashSet();
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((k1, k2) ->
                grid[k1 / N][k1 % N] - grid[k2 / N][k2 % N]);
        pq.offer(0);
        int ans = 0;

        int[] dr = new int[]{1, -1, 0, 0};
        int[] dc = new int[]{0, 0, 1, -1};

        while (!pq.isEmpty()) {
            int k = pq.poll();
            int r = k / N, c = k % N;
            ans = Math.max(ans, grid[r][c]);
            if (r == N-1 && c == N-1) return ans;

            for (int i = 0; i < 4; ++i) {
                int cr = r + dr[i], cc = c + dc[i];
                int ck = cr * N + cc;
                if (0 <= cr && cr < N && 0 <= cc && cc < N && !seen.contains(ck)) {
                    pq.offer(ck);
                    seen.add(ck);
                }
            }
        }

        throw null;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def swimInWater(self, grid):
        N = len(grid)

        seen = {(0, 0)}
        pq = [(grid[0][0], 0, 0)]
        ans = 0
        while pq:
            d, r, c = heapq.heappop(pq)
            ans = max(ans, d)
            if r == c == N-1: return ans
            for cr, cc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                if 0 <= cr < N and 0 <= cc < N and (cr, cc) not in seen:
                    heapq.heappush(pq, (grid[cr][cc], cr, cc))
                    seen.add((cr, cc))
```

**复杂度分析**

* 时间复杂度： $O(N^2 \log N)$。最大需要经过 $O(N^2)$ 个节点，每个节点需要 $O(\log N)$ 的时间来完成堆操作。

* 空间复杂度： $O(N^2)$，其为堆的最大值。

#### 方法二： 二分搜索 + 深度优先搜索 【通过】

**思路和算法**

可以发现是否能完成是根据时间的单调函数，因此可以用二分搜索来找到最少耗时。即找到最小 `T` 使得从起点游到终点成为可能。设最少耗时为 `T`，用深度优先搜索来检查是否有可能从起点游到终点。

```java [solution2-Java]
class Solution {
    public int swimInWater(int[][] grid) {
        int N = grid.length;
        int lo = grid[0][0], hi = N * N;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (!possible(mi, grid)) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }

    public boolean possible(int T, int[][] grid) {
        int N = grid.length;
        Set<Integer> seen = new HashSet();
        seen.add(0);
        int[] dr = new int[]{1, -1, 0, 0};
        int[] dc = new int[]{0, 0, 1, -1};

        Stack<Integer> stack = new Stack();
        stack.add(0);

        while (!stack.empty()) {
            int k = stack.pop();
            int r = k / N, c = k % N;
            if (r == N-1 && c == N-1) return true;

            for (int i = 0; i < 4; ++i) {
                int cr = r + dr[i], cc = c + dc[i];
                int ck = cr * N + cc;
                if (0 <= cr && cr < N && 0 <= cc && cc < N
                        && !seen.contains(ck) && grid[cr][cc] <= T) {
                    stack.add(ck);
                    seen.add(ck);
                }
            }
        }

        return false;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def swimInWater(self, grid):
        N = len(grid)

        def possible(T):
            stack = [(0, 0)]
            seen = {(0, 0)}
            while stack:
                r, c = stack.pop()
                if r == c == N-1: return True
                for cr, cc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                    if (0 <= cr < N and 0 <= cc < N
                            and (cr, cc) not in seen and grid[cr][cc] <= T):
                        stack.append((cr, cc))
                        seen.add((cr, cc))
            return False

        lo, hi = grid[0][0], N * N
        while lo < hi:
            mi = (lo + hi) / 2
            if not possible(mi):
                lo = mi + 1
            else:
                hi = mi
        return lo
```


**复杂度分析**

* 时间复杂度：$O(N^2 \log N)$。深度优先搜索的复杂度为 $O(N^2)$，最多需要搜索 $O(\log N)$ 次。

* 空间复杂度：$O(N^2)$，栈的大小。