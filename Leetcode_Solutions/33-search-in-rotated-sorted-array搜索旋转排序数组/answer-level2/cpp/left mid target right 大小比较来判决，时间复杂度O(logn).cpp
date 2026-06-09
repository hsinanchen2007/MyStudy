### 解题思路


### 代码

```cpp
class Solution {
public:
    int s(vector<int>& nums,int l,int r,int target)
    {
        if(l>r)return -1;
        if(nums[l]==target)return l;
        if(nums[r]==target)return r;
        int mid=(l+r)/2;if(nums[mid]==target)return mid;
        if(nums[mid]<nums[r])
        {
            if((target>=nums[r])||(target<nums[mid]))
                return s(nums,l,mid-1,target);
            else
                return s(nums,mid+1,r,target);
        }
        else 
        {
            if(target<=nums[l]||target>nums[mid])
                return s(nums,mid+1,r,target);
            else
                return s(nums,l,mid-1,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return -1;
        return s(nums,0,nums.size()-1,target);
    }
};
```