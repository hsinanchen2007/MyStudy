### 解题思路
计算出每个海洋区域到陆地区域的最短距离，然后取其中最大的距离。
先将陆地区域的坐标保存到容器中，然后遍历每个海洋区域，对每个海洋区域，遍历容器中的陆地区域，取得最小的距离。从计算出的最小距离中获得最大的距离。

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        List<int[]> lands = new ArrayList<>();
        int i = 0, j = 0, k = 0;
        for (i = 0; i < grid.length; i ++) {
            for (j = 0; j < grid[i].length; j ++) {
                if (grid[i][j] == 1) {
                    lands.add(new int[]{i, j});
                }
            }
        }

        int ans = -1, dist = 0;
        for (i = 0; i < grid.length; i ++) {
            for (j = 0; j < grid[i].length; j ++) {
                if (grid[i][j] == 1) continue;
                dist = Integer.MAX_VALUE;
                for (k = 0; k < lands.size(); k ++) {
                    dist = Math.min(dist, mdDist(lands.get(k), i, j));
                }
                ans = Math.max(ans, dist == Integer.MAX_VALUE ? -1 : dist);
            }
        }
        return ans;
    }

    private int mdDist(int[] land, int x, int y) {
        return Math.abs(land[0] - x) + Math.abs(land[1] - y);
    }
}
```