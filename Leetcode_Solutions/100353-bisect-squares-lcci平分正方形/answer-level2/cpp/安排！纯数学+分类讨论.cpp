### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        // keypoint: 经过正方形中心点（垂心？）的直线面积平分正方形；
        // square1放置横坐标最小的点
        if (square1[0] > square2[0]) swap(square1, square2);

        // 求中心点
        double r1 = square1[2] / 2.0, r2 = square2[2] / 2.0;
        double x1 = square1[0] + r1, y1 = square1[1] + r1;
        double x2 = square2[0] + r2, y2 = square2[1] + r2;
        // 斜率不存在，下边确定，主要找上边；此处包含了中心相同有多组解求斜率最大的解
        if (x1 == x2) return {x1, y1 - r1, x1, max(y1 + r1, y2 + r2)};  
        else {
            double k = (y2 - y1) / (x2 - x1), b = y1 - k * x1;
            if (abs(k) <= 1) { // 斜率绝对值小于1， 与左右两边交
                double l = square1[0], r = max(x1 + r1, x2 + r2);
                return {l, k * l + b, r, k * r + b};
            } else { // 斜率绝对值大于1，与上下两边交
                double d = min(square1[1], square2[1]), u = max(y1 + r1, y2 + r2);
                double xd = (d - b) / k, xu = (u - b) / k;
                if (xd < xu || (xd == xu && d < u)) return {xd, d, xu, u};
                return {xu, u, xd, d};
            }
        }
    }
};
```