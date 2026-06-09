# 相关题目
[149. 直线上最多的点数](https://leetcode-cn.com/problems/max-points-on-a-line/)

# 代码
```java
class Solution {
    int[][] points;
    HashMap<Double, Integer> lines = new HashMap<>();
    HashMap<Double, int[]> pairs = new HashMap<>();
    int horizontal_lines, points_num, count, duplicates;
    int[] pair, horizontal_pair;

    public int[] bestLine(int[][] points) {
        this.points = points;
        points_num = points.length;
        if (points_num < 3) return new int[]{0, 1};
        int max_count = 1;
        int[] res = new int[0];
        for (int i = 0; i < points_num - 1; ++i) {
            int val = max_points_on_a_line_containing_point_i(i);
            if (max_count < val) {
                max_count = val;
                res = pair;
            }
        }
        return res;
    }

    public int max_points_on_a_line_containing_point_i(int i) {
        lines.clear();
        pairs.clear();
        horizontal_lines = 1;
        count = 1;
        duplicates = 0;
        pair = null;
        for (int j = i + 1; j < points_num; ++j)
            add_line(i, j);

        return count + duplicates;
    }

    public void add_line(int i, int j) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        if ((x1 == x2) && (y1 == y2))
            ++duplicates;
        else if (y1 == y2) {
            if (horizontal_lines < 2)
                horizontal_pair = new int[]{i, j};
            if (count < ++horizontal_lines) {
                count = horizontal_lines;
                pair = horizontal_pair;
            }
        } else {
            double slope = 1.0 * (x1 - x2) / (y1 - y2) + 0.0;
            if (!pairs.containsKey(slope))
                pairs.put(slope, new int[]{i, j});
            lines.put(slope, lines.getOrDefault(slope, 1) + 1);
            if (count < lines.get(slope)) {
                count = lines.get(slope);
                pair = pairs.get(slope);
            }
        }
    }
}
```
