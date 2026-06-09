![image.png](https://pic.leetcode-cn.com/622477bcca45781543c9ee81d20be45dc90aebf642d78139c73515ac32b6d191-image.png)

class Solution {
    public int missingNumber(int[] nums) {
        int result = nums[0]^nums.length;
        for(int i=1;i<nums.length;i++){
            result = result^i^nums[i];
        }
        return result;
    }
}