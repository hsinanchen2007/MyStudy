class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        // 记录连续1个数
        int sum = 0;
        // 存最大的连续1个数
        int maxCount = Integer.MIN_VALUE;
       for (int i = 0; i < nums.length; i++) {
           // 为零就置零从新计算
           if(nums[i]==0) {
               // 重置
               sum=0;
           } else{
               // 累计
               sum+=nums[i];
           }
           // 复制
           if(sum>maxCount) {
               maxCount = sum;
           }
       } 
       return maxCount;
    }
}