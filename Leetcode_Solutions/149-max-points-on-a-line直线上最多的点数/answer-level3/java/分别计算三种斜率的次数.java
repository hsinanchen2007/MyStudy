## 1.最外层循环用于固定该点(x1,y1)，并统计横坐标一样和纵坐标一样的点出现的次数，也就是计算同一水平和垂直线点的个数。
## 2.内层循环用于计算(x2,y2)和(x1,y1)的斜率，并放入 subMap。
2.1 统计当前的(x2,y2)和(x1,y1)是否重合，重合的话 repeat++，continue 循环
2.2 统计当前的(x2,y2)和(x1,y1)是否包含一样的横坐标或纵坐标，包含的 continue 循环
2.3 计算两个点的斜率，判断该斜率是否在之前的外层循环计算过，同一种斜率只需要计算一遍，通过 HashSet 集合统计，斜率类型为 Double
2.4 如果两个点的斜率在之前的外层循环中位计算过，更新当前斜率在 subMap 中出现的次数，更新当前内循环的中斜率出现次数的最大值 currentMax
## 3.内存循环全部结束之后
3.1 更新最大值 result = Max(result，同一水平的点出现的次数，同一垂直的点出现的次数)
3.2 更新最大值 result = Max(result, 内存循环出现斜率的最大次数+重复的次数)
3.3 将 subMap 统计过的斜率加入 HashSet

```java
class Solution {
    public int maxPoints(int[][] points) {
        int result = 0;

        // 斜线的斜率
        Set<Double> slopeSet = new HashSet<>();
        // 横坐标一样的斜率
        Map<Integer, Integer> xSlopeMap = new HashMap<>();
        // 纵坐标一样的斜率
        Map<Integer, Integer> ySlopeMap = new HashMap<>();

        for (int i = 0; i < points.length; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            xSlopeMap.put(x1, xSlopeMap.getOrDefault(x1, 0) + 1);
            ySlopeMap.put(y1, ySlopeMap.getOrDefault(y1, 0) + 1);

            int repeat = 0;
            int currentMax = 0;
            Map<Double, Integer> subMap = new HashMap<>();
            for (int j = i + 1; j < points.length; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                // 统计重复的点的数量
                if (x1 == x2 && y1 == y2) {
                    repeat++;
                    continue;
                }
                // 除去横坐标或纵坐标一样的点
                if (x1 == x2 || y1 == y2) {
                    continue;
                }
                // 计算斜率
                double k = (x1 - x2) * 1.0 / (y1 - y2);
                // 判断斜率是否计算过
                if (slopeSet.contains(k)) {
                    continue;
                }
                // 更新当前循环一样的点出现的次数
                subMap.put(k, subMap.getOrDefault(k, 1) + 1);
                currentMax = Math.max(currentMax, subMap.get(k));
            }
            result = Math.max(result, Math.max(xSlopeMap.get(x1), ySlopeMap.get(y1)));
            result = Math.max(result, currentMax + repeat);
            slopeSet.addAll(subMap.keySet());
        }

        return result;
    }
}
```

