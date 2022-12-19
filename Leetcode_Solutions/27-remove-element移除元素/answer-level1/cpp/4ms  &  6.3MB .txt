class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int len = nums.size();
        int flag = len;
        for(int i = 0; i < len; i++)
        {
            if(val == nums[i])
            {
                for(int j = i+1; j < len; j++)
                {
                    nums[j-1] = nums[j];
                }
                len--;
                i--;
            }
        }
        return len;
    }
};