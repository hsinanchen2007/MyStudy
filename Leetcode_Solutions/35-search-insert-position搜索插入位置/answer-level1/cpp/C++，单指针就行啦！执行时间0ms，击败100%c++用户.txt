class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return 0;
    int i = 0;
    while(i < nums.size() && target > nums[i])
        i++;
    return i;
    }
};