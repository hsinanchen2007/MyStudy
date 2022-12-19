若使用遍历的方法查找，时间复杂度为O(n)。此处推荐使用二分查找法。使用二分查找法时间复杂度为O(logn)。
```C++ []
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        if(target>nums[r])return r+1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<target)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};
```