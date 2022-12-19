执行用时 : 1 ms, 在Find Peak Element的Java提交中击败了95.58% 的用户
内存消耗 : 35.3 MB, 在Find Peak Element的Java提交中击败了96.54% 的用户
```
class Solution {
    public int findPeakElement(int[] nums) {
        int i = 0;
        if(nums.length==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[nums.length-1]>nums[nums.length-2]) return nums.length-1;
        int l=0;
        int r=nums.length-1;
        int m=(l+r)/2;
        while(l<r && m-1>=0 && m+1<=nums.length-1){
            if(nums[m]<=nums[m+1]) l=m;
            else r=m;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1]) break;
            m=(l+r)/2;
        }
        return m;
    }
}
```