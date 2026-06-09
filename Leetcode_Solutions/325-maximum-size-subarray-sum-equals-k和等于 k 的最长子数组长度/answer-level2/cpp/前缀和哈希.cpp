### 解题思路
用两个哈希表记录每一个前缀和第一次和最后一次出现的序号。

### 代码

```cpp
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        vector<int> sum = {0};
        unordered_map<int, int> lo, hi;
        lo[0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            int num = nums[i - 1];
            sum.emplace_back(sum.back() + num);
            int new_sum = sum.back();
            if (lo.find(new_sum) == lo.end())
                lo[new_sum] = i;
            hi[new_sum] = i;
        }
        int ans = 0;
        for (auto [num, first] : lo)
            if (hi.find(num + k) != hi.end())
                ans = max(ans, hi[num + k] - first);
        return ans;
    }
};
```