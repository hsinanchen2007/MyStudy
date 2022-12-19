class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int loop;
        int size = nums.size();
        
        for (loop = 0; loop < size; loop++) {
            nums[loop] = a * nums[loop] * nums[loop] + b * nums[loop] + c;
        }
        
        std::sort (nums.begin(), nums.end(), less<int>()); 
        return nums;
    }
};