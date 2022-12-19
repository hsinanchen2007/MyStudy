### 解题思路

若nums[mid]！= target
先判断是左区间有序还是右区间有序，再判断target在左区间还是在右区间。

### 代码

```cpp
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int low=0,high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(target==nums[mid]) return mid;

            if(nums[low]<=nums[mid])  /////左区间有序
            {
                if(target>=nums[low]&&target<nums[mid])   ////target在左区间
                    high=mid-1;
                else low=mid+1;
            }

            else                     ///右区间有序
            {
                if(target>nums[mid]&&target<=nums[high])    ////target在右区间
                    low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
};
```