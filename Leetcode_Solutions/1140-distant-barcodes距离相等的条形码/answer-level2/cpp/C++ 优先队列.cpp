```
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int N = barcodes.size();
        map<int, int> m;
        for (auto i : barcodes) ++m[i];
        priority_queue<pair<int, int> > pq;
        for (auto& p : m) pq.push({p.second, p.first});
        vector<int> res(N);
        int i = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            for (int j = 0; j < p.first; ++j) {
                res[i] = p.second;
                i = (i + 2 >= N) ? 1 : i + 2; // 隔一位填充一个
            }
        }
        return res;
    }
};
```
