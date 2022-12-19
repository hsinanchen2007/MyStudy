```
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int len = points.size(), x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        long long cur = 0, pre = 0;
        for (int i = 0; i < len; i++) {
            x1 = points[(i+1) % len][0] - points[i][0];
            x2 = points[(i+2) % len][0] - points[i][0];
            y1 = points[(i+1) % len][1] - points[i][1];
            y2 = points[(i+2) % len][1] - points[i][1];
            cur = x1 * y2 - x2 * y1;
            if (cur != 0 && cur * pre < 0) return false;
            if (cur != 0) pre = cur;
        }
        return true;
    }
};
```
