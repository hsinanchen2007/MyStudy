## 思路
遍历每个点，通过斜率相等判断是否与其它点在同一条直线上。分为三种情况：
- 相同点
- x点坐标相同，即与x轴垂直
- 正常求斜率

**注意：long double防止精度丢失**

### 代码
时间复杂度：O(n^2)
```c++
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<long double, int> umap;
            int samePoint = 1;
            for (int j = i + 1; j < points.size(); ++j) {                
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++samePoint;
                } else if (points[i][0] == points[j][0]) {
                    ++umap[INT_MAX];
                } else {
                    long double slope = (long double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    ++umap[slope];
                }
            }
            //求当前点在一条直线上最大点数
            int localMax = 0;
            for (auto it = umap.begin(); it != umap.end(); ++it) {
                localMax = max(localMax, it->second);
            }
            localMax += samePoint;
            //更新最终结果
            res = max(res, localMax);
        }
        return res;
    }
};
```
