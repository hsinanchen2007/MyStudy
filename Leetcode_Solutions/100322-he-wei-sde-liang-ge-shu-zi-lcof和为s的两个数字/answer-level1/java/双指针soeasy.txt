```
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int left=0;
        int right = nums.length-1;
        int[] res = new int[2];
        while(left<right){
            if(nums[right]>target){
                right--;
                continue;
            }
            if(nums[right]+nums[left]<target){
                left++;
            }
            else if(nums[right]+nums[left]>target){
                right--;
            }
            else if(nums[right]+nums[left]==target){
                res[0]=nums[right];
                res[1]=nums[left];
                break;
            }
        }
        return res;
    }
}
```
