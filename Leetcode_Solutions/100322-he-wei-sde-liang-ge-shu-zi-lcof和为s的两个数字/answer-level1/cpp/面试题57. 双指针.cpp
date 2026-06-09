```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {       
        if (nums.size() <= 1)
            return {};
        int i = 0; 
        int j = nums.size() - 1;
        int sum = 0;
        while (i < j) {
            sum = nums[i] + nums[j];
            if (sum < target)
                i ++;
            else if (sum > target)
                j --;
            else
                return {nums[i], nums[j]};
        } 
        return {};
    }
};
```