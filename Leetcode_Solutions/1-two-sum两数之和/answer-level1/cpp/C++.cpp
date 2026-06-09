### 解题思路
使用哈希表记录

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int size = nums.size();
        if (size <= 1) {
            return ans;
        }
        map<int, int> mp;
        for (int i = 0; i < size; i++) {
            if (mp.count(target - nums[i]) && mp[target - nums[i]] != i) {
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                break;
            } else {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};
```