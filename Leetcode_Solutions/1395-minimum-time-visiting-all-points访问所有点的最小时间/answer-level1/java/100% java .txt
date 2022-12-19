### 解题思路
the max(xdif,ydif) is the ans we need for point i and point i+1

### 代码

```java h
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int ans = 0;
        int xd; //x difference
        int yd; //y difference
        for(int i=0;i<(points.length)-1;i++){
            xd = Math.abs(points[i+1][0] - points[i][0]);
            yd = Math.abs(points[i+1][1] - points[i][1]);
            if(xd>=yd){ans = ans + xd;}
            else{ans = ans + yd;}
        }return ans;
    }
}
```