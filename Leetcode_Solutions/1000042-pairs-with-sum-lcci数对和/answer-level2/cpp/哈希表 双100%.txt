### 解题思路
注意num[i] == target - num[i]的情况

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (auto n : nums)
            mp[n]++;
        for (auto n : nums)
            if (--mp[n] >= 0 && --mp[target - n] >= 0)
            {
                ans.push_back({n, target - n});
                //mp[n]--, mp[target - n]--;
            }
        return ans;
    }
};
```