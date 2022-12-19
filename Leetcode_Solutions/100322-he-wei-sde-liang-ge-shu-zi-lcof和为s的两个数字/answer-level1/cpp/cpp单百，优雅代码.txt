### 解题思路
思路是双指针，代码优雅

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0,j = nums.size()-1;
        for(;i<j;){
            if(nums[i] + nums[j] == target) return {nums[i], nums[j]};
            if(nums[i] + nums[j] < target) i++;
            if(nums[i] + nums[j] > target) j--;
        }
        return {nums[i], nums[j]};
    }
};
```