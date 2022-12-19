### 解题思路
要最短时间，即可以走斜边就走斜边
斜边的的次数实际为两条边中比较短的边行走的次数
斜边之外的时间即长边减去短边之外的长度行走的时间
综上：只需要计算两条边中的长边即为行走的时间
### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int sum=0;
        for(int i=1;i<points.length;i++){
            sum+=Math.max(Math.abs(points[i][0]-points[i-1][0]),Math.abs(points[i][1]-points[i-1][1]));
        }
        return sum;
    }
}
```