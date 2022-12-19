当左右两数之和大于目标值时，右边指针往左移，左右两数之和小于目标值时，左边指针往右移。直至找到目标位置。
```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int l=0,r=nums.length-1;
        int[] res=new int[2];
        while(l<=r){
            if(target==nums[l]+nums[r]){
                res[0]=nums[l];
                res[1]=nums[r];
                break;
            } else if(target<nums[l]+nums[r]){
                r--;
            }else{
                l++;
            }
        }
        return res;
    }
}
```
