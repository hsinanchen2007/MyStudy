### 解题思路

思路很直观：首先用哈希表统计每个元素出现的次数，然后构建一个最大堆，移除k次堆顶元素即是想要结果。

### 代码

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (const auto& n : nums) {
            if (counter.find(n) == counter.end()) counter[n] = 1;
            else counter[n]++;
        }
        using my_pair_t = pair<int, int>;
        using my_container_t = vector<my_pair_t>;
        auto my_cmp = [] (const my_pair_t& left, const my_pair_t& right) {
            return left.second < right.second;
        };
        priority_queue<my_pair_t, my_container_t, decltype(my_cmp)> q(my_cmp);
        for (const auto& p : counter) q.push(p);
        vector<int> res;
        while (k--) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};
```