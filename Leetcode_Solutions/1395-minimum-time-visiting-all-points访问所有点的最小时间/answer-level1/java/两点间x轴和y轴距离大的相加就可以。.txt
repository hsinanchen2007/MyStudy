### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int sum = 0;
        for (int i = 0; i < points.length - 1; i ++) {
            int[] point1 = points[i];
            int[] point2 = points[i+1];
            int x = Math.abs(point2[0] - point1[0]);
            int y = Math.abs(point2[1] - point1[1]);
            sum += Math.max(x, y);
        }
        return sum;
    }
}
```