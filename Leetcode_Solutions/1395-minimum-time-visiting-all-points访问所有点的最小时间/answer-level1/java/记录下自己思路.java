   记录下思路：首先明确，一个任意的点，直线上下左右移动，坐标会对应x+1，x-1，y-1，y+1；
   右上对角线移动坐标x+1，y+1；右下是x+1，y-1；左上x-1，y+1；左下x-1，y-1；
   A点到B点，可由B点相应坐标-A点相应坐标，得的值可理解为两个点的距离，此距离根据上边
   所述的移动规则以最小的步数把此距离变为[0,0]，则可知两点最少的步数是距离中两个数绝对值最大那个


```
    public int minTimeToVisitAllPoints(int[][] points) {
        int sum=0;
        int x=0;
        int y=0;
        for (int i=0;i<points.length-1;i++){
            x=points[i+1][0]-points[i][0];
            y=points[i+1][1]-points[i][1];
            sum+= Math.abs(x)>Math.abs(y) ? Math.abs(x) : Math.abs(y);
        }
        return sum;

    }
```

    