### 解题思路
1. 使用辗转相除法保证最简形式的除法。
2. 遍历每一个点，然后计算它和其余点的斜率，保存至map中，求出经过当前点的直线中，覆盖点最多的数目。
3. 对于每一个点，只计算与它之后的点的斜率，所以第二层遍历j=i+1.
4. 对于可能出现相同点的情况，使用一个变量保存，在最后计算点数目时加上。

### 代码

```java
class Solution {
    public int maxPoints(int[][] points) {
        if(points == null || points.length == 0 || points[0].length == 0) return 0;
        int res = 0, length = points.length;
        for(int i = 0; i < length; i++){
            int max = 0, dup = 0;
            Map<String, Integer> map = new HashMap<>();
            for(int j = i + 1; j < length; j++){
                int dy = points[i][1] - points[j][1];
                int dx = points[i][0] - points[j][0];
                if(dy == 0 && dx == 0){
                    dup++;
                    continue;
                }

                int g = gcd(dy, dx);
                dy /= g;
                dx /= g;
                String hs = dy + "/" + dx;
                map.put(hs, map.getOrDefault(hs, 0) + 1);
                max = Math.max(max, map.get(hs));
            }
            res = Math.max(res, max + dup + 1);
        }
        return res; 
    }
    private int gcd(int dy, int dx) {
        if (dx == 0) return dy;
        else return gcd(dx, dy % dx);
    }
}
```