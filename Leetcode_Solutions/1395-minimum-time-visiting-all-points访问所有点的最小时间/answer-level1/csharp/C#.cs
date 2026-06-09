两点之间的距离就是x轴距离和y轴距离两者中大的一个
```
    public int MinTimeToVisitAllPoints(int[][] points) {
        int d = 0;
        for (int i = 0; i < points.Count() - 1; i++)
        {
            int dx = Math.Abs(points[i + 1][0] - points[i][0]);
            int dy = Math.Abs(points[i + 1][1] - points[i][1]);
            d += dx > dy ? dx : dy;
        }
        return d;
    }
```
