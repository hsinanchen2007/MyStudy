```
class Solution {
    public int maximumProduct(int[] nums) {
        if(nums.length<3) return 0;
        Arrays.sort(nums);
        int i = nums.length-1;
        int max1 = nums[i] * nums[i-1] * nums[i-2]; //全正（最大的正数） 或 全负（得到最大的负数）
        int max3 = nums[0] * nums[1] * nums[i]; // 有负数（- -..... + +）
        int max =Math.max(max1, max3);
        return max;
    }
```
