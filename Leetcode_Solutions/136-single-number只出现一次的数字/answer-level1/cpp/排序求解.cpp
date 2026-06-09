`class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0)
            throw;
        // special case
        if(nums.size() == 1)
            return nums[0];
        
        // main function
        sort(nums.begin(), nums.end());
        int i = 0;
        for(; i <= nums.size() - 3; i = i + 2){
            if(nums[i] != nums[i+1])
                break;
        }
        return nums[i];
    }
};`c++