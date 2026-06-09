### 解题思路
当前一个点与后一个点在某一条对角线上，则直接按照对角线访问，距离是两个点的差。
若不在对角线上，所需的时间是后一个点的x，y值减去前一个点的x，y值得最大值max[(x2-x1),(y2-y1)]
(小菜鸟分享思路，有错误大家帮忙指出哦，捂脸逃emm~)
### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int time=0;
        for(int i=0;i<points.length-1;i++){
            for(int j=0;j<points[0].length-1;j++){
                if(points[i+1][j]-points[i][j]==points[i+1][j+1]-points[i][j+1])
                    time+=Math.abs(points[i+1][j]-points[i][j]);
                else
                   {
                        time+=Math.max(Math.abs(points[i+1][j]-points[i][j]),Math.abs(points[i+1][j+1]-points[i][j+1]));
                    }
            }
        }
        return time;
    }
}
```