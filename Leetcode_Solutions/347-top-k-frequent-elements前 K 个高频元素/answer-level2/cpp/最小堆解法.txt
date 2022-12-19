### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        for (auto &n : nums) freq[n]++;

        priority_queue<pair<int, int>,  // min_heap
                vector<pair<int, int>>, 
                greater<pair<int, int>>> pq;

        for (auto it = freq.begin(); it != freq.end(); it++) {

            if (pq.size() < k) {
                pq.emplace(it->second, it->first);
                continue;
            }

            if (it->second > pq.top().first) {
                pq.pop();
                pq.emplace(it->second, it->first);
            }
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            ans.emplace_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
```