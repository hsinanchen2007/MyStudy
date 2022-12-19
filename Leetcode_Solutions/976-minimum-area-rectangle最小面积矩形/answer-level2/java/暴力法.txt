```java
class Solution {
    public int minAreaRect(int[][] points) {
        Set<Point> set = new HashSet<>();
        for (int[] point : points) {
            set.add(new Point(point[0], point[1]));
        }
        int minArea = Integer.MAX_VALUE;
        for (int i = 0; i < points.length; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.length; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 || y1 == y2) {
                    continue;
                }
                Point p1 = new Point(x1, y2);
                Point p2 = new Point(x2, y1);
                if (set.contains(p1) && set.contains(p2)) {
                    minArea = Math.min(minArea, Math.abs(x2 - x1) * Math.abs(y2 - y1));
                }
            }
        }
        return minArea == Integer.MAX_VALUE ? 0 : minArea;
    }

    static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Point)) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            return y == point.y;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }

}
```
