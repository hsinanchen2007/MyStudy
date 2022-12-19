```
class Solution {
public:
    // 基于大根堆的滑动窗口方法
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> hp;
        for (int i = 0; i < points.size(); i++)
        {
            int sum = pow(points[i][0], 2) + pow(points[i][1], 2);
            if (hp.size() < K)
                hp.push({sum, i});
            else
            {
                if (sum < hp.top().first)
                {
                    hp.pop();
                    hp.push({sum, i});
                }
            }
        }
        while (hp.size())
        {
            res.push_back(points[hp.top().second]);
            hp.pop();
        }
        return res;
    }
};
```
