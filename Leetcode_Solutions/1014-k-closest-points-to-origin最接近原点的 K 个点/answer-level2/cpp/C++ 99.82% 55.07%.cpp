```
class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int len = points.size();
        vector<pair<int, int>> v(len);
        for (int i = 0; i < points.size(); i++) {
            v[i].first = i;
            v[i].second = pow(points[i][0], 2) + pow(points[i][1], 2);
        }
        sort(v.begin(), v.end(), cmp);
        vector<vector<int>> res;
        for (int i = 0; i < K; i++) {
            res.push_back(points[v[i].first]);
        }
        return res;
    }
};
```
