```
/**
* 思路：根据题意：能走对角线则优先走对角线。那么相邻两点P0(x0,y0),P1(x1,y1)之间的距离，有以下三种情况：
* （1）若dx < dy, 则dx + (dy - dx) = dy
* （2）若dx = dy, 则dx
* （3）若dx > dy, 则dy + (dx - dy) = dx
* 总之：相邻两点距离 = max(dx,dy)
*/
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            int x0 = points[i][0], y0 = points[i][1];
            int x1 = points[i+1][0], y1 = points[i+1][1];
            res += max(abs(x1 - x0), abs(y1 - y0));
        }
        return res;
    }
};


```