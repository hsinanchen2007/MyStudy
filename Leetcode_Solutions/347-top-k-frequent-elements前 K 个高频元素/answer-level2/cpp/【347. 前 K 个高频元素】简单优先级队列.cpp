## 思路
### 代码
```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {        
        if (nums.empty()) return {};
        int size = nums.size();
        unordered_map<int, int> umap;
        for (int n : nums) {
            ++umap[n];
        }
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int)umap.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};
```
