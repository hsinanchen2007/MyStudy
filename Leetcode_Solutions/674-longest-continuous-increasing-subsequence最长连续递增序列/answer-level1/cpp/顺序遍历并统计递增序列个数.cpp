```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = 1;
        int mx = 1;
        if(nums.size() == 0)
        {
            return 0;
        }
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
            {
                n++;
            }
            else
            {
                n = 1;
            }
            if(n > mx)
            {
                mx = n;
            }
        }
        return mx;
    }
};
```
