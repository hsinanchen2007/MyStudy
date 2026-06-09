### 解题思路
https://github.com/BlackNiuza/WritingForOffer/blob/master/leetcode-cn/daily2020/_1162_%E5%9C%B0%E5%9B%BE%E5%88%86%E6%9E%90.java

### 代码

```java
     class Solution {

        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        public int maxDistance(int[][] grid) {
            boolean isSea = true;
            boolean isLand = true;
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    if (grid[i][j] == 0) {
                        isLand = false;
                    }
                    if (grid[i][j] == 1) {
                        isSea = false;
                    }
                }
            }
            if (isLand || isSea) {
                return -1;
            }

            int res = Integer.MIN_VALUE;
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    if (grid[i][j] == 0) {
                        res = Math.max(res, findFarestLand(grid, res, new Point(i, j)));
                    }
                }
            }
            return res;
        }

        private int findFarestLand(int[][] grid, int currMaxRes, Point p) {
            int[] v = new int[grid.length * grid.length];
            int n = grid.length;
            for (int i = 0; i < v.length; i++) {
                v[i] = 0;
            }

            int res = Integer.MAX_VALUE;
            Queue<Point> q = new LinkedList<>();
            q.add(p);
            v[idx(p.x, p.y, n)] = 1;
            while (!q.isEmpty()) {
                Point tp = q.poll();
                for (int d = 0; d < dx.length; d++) {
                    Point np = new Point(tp.x + dx[d], tp.y + dy[d]);
                    if (0 <= np.x && np.x < n && 0 <= np.y && np.y < n && v[idx(np.x, np.y, n)] == 0) {
                        v[idx(np.x, np.y, n)] = 1;
                        int dist = dist(np, p);
                        if (dist > res) {
                            continue;
                        }
                        if (grid[np.x][np.y] == 1) {
                            if (dist < res) {
                                res = dist;
                                if (res < currMaxRes) {
                                    break;
                                }
                            }
                        } else {
                            q.add(np);
                        }
                    }
                }
            }
            return res;
        }


        private int idx(int i, int j, int n) {
            return i * n + j;
        }

        private int dist(Point p1, Point p2) {
            return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y);
        }
    }

     class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

```