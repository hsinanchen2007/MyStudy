### 解题思路
三角形面积area = a*b*sin(theta) / 2; 
A = 平方(a*b*sin(theta)) = (4*b*b*c*c - (a*a - b*b - c*c)的平方) / 4
故 area = sqrt(A) / 2;
另在求面积之前需要判断是否可以组成一个三角形；
判断的标准是找出最小的两个边长，看是否最小的两边长大于最大边，如果是，则可以求面积；

### 代码

```cpp
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0.0;
        }
        double max_erea = 0;
        int f = 0, s = 1, t = 2;
        Permute(points, f, s,t, max_erea);
        return sqrt(max_erea) / 2;
    }
    void Permute(vector<vector<int>>& points, int f, int s, int t, double& area) {
        if (f < points.size() && t < points.size() && t < points.size()) 
        MaxArea(points[f], points[s], points[t], area);
        t += 1;
        if (t >= points.size()) {
            s += 1;
            t = s + 1;
        }
        if (s >= points.size()) {
            f += 1;
            s = f + 1;
            t = s + 1;
        } 
        if (f >= points.size()) {
            return ;
        }
        Permute(points, f, s, t, area);
    }
    void MaxArea(const vector<int>&f, const vector<int>& s, const vector<int>& t, double& area) {
        double a2 = (f[0] - s[0]) * (f[0] - s[0]) + (f[1] - s[1]) * (f[1] - s[1]);
        double b2 = (f[0] - t[0]) * (f[0] - t[0]) + (f[1] -  t[1]) * (f[1] - t[1]);
        double c2 = (s[0]- t[0]) * (s[0]- t[0]) + (s[1] - t[1]) * (s[1] - t[1]);
        if (NotAngle(sqrt(a2), sqrt(b2), sqrt(c2))) {
            return ;
        }
        double x = a2 - b2 - c2;
        double temp = 4 * b2 * c2 - x * x;
        temp /= 4;
        if (area < temp) {
            area = temp;
        }
        
    }
    bool NotAngle(const double a, const double b, const double c) {
        double f = max(a, max(b, c));
        double s = a + b + c - f;
        return s <= f;
    }
};
```