```
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int sum = 0;
        for (int i = 1; i < points.length; i++) {
            int[] point = points[i];
            int[] pointAhead = points[i - 1];
            int absX = Math.abs(point[0] - pointAhead[0]);
            int absY = Math.abs(point[1] - pointAhead[1]);
            sum += Math.max(absX, absY);
        }

        return sum;
    }
}
```
