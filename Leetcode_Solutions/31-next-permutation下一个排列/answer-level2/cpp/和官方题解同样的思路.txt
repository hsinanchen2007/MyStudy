从后往前找到nums[i] > nums[i - 1]的点。
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto i = 0;
        for (i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                int j = i;
                while (j < (nums.size() - 1)) {
                    if (nums[j] <= nums[i - 1]) {
                        swap(nums[j - 1], nums[i - 1]);
                        reverse(nums.begin() + i, nums.end());
                        return;
                    } 
                    j++;
                }
                if (nums[j] <= nums[i - 1]) {
                    swap(nums[j - 1], nums[i - 1]);
                    reverse(nums.begin() + i, nums.end());
                    return;
                } 
                swap(nums[j], nums[i - 1]);
                reverse(nums.begin() + i, nums.end());
                return;
            }    
        }
        
        sort(nums.begin(), nums.end());
    }
};