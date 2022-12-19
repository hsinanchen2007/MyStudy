### 解题思路
请直接看代码

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                return {m[nums[i]],nums[i]};
            }else
            {
                m[target-nums[i]] = nums[i];
            }
        }
        return {};
    }
};
```