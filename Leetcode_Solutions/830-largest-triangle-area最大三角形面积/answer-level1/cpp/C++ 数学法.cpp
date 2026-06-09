根据坐标面积计算公式可查阅矩阵相关知识
```
class Solution {
public:
    double area(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
        int dx1 = p2[0] - p1[0];
        int dx2 = p3[0] - p1[0];
        int dy1 = p2[1] - p1[1];
        int dy2 = p3[1] - p1[1];
        return abs(dx1 * dy2 - dx2 * dy1) / 2.0;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int N = points.size();
        double res = 0;
        for (int i = 0; i < N - 2; ++i) {
            for (int j = i + 1; j < N - 1; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    res = max(res, area(points[i], points[j], points[k]));
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/028da8de30b4c3a90118fc15368402971857017fbbcce866ae6861cff57d72aa-image.png)
