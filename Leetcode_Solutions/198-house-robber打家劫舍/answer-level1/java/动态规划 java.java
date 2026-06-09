
定义f(i,j) 为 nums[i] 到 nums[j] 的最优解， 求解 f(1,n)
递归定义：
f(i, n) = Max(nums[i] + f(i+2,n), f(i+1, n)) 分别对应 取nums[i] 跳过nums[i+1] 和忽略nums[i] 看从i+1开始的最优解

class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int len = nums.length;
        int tmp = 0, a = nums[len-1], b = Math.max(nums[len-1], nums[len-2]);
        for (int j = nums.length - 3; j >= 0; j--) {
            tmp = Math.max(nums[j] + a, b);
            a = b;
            b = tmp;
        }
        
        return b;
    }
}
