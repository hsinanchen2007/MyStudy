#### 方法 1： 暴力

暴力方法十分简单，我们只需要从每个空的房间开始做宽度优先搜索，找到最近的门即可。

我们搜索的时候，用一个二维的数组，记作 `distance` ，记录从起点出发的距离。它也能隐含一个位置是否已经被访问过的信息，以免被重复放入队列。

```Java []
private static final int EMPTY = Integer.MAX_VALUE;
private static final int GATE = 0;
private static final int WALL = -1;
private static final List<int[]> DIRECTIONS = Arrays.asList(
        new int[] { 1,  0},
        new int[] {-1,  0},
        new int[] { 0,  1},
        new int[] { 0, -1}
);

public void wallsAndGates(int[][] rooms) {
    if (rooms.length == 0) return;
    for (int row = 0; row < rooms.length; row++) {
        for (int col = 0; col < rooms[0].length; col++) {
            if (rooms[row][col] == EMPTY) {
                rooms[row][col] = distanceToNearestGate(rooms, row, col);
            }
        }
    }
}

private int distanceToNearestGate(int[][] rooms, int startRow, int startCol) {
    int m = rooms.length;
    int n = rooms[0].length;
    int[][] distance = new int[m][n];
    Queue<int[]> q = new LinkedList<>();
    q.add(new int[] { startRow, startCol });
    while (!q.isEmpty()) {
        int[] point = q.poll();
        int row = point[0];
        int col = point[1];
        for (int[] direction : DIRECTIONS) {
            int r = row + direction[0];
            int c = col + direction[1];
            if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] == WALL
                    || distance[r][c] != 0) {
                continue;
            }
            distance[r][c] = distance[row][col] + 1;
            if (rooms[r][c] == GATE) {
                return distance[r][c];
            }
            q.add(new int[] { r, c });
        }
    }
    return Integer.MAX_VALUE;
}
```

**复杂度分析**

* 时间复杂度：$O(m^2n^2)$ 。对 $m \times n$ 大小格子中的每一个点，门最远会在 $m \times n$ 步远的地方。

* 空间复杂度： $O(mn)$ 。空间复杂度取决于队列的大小。我们在从某个空房间开始搜索的时候，不会访问已经访问过的格子，所以队列里最多有 $m \times n$ 个点。

#### 方法 2：宽度优先搜索

与其从一个空的房间开始找门，我们何不按另一种方式来搜索？换言之，我们从门开始做宽度优先搜索。由于宽度优先搜索保证我们在搜索 *d + 1* 距离的位置时， 距离为 *d* 的位置都已经被搜索过了，所以到达每一个房间的时候都一定是最短距离。

```Java []
private static final int EMPTY = Integer.MAX_VALUE;
private static final int GATE = 0;
private static final List<int[]> DIRECTIONS = Arrays.asList(
        new int[] { 1,  0},
        new int[] {-1,  0},
        new int[] { 0,  1},
        new int[] { 0, -1}
);

public void wallsAndGates(int[][] rooms) {
    int m = rooms.length;
    if (m == 0) return;
    int n = rooms[0].length;
    Queue<int[]> q = new LinkedList<>();
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (rooms[row][col] == GATE) {
                q.add(new int[] { row, col });
            }
        }
    }
    while (!q.isEmpty()) {
        int[] point = q.poll();
        int row = point[0];
        int col = point[1];
        for (int[] direction : DIRECTIONS) {
            int r = row + direction[0];
            int c = col + direction[1];
            if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != EMPTY) {
                continue;
            }
            rooms[r][c] = rooms[row][col] + 1;
            q.add(new int[] { r, c });
        }
    }
}
```

**复杂度分析**

* 时间复杂度： $O(mn)$ 。
    
    如果你对直接得到时间复杂度有困难的话，我们可以从简单的情况开始。

    我们首先考虑只有一个门的情况，宽度优先搜索最多只需要 $m \times n$ 步就能到达所有的房间，所以时间复杂度是 $O(mn)$ 。但是如果从 $k$ 个门开始呢？

    一旦我们到达了一个房间，并记录下它的距离时，这意味着我们也标记了这个房间已经被访问过了，这意味着每个房间最多会被访问一次。因此，时间复杂度与门的数量无关，所以时间复杂度为 $O(mn)$ 。

* 空间复杂度： $O(mn)$ 。

    空间复杂度与队列的大小有关。我们最多将 $m \times n$ 个位置插入队列，所以空间最大为 $m \times n$ 。