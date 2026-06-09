### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        //取两个平面上不同的点，所花的时间实际就是两个点横坐标差与纵坐标差各取绝对值中较大的一个
        int n=points.length;  //点的个数
        int res=0;
        for(int i=1;i<n;i++)  //初始位置已经在第一个点上了
            res+=Math.max(Math.abs(points[i][0]-points[i-1][0]),Math.abs(points[i][1]-points[i-1][1]));
        return res;
    }
}
```