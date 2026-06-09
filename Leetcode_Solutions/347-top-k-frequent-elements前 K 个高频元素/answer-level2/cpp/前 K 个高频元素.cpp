### 解题思路
优先队列 priority_queue，本质是个堆
### 代码

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        priority_queue<pair<int,int> > pq;
        for(int i = 0; i < nums.size(); ++i) {
            record[nums[i]]++;
        }
        vector<int> res;
        for(auto item: record) {
            pq.push(make_pair(item.second, item.first));
        }
        for(int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
```