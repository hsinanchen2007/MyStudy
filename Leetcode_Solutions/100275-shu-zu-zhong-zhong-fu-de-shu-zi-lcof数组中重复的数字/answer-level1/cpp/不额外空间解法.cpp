class Solution {
public:
    void swap(int &a,int &b)
    {
        int temp = a;
        a = b;
        b = temp;

    }
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                else
                    swap(nums[i],nums[nums[i]]);
            }
        }
         return 0;
    }
   
};