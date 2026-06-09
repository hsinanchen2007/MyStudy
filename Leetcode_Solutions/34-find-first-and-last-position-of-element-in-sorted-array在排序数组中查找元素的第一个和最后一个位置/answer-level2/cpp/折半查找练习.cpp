### 解题思路
用两次折半查找，一次确定上边界，一次确定下边界。

### 代码

```cpp
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res={-1,-1};
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            if(target==nums[mid])
            {
                if(mid==nums.size()-1) res[1]=mid;            ///找上边界
                else if(nums[mid+1]>target) res[1]=mid;
            }
            if(target<nums[mid]) high=mid-1;
            else if(target>=nums[mid]) low=mid+1;
        }

        int low1=0,high1=nums.size()-1;
        while(low1<=high1)
        {
            int mid1= low1+(high1-low1)/2;
            if(target==nums[mid1])
            {
                if(mid1==0)res[0]=mid1;
                else if(nums[mid1-1]<target)res[0]=mid1;   ///找下边界
            }
            if(target<=nums[mid1]) high1=mid1-1;
            else if(target>nums[mid1]) low1=mid1+1;
        }
        return res;
    }
};
```