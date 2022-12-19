#### 方法 1：广度优先搜索

**想法**

由于我们需要找到一条最短路径，广度优先搜索是一种理想的方法。难点在于如何对每个方格枚举所有可能的移动。

**算法**

假设我们在方格 `s` 上，我们想知道一次移动之后所有可能的终点 `s2`。

这需要知道方格 `s2` 的坐标 `get(s2)`，这有一个小技巧：我们知道行号每 `N` 个方格改变一次，所以只依赖于 `quot = (s2-1) / N`；同样列号依赖于 `rem = (s2-1) % N`。

由此，我们可以实现一个根据方格 `s`  的信息进行广度优先搜索。

```Java []
class Solution {
    public int snakesAndLadders(int[][] board) {
        int N = board.length;

        Map<Integer, Integer> dist = new HashMap();
        dist.put(1, 0);

        Queue<Integer> queue = new LinkedList();
        queue.add(1);

        while (!queue.isEmpty()) {
            int s = queue.remove();
            if (s == N*N) return dist.get(s);

            for (int s2 = s+1; s2 <= Math.min(s+6, N*N); ++s2) {
                int rc = get(s2, N);
                int r = rc / N, c = rc % N;
                int s2Final = board[r][c] == -1 ? s2 : board[r][c];
                if (!dist.containsKey(s2Final)) {
                    dist.put(s2Final, dist.get(s) + 1);
                    queue.add(s2Final);
                }
            }
        }
        return -1;
    }

    public int get(int s, int N) {
        // Given a square num s, return board coordinates (r, c) as r*N + c
        int quot = (s-1) / N;
        int rem = (s-1) % N;
        int row = N - 1 - quot;
        int col = row % 2 != N % 2 ? rem : N - 1 - rem;
        return row * N + col;
    }
}
```

```Python []
class Solution(object):
    def snakesAndLadders(self, board):
        N = len(board)

        def get(s):
            # Given a square num s, return board coordinates (r, c)
            quot, rem = divmod(s-1, N)
            row = N - 1 - quot
            col = rem if row%2 != N%2 else N - 1 - rem
            return row, col

        dist = {1: 0}
        queue = collections.deque([1])
        while queue:
            s = queue.popleft()
            if s == N*N: return dist[s]
            for s2 in xrange(s+1, min(s+6, N*N) + 1):
                r, c = get(s2)
                if board[r][c] != -1:
                    s2 = board[r][c]
                if s2 not in dist:
                    dist[s2] = dist[s] + 1
                    queue.append(s2)
        return -1
```


**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是 `board` 的长度。
* 空间复杂度：$O(N^2)$。