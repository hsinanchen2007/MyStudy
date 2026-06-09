X2 - X1, Y2 - Y1 的最大值为必须走的距离,即斜线之后剩下的直线
```
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        if(points.length < 2){
            return points.length;
        }
        int count = 0;
        for(int i = 1; i < points.length; i++){
            count += Math.max(Math.abs(points[i][0] - points[i-1][0]), Math.abs(points[i][1] - points[i-1][1]));
        }
        return count;
    }
}
```
