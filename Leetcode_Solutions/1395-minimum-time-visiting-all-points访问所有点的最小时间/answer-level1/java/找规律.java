### 解题思路
找张纸随便画画就能找到规律了，先算出dx和dy，分别求绝对值，然后分情况做判断，看了题解才知道原来这叫切比雪夫距离

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int len = points.length;
        if (len == 0 || len == 1) return 0;
        int res = 0;
        for (int i = 0; i < len - 1; i++) {
            int x = points[i][0] - points[i + 1][0];
            int y = points[i][1] - points[i + 1][1];
            if (x < 0) x = -x;
            if (y < 0) y = -y;
            res += Math.max(x, y) - Math.min(x, y) + Math.min(x, y);
        }
        return res;
    }
}
```