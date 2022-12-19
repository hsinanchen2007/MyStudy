### 解题思路
遍历数组，求两个坐标轴的绝对值大的那个，然后相加求和。

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        // 距离总计
        int sum = 0;
        // 遍历数组
        for(int i = 0; i < points.length - 1; i++) {
            // 坐标X的绝对值
            int X = Math.abs(points[i][0] - points[i+1][0]);
            // 坐标Y的绝对值
            int Y = Math.abs(points[i][1] - points[i+1][1]);
            if(X > Y) {
                sum = sum + X; 
            } else {
                sum = sum + Y;
            }
        }
        return sum;
    }
}
```