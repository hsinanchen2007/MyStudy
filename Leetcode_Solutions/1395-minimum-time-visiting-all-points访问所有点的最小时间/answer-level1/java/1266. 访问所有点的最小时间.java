```
class Solution {
    /*
        两点的坐标关系分为以下三种：
        1. 两点构成正方形，则存在对角线路径最短，用时等同于沿一边的行进的用时。
        2. 两点构成一条线，则路径为线的长度。
        3. 两点构成矩形，假设|x1-x2|<|y1-y2|,则最短路径为先沿边长为|x1-x2|的正方形对角线行进，再沿y轴方向行进。

        三种情况归纳可得，最短时间等效于横纵坐标差值绝对值较大的那个值。
    */
    public int minTimeToVisitAllPoints(int[][] points) {
        int time = 0;
        for(int i=0; i<points.length-1; i++){
                time += Math.max(Math.abs(points[i+1][0]-points[i][0]),Math.abs(points[i+1][1]-points[i][1]));
        }
        return time;
    }
}
```
