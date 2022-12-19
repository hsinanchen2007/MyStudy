class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int max = nums[0];
        int sum = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(sum + nums[i] <= 0)
            {
                sum = 0;
                if(nums[i] > max)
                    max = nums[i];
            }
            else
            {
                sum += nums[i];
                if(sum > max)
                    max = sum;
            }
        }
        return max;
    }
};