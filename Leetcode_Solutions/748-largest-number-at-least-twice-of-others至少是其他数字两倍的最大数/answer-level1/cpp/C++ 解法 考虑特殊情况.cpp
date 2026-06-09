class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> v = nums;
        sort(nums.begin(), nums.end());
        if(nums.size() == 1) return  0;
        if(nums[nums.size()-2] == 0 || nums[nums.size()-1] / nums[nums.size()-2] >= 2)
            return find(v.begin(), v.end(), nums[nums.size()-1])-v.begin();
        return -1;
    }
};