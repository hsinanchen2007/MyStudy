二分递归方法 复杂度保持在O(lgn)
```
class Solution {
public:
    int f(int l, int r, vector<int>& nums)
    {
        int mid = l + (r - l) / 2;
        int t = 0;
        if(mid==l)
            return nums[mid]<=nums[r]?nums[mid]:nums[r];
        if(nums[mid]==nums[r])
        {
            int a = f(l,mid,nums);
            int b = f(mid+1,r,nums);
            return a<=b?a:b;
        }
        else if(nums[mid]<nums[r])
        {
            t = f(l,mid,nums);
        }
        else{
            t = f(mid+1,r,nums);
        }
        return t;
    }
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int left = 0;
        int right = nums.size()-1;
        int r = f(left,right,nums);
        return r;
    }
};
```
