### 解题思路
JAVA 贪心算法，找交集

### 代码

```java
class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points == null || points.length == 0) {
            return 0;
        }
        Arrays.sort(points, (e1, e2) -> e1[0] != e2[0] ? e1[0] - e2[0] : e1[1] - e2[1]);
        int result = 1;
        int next = points[0][1];
        for (int i = 1; i < points.length; i++) {
            if (next >= points[i][0]) {
                next = Math.min(next, points[i][1]);
            } else {
                next = points[i][1];
                result++;
            }
        }
        return result;
    }
}
```