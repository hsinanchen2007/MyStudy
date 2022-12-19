```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            if(nums[l] < target - nums[r]) l++;
            else if(nums[l] > target - nums[r]) r--;
            else return {nums[l], nums[r]};
        }
        return {};
    }
};
```
