```
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return find(nums, 0, S);
    }
    
    int find(vector<int> &nums, int i, long sum)
    {
        if (i == nums.size() - 1)
            return (sum == nums[i]) + (sum == -nums[i]);
        return find(nums, i+1, sum - nums[i]) + find(nums, i+1, sum + nums[i]);
    }
};
```
