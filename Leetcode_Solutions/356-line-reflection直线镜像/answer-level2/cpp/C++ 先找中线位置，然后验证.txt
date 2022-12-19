找到中线位置的两倍值M进行点对称即可
```
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int left = INT_MAX;
        int right = INT_MIN;
        for (auto& point : points) {
            left = min(point[0], left);
            right = max(point[0], right);
        }
        double M = left + right; // 中线位置的两倍
        set<vector<int> > s(points.begin(), points.end());
        for (auto& point : points) {
            if (s.find({M - point[0], point[1]}) == s.end()) {
                return false;
            }
        }
        return true;
    }
};
```
![image.png](https://pic.leetcode-cn.com/525b5b3bb07b2c5b172bc98256902c0a38de595e91fe4fd19b5b7e38a52ed561-image.png)

