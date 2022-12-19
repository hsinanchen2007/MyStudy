### 解题思路

基本思路是每条斜率对应一条线

需要注意的是，计算斜率的时候用gcd保存，不能用dy / dx

### 代码

```java
class Solution {
    public int maxPoints(int[][] points) {
        if (points == null) return 0;
        int res = 0;
        if (points.length < 3) return points.length;
        for (int i = 0; i < points.length; i ++) {
            int overlap = 0;
            int max = 0;
            Map<Integer, Map<Integer, Integer>> m = new HashMap<>();
            for (int j = i + 1; j < points.length; j ++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {
                    overlap ++;
                    continue;
                }
                int dx = x2 - x1;
                int dy = y2 - y1;
                                
                int gcd = gcd(dx, dy);
                if (gcd != 0) {
                    dx /= gcd;
                    dy /= gcd;
                } 
                Integer cur = m.computeIfAbsent(dx, k -> new HashMap<Integer, Integer>()).getOrDefault(dy, 0);
                m.get(dx).put(dy, cur + 1);
                max = Math.max(max, cur + 1);
            }
            res = Math.max(res, max + overlap + 1);
        }
        return res; 
    }

    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
}
```