### 解题思路
显然，执行时间上还需要优化。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            auto iterator = mp.find(target - nums[i]);

            if(iterator != mp.end()) {
                return {iterator->first, nums[i]};
            } else {
                mp[nums[i]] = i;
            }
        }

        return {};

    }
};
```