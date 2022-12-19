```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int res=0;
        int max_num=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                res=res+1;
                max_num=max(max_num,res);
            }
            else
            {
                res=0;
            }
        }
        return max_num;
    }
};
```
