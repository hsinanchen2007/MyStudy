java 1ms 破解

```
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int count = 0;
        for (int i=0; i<points.length-1; i++) {
            int left = points[i][0] - points[i+1][0] > 0 ? points[i][0] - points[i+1][0]: points[i+1][0] - points[i][0];
            int right = points[i][1] - points[i+1][1] > 0 ? points[i][1] - points[i+1][1]: points[i+1][1] - points[i][1];
            count += left > right ? left : right;
        }
        
        return count;
    }
}
```