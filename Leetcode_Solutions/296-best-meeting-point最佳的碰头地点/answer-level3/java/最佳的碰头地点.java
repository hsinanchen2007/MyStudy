#### 方法 1：宽度优先搜索

一种暴力的解法是枚举网格中所有可能的相遇地点。我们从每个点出发做宽度（广度）优先搜索。

在将某个点放进队列时，我们需要记录从相遇点到这个点的曼哈顿距离。同时，我们需要一个额外的数组 `visited` 记录哪些点已经被访问过了，以避免将一个已经访问过的点重复放入队列。

```Java []
public int minTotalDistance(int[][] grid) {
    int minDistance = Integer.MAX_VALUE;
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            int distance = search(grid, row, col);
            minDistance = Math.min(distance, minDistance);
        }
    }
    return minDistance;
}

private int search(int[][] grid, int row, int col) {
    Queue<Point> q = new LinkedList<>();
    int m = grid.length;
    int n = grid[0].length;
    boolean[][] visited = new boolean[m][n];
    q.add(new Point(row, col, 0));
    int totalDistance = 0;
    while (!q.isEmpty()) {
        Point point = q.poll();
        int r = point.row;
        int c = point.col;
        int d = point.distance;
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c]) {
            continue;
        }
        if (grid[r][c] == 1) {
            totalDistance += d;
        }
        visited[r][c] = true;
        q.add(new Point(r + 1, c, d + 1));
        q.add(new Point(r - 1, c, d + 1));
        q.add(new Point(r, c + 1, d + 1));
        q.add(new Point(r, c - 1, d + 1));
    }
    return totalDistance;
}

public class Point {
    int row;
    int col;
    int distance;
    public Point(int row, int col, int distance) {
        this.row = row;
        this.col = col;
        this.distance = distance;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(m^2n^2)$ 。

    在 $m \times n$ 大小的网格图中，宽度优先搜索最多需要 $m \times n$ 步可以到达任意一个点。所以总时间复杂度是 $O(m^2n^2)$ 。

* 空间复杂度： $O(mn)$ 。

    `visited` 表包含 $m \times n$ 个元素对应网格图中的每一个点。同事我们最多往队列中插入 $m \times n$ 个点。


#### 方法 2：曼哈顿距离公式

你也许注意到宽度优先搜索并不是必需的。你可以直接用以下公式来计算曼哈顿距离：

$$
distance(p1, p2) = \left | p2.x - p1.x \right | + \left | p2.y - p1.y \right |
$$

```Java []
public int minTotalDistance(int[][] grid) {
    List<Point> points = getAllPoints(grid);
    int minDistance = Integer.MAX_VALUE;
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            int distance = calculateDistance(points, row, col);
            minDistance = Math.min(distance, minDistance);
        }
    }
    return minDistance;
}

private int calculateDistance(List<Point> points, int row, int col) {
    int distance = 0;
    for (Point point : points) {
        distance += Math.abs(point.row - row) + Math.abs(point.col - col);
    }
    return distance;
}

private List<Point> getAllPoints(int[][] grid) {
    List<Point> points = new ArrayList<>();
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            if (grid[row][col] == 1) {
                points.add(new Point(row, col));
            }
        }
    }
    return points;
}

public class Point {
    int row;
    int col;
    public Point(int row, int col) {
        this.row = row;
        this.col = col;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(m^2n^2)$ 。

    假设 $k$ 是房子的数目，对 $m \times n$ 大小的网格图中的每一个点，我们需要 $O(k)$ 的时间计算到每一个房子的曼哈顿距离。所以总时间复杂度是 $O(mnk)$ 。但是注意到最多可能有 $m \times n$ 个房子，所以最坏情况下时间复杂度为 $O(m^2n^2)$ 。

* 空间复杂度： $O(mn)$ 。

#### 方法 3： 排序

在二维格子里找到相遇点看起来似乎很困难。让我们退一步考虑一维的情况，这会让问题更简单。注意到曼哈顿距离其实是两个独立变量的子问题的和。因此我们只要解决一维的情况，我们就可以把二维的情况当做两个一维独立的子问题的和。

让我们看一些一维的情况：

    情况 1: 1-0-0-0-1

    情况 2: 0-1-0-1-0

我们知道最佳相遇点应该是最左边的点和最右边的点中间的某个位置。对于以上两种情况，我们可以选择中间的点 $x = 2$ 作为最佳相遇点。那么如果我们选择所有位置的平均数作为相遇点怎么样呢？

考虑如下情况：

    情况 3: 1-0-0-0-0-0-0-1-1

使用平均值会得到 $\bar{x} = \frac{0 + 7 + 8}{3} = 5$ 作为相遇点，总距离为 $10$ 。

但是最佳距离其实是 $x = 7$ ，总距离为 $8$ 。

你也许可以会争论平均值非常 *接近* 最优相遇点。但考虑一个更大的测试数据，许多 1 都聚集在最右边，只有一个 1 在最左边，用平均值作为相遇点会跟最优相遇点偏离很多。

除了平均值，表征这些点分布更好的方法是什么呢？中位数会是更好的选择吗？事实上是的，中位数 *确实* 是最优的相遇点。

    情况 4: 1-1-0-0-1

为了解释为什么这样是对的。我们看看上面的情况 4 并选择中位数 $x = 1$ 作为我们的初始相遇点。假设遍历后的总距离为 *d* 。注意到我们在相遇点左边和右边有相同数目的点。让我们看看将相遇点往右移动一步，也就是 $x = 2$，看看距离会如何变化。

因为 $x = 2$ 的左边有 2 个点，我们需要将 *d* 增加 $2 * (+1)$ ，同时将 *d* 减 1，因为右边有一个点距离减少了 1 。这意味着总体来说距离增加了 1 。

因此，如下结论显然成立：

>只要相遇点左边和右边有相同数目的点，总距离都是最小的。

    情况 5: 1-1-0-0-1-1

也许你会认为最优相遇点一定是这些 1 中的某一个。对于奇数个 1 来说确实如此。但偶数个 1 的情况却未必，就像情况 5 。你可以选择 $x = 1$ 到 $x = 4$ 之间的任意一个点作为相遇点，且距离都是最小的。

实现方法是十分直接的。首先，我们将行和列的坐标收集并排序，然后选择它们中间的元素。然后计算两个独立的一维子问题的距离之和，就是答案。

```Java []
public int minTotalDistance(int[][] grid) {
    List<Integer> rows = new ArrayList<>();
    List<Integer> cols = new ArrayList<>();
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            if (grid[row][col] == 1) {
                rows.add(row);
                cols.add(col);
            }
        }
    }
    int row = rows.get(rows.size() / 2);
    Collections.sort(cols);
    int col = cols.get(cols.size() / 2);
    return minDistance1D(rows, row) + minDistance1D(cols, col);
}

private int minDistance1D(List<Integer> points, int origin) {
    int distance = 0;
    for (int point : points) {
        distance += Math.abs(point - origin);
    }
    return distance;
}
```

注意到上面代码我们并不需要将 *行* 进行排序，为什么？

**复杂度分析**

* 时间复杂度： $O(mn \log mn)$ 。
    
    最多会有 $m \times n$ 个点，因此排序所需的时间是 $O(mn \log mn)$ 。

* 空间复杂度： $O(mn)$ 。

#### 方法 4：按顺序收集坐标

我们可以使用 [快速选择算法](https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&tn=baidu&wd=%E5%BF%AB%E9%80%9F%E9%80%89%E6%8B%A9%E7%AE%97%E6%B3%95&rsv_spt=3&oq=%25E7%2599%25BE%25E7%25A7%2591&rsv_pq=d181ed0d00187779&rsv_t=280euL22fIUw5Fc3uVCHVnlM4HongFsN6xrrbNjCUoKtGbXw5zrSgqae384&rqlang=cn&rsv_enter=1&rsv_sug3=20&rsv_sug1=14&rsv_sug7=100&bs=%E7%99%BE%E7%A7%91) 在 $O(mn)$ 的时间内得到中位数，但还有更简单的方法。我们可以按顺序收集行和列的坐标，就不需要排序了。

```Java []
public int minTotalDistance(int[][] grid) {
    List<Integer> rows = collectRows(grid);
    List<Integer> cols = collectCols(grid);
    int row = rows.get(rows.size() / 2);
    int col = cols.get(cols.size() / 2);
    return minDistance1D(rows, row) + minDistance1D(cols, col);
}

private int minDistance1D(List<Integer> points, int origin) {
    int distance = 0;
    for (int point : points) {
        distance += Math.abs(point - origin);
    }
    return distance;
}

private List<Integer> collectRows(int[][] grid) {
    List<Integer> rows = new ArrayList<>();
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            if (grid[row][col] == 1) {
                rows.add(row);
            }
        }
    }
    return rows;
}

private List<Integer> collectCols(int[][] grid) {
    List<Integer> cols = new ArrayList<>();
    for (int col = 0; col < grid[0].length; col++) {
        for (int row = 0; row < grid.length; row++) {
            if (grid[row][col] == 1) {
                cols.add(col);
            }
        }
    }
    return cols;
}
```

你还可以直接用两个指针的方法来计算距离而不需要知道中位数。

```Java []
public int minTotalDistance(int[][] grid) {
    List<Integer> rows = collectRows(grid);
    List<Integer> cols = collectCols(grid);
    return minDistance1D(rows) + minDistance1D(cols);
}

private int minDistance1D(List<Integer> points) {
    int distance = 0;
    int i = 0;
    int j = points.size() - 1;
    while (i < j) {
        distance += points.get(j) - points.get(i);
        i++;
        j--;
    }
    return distance;
}
```

**复杂度分析**

* 时间复杂度： $O(mn)$ 。

* 空间复杂度： $O(mn)$ 。