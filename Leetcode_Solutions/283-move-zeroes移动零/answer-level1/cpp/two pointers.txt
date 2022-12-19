```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for (i = 0; i < nums.size(); i ++) {
            if (nums[i] != 0)
                nums[j ++] = nums[i];
        }
        for (i = j; i < nums.size(); i ++)
            nums[i] = 0;
    }
};