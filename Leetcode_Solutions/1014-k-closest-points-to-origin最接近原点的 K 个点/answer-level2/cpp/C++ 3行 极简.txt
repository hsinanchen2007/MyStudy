![image.png](https://pic.leetcode-cn.com/5b3c858a31be5db9ef71f489c2e85aa0524e85503245933e3c70079accd424c1-image.png)

思路：
先排序，然后保留前k个

```
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [] (auto& x, auto& y) { return x[0] * x[0] + x[1] * x[1] < y[0] * y[0] + y[1] * y[1]; });
        points.resize(K);
        return points;
    }
};
```
