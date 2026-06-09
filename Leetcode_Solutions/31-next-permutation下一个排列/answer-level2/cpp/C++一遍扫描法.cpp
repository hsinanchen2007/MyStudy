class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int flag = 0;
        int i = nums.size() - 1;
        for(; i > 0; i--)
        {
            if(nums[i - 1] < nums[i])
            {
                flag = i - 1;
                break;
            }
        }
    
        if(i == 0)//不存在下一个更大排列
            sort(nums.begin(),nums.end());//重新排成最小排列
        else
        {
            sort(nums.begin() + i,nums.end());
            int j = i;
            for(; j < nums.size(); j++)
                if(nums[j] > nums[flag]) break;//找到刚好大于a[flag]的数
            //交换两个数
            int t = nums[flag];
            nums[flag] = nums[j];
            nums[j] = t;
        }
    }
};