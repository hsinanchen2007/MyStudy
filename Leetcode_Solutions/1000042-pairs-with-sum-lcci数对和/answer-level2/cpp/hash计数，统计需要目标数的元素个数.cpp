### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> res;
        unordered_map<int, int> m;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            auto it = m.find(nums[i]);
            if (it == m.end()) {
                ++m[target - nums[i]];
            } else {
                res.push_back({target - it->first, it->first});
                --it->second;
                if (it->second <= 0) {
                    m.erase(it);
                }
            }
        }
        return res;
    }
};
```