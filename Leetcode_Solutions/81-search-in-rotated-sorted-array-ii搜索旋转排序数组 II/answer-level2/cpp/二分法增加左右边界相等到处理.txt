```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        int m = 0;
        while(i<=j)
        {
            m = (i+j)/2;
            if(nums[m] == target)
                return true;
            else if(nums[m] == nums[i])
            {
                i++;
            }
            else if(nums[m] == nums[j])
            {
                j--;
            }
            else if(nums[m] > nums[i])
            {
                if(target<=nums[m] && target>=nums[i])
                    j = m-1;
                else
                    i = m+1;
            }
            else
            {
                if(target>=nums[m] && target<=nums[j])
                    i = m+1;
                else
                    j=m-1;
            }
        }
        return false;
    }
};
```
