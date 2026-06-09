通过两个Set实现交替扩散：
```java
class Solution {
    static final int[][] dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if (n == 1 && grid[0][0] == 0) return 1;

        Set<Coordinate> beginSet = new HashSet<>(Collections.singleton(new Coordinate(0, 0)));
        Set<Coordinate> endSet = new HashSet<>(Collections.singleton(new Coordinate(n - 1, n - 1)));
        grid[0][0] = grid[n - 1][n - 1] = -1; // 通过更改原值来区分当前坐标是否已访问，替代visited数组，用-1是为了区别原有的1，如果需要也方便还原grid

        int count = 1;
        while (!beginSet.isEmpty()) {
            Set<Coordinate> tempSet = new HashSet<>();
            for (Coordinate curr : beginSet) {
                for (int[] d : dir) {
                    int x = curr.x + d[0], y = curr.y + d[1];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1) continue;  // 过界及阻塞判断
                    Coordinate next = new Coordinate(x, y);
                    if (endSet.contains(next)) return count + 1; // 前后碰头就可以返回了
                    if (grid[x][y] == -1) continue; // 已访问判断
                    grid[x][y] = -1; // 已访问设置
                    tempSet.add(next); // 添加后续扩散数据
                }
            }
            count++;
            // 优先选择数据量少的进行扩散
            if (tempSet.size() > endSet.size()) {
                beginSet = endSet;
                endSet = tempSet;
            } else {
                beginSet = tempSet;
            }
        }
        return -1;
    }
}

// 记录坐标，重写equals、hashCode用于set.contains()判断
class Coordinate {
    int x, y;

    public Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Coordinate)) return false;
        Coordinate that = (Coordinate) o;
        return x == that.x && y == that.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}
```
当然你也可以更直观更传统的用Queue来实现：
```java
class Solution {
    static final int[][] dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if (n == 1 && grid[0][0] == 0) return 1;

        Queue<Coordinate> beginQueue = new LinkedList<>(Collections.singleton(new Coordinate(0, 0)));
        Queue<Coordinate> endQueue = new LinkedList<>(Collections.singleton(new Coordinate(n - 1, n - 1)));
        grid[0][0] = grid[n - 1][n - 1] = -1;

        int count = 1;
        while (!beginQueue.isEmpty()) {
            int size = beginQueue.size();
            while (size-- > 0) {
                Coordinate curr = beginQueue.poll();
                for (int[] d : dir) {
                    int x = curr.x + d[0], y = curr.y + d[1];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1) continue;
                    Coordinate next = new Coordinate(x, y);
                    if (endQueue.contains(next)) return count + 1; // queue的contains会整个便利，稍微慢一点
                    if (grid[x][y] == -1) continue;
                    grid[x][y] = -1;
                    beginQueue.offer(next);
                }
            }
            count++;
            if (beginQueue.size() > endQueue.size()) {
                Queue<Coordinate> tmpQueue = beginQueue;
                beginQueue = endQueue;
                endQueue = tmpQueue;
            }
        }
        return -1;
    }
}

class Coordinate {
    // 同上，略
}
```

或者更简约的实现，省去自定义类：
```java
class Solution {
    static final int[][] dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if (n == 1 && grid[0][0] == 0) return 1;

        Queue<int[]> beginQueue = new LinkedList<>(Collections.singleton(new int[]{0, 0}));
        Queue<int[]> endQueue = new LinkedList<>(Collections.singleton(new int[]{n - 1, n - 1}));
        boolean[][] beginSet, endSet = new boolean[n][n]; // 为了方便判断坐标是否在endSet中存在，替代endQueue.contains()
        endSet[n - 1][n - 1] = true;
        grid[0][0] = grid[n - 1][n - 1] = -1;

        int count = 1;
        while (!beginQueue.isEmpty()) {
            beginSet = new boolean[n][n];
            int size = beginQueue.size();
            while (size-- > 0) {
                int[] curr = beginQueue.poll();
                for (int[] d : dir) {
                    int x = curr[0] + d[0], y = curr[1] + d[1];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1) continue;
                    if (endSet[x][y]) return count + 1;
                    if (grid[x][y] == -1) continue;
                    grid[x][y] = -1;
                    beginQueue.offer(new int[]{x, y});
                    beginSet[x][y] = true;
                }
            }
            count++;
            if (beginQueue.size() > endQueue.size()) {
                Queue<int[]> tmpQueue = beginQueue;
                beginQueue = endQueue;
                endQueue = tmpQueue;
                endSet = beginSet;
            }
        }
        return -1;
    }
}
```

算了，别烦了，就单向吧：
```java
class Solution {
    static final int[][] dir = {{1, 1}, {1, 0}, {0, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length, m = n - 1;
        if (grid[0][0] == 1 || grid[m][m] == 1) return -1;
        if (n == 1 && grid[0][0] == 0) return 1;

        Queue<int[]> queue = new LinkedList<>(Collections.singleton(new int[]{0, 0}));
        grid[0][0] = -1;

        int count = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                int[] curr = queue.poll();
                for (int[] d : dir) {
                    int x = curr[0] + d[0], y = curr[1] + d[1];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1) continue;
                    if (x == m && y == m) return count + 1;
                    if (grid[x][y] == -1) continue;
                    grid[x][y] = -1;
                    queue.offer(new int[]{x, y});
                }
            }
            count++;
        }
        return -1;
    }
}
```
