class Solution {
    public int rob(int[] nums) {
        if(nums.length==0) return 0;
        if(nums.length == 1) return nums[0];
        int[] values = new int[nums.length];//values[i]表示到达第i天时最多可偷的金额
        values[0] = nums[0];//第一天单独处理 就是第一天的金额
        values[1] = Math.max(values[0],nums[1]);//第二天也单独处理 到第2天偷的最多为第一天偷金额和第二天偷金额的最大值
        for(int i = 2; i<nums.length; i++) {
            values[i] = Math.max(values[i-1],values[i-2]+nums[i]);//之后第i天偷的 为第i-1天和第i-2天加上第i天本身金额的最大值
        }
        return values[nums.length-1];
    }
}