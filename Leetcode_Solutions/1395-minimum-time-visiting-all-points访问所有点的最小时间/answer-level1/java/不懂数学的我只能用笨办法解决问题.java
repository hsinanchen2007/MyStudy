```
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int time = 0;
        int points_count = points.length;
        int [] p = {-1001, 1001};
        for (int i = 0; i < points_count; ++i) {
            if (p[0] == -1001 && p[1] == 1001) {
                p[0] = points[i][0];
                p[1] = points[i][1];
                continue;
            }
            while (p[0] != points[i][0] || p[1] != points[i][1]) {
                if (p[0] > points[i][0]) {
                    --p[0];
                } else if (p[0] < points[i][0]) {
                    ++p[0];
                }
                if (p[1] > points[i][1]) {
                    --p[1];
                } else if (p[1] < points[i][1]) {
                    ++p[1];
                }
                ++time;
            }
        }
        return time;
    }
}
```
