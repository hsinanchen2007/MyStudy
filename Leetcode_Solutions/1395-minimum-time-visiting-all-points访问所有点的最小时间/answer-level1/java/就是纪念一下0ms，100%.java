```
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int res = 0;
        for(int i = 0;i<points.length-1;i++){
            res+=getMinTimeOfTwoPoints(points[i],points[i+1]);
        }
        return res;
    }
    private int getMinTimeOfTwoPoints(int[] point1,int[] point2){
        int x = Math.abs(point1[0]-point2[0]);
        int y = Math.abs(point1[1]-point2[1]);
        return x>y?x:y;
    }
}
```
![p1266.png](https://pic.leetcode-cn.com/0756309072753adfd11e81cc25925480096a775eb63bd04554dd7ca69c575204-p1266.png)
