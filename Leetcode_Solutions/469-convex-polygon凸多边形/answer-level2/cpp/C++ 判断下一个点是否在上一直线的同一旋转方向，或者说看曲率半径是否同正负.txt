```
class Solution {
public:
    struct Line {
        int x, y, dx, dy;
        Line(int x1, int y1, int x2, int y2) : x(x1), y(y1), dx(x2 - x1), dy(y2 - y1) {}
    };
    int pLine(int x, int y, const Line& line) {
        int t = (y - line.y) * line.dx - (x - line.x) * line.dy;
        if (t == 0) return 0;
        return t > 0 ? 1 : -1;
    }
    bool isConvex(vector<vector<int>>& points) {
        int N = points.size();
        int rotate = 0;
        for (int i = 0; i < N; ++i) {
            int j = (i + 1) % N;
            int k = (j + 1) % N;
            Line line = Line(points[i][0], points[i][1], points[j][0], points[j][1]);
            int t = pLine(points[k][0], points[k][1], line);
            if (t == 0) continue;
            if (rotate == 0) {
                rotate = t;
            } else if (rotate != t) {
                return false;
            }
        }
        return true;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ad6f0b83b646830dbecdaf5ea16bf632605fd6ed955a831fcc29b7f7927316bf-image.png)
