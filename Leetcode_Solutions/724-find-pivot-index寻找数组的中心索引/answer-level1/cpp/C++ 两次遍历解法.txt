```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 求数组中所有元素之和
        int sum = 0;
        for (int item : nums)
            sum += item;

        int sum_left = 0;
        for (int i=0; i<nums.size(); i++) {
            if (sum_left == sum - sum_left - nums[i])
                return i;
            sum_left += nums[i];
        }
        
        return -1;
    }
};
```
