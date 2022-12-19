### 解题思路
先按结束点排序，然后使用贪心算法来射爆气球。

![image.png](https://pic.leetcode-cn.com/1b5534472f4814689ebf93793586ff74ce138f64437d3ca567566e35db3f5cb0-image.png)


### 代码

```java
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, Comparator.comparingInt(o -> o[1]));
        Integer pre = null;
        int result = 0;
        for (int i = 0; i < points.length; i++) {
            if (pre != null && points[i][0] <= pre) continue;
            pre = points[i][1];
            result ++;
        }
        return result;
    }
}
```