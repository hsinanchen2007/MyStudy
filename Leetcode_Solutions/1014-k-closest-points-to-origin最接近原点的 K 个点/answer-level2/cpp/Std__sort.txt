### 解题思路
直接采用系统内置的sort来进行排序，自己进行排序的化，如果是遍历的话，会超时。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        map<vector<int>, double> maps;
        for (size_t i = 0; i < points.size(); i++) {
            maps[points[i]] = pow(points[i][0], 2) + pow(points[i][1], 2);
        }
        vector<pair<vector<int>, double>> pMaps(maps.begin(), maps.end());
        std::sort(pMaps.begin(), pMaps.end(),
                  [](const pair<vector<int>, double> &point1, const pair<vector<int>, double> &point2) {
                      return point1.second < point2.second;
                  });
        vector<vector<int>> vecResult;
        for (int i = 0; i < K; i++) {
            vecResult.push_back(pMaps[i].first);
        }
        return vecResult;
    };
};
```