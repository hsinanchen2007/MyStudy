### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
int times = 0;
for(int i = 0; i < points.length-1; i++){
times += Math.max(Math.abs(points[i + 1][0] - points[i][0]), Math.abs(points[i + 1][1] - points[i][1]));
}
return times;
    }
}
```