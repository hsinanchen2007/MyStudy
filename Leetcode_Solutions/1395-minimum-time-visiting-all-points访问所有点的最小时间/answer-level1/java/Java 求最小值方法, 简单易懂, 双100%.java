代码如下:
```java
class Solution {

    public int minTimeToVisitAllPoints(int[][] points) {
        int min = 0;
        for (int i = 1; i < points.length; ++i)
            min += findMinStep(points[i - 1][0], points[i - 1][1], points[i][0], points[i][1]);
        return min;
    }

    private static int findMinStep(int x1, int y1, int x2, int y2) {
        int minSlope = Math.min(Math.abs(x1 - x2), Math.abs(y1 - y2));
        return Math.abs(x1 - x2) + Math.abs(y1 - y2) - minSlope;
    }
}
```
1. 先计算移动到同一行或同一列所需最少步数: `Math.min(Math.abs(x1 - x2), Math.abs(y1 - y2))`
2. 然后计算整体步数: 整体步数 = (x方向移动 - 最小步数) + (y方向移动 - 最小步数) + 最小步数, 化简完即为: Math.abs(x1 - x2) + Math.abs(y1 - y2) - minSlope