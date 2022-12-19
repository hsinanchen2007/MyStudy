class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCont = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zeroCont++;
            }
            else
            {
                nums[i-zeroCont] = nums[i];
            }
        }
        for(int i = 0; i < zeroCont; i++)
        {
            nums[nums.size()-1-i] = 0;
        }
    }
};
























