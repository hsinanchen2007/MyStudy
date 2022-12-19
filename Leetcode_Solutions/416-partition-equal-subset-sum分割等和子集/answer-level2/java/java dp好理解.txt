背包算法，稍微不同的地方在于，在背包算法问题中，如果当前物品重量和背包体积相同，我们需要判断是当前物品价值加上还可以拿的物品价值高，还是不拿当前的物品价值高。
对于这个问题而言，我们需要判断的是当前的物品价值能不能刚好满足我们要的值。
![backpack.jpg](https://pic.leetcode-cn.com/2bc4a6922b47f1d12b8c0331476d00720b3f81145f48e5433ad4c88c84e1a926-backpack.jpg)

这个是我第一次做这道题的时候画出的表格，虽然dp转换公式有点凌乱，但是我是一边画表格一边慢慢推导出来的，希望大家也可以按照这个思路慢慢推导出dp转换公式。
```
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        if(sum % 2 != 0) return false;
        int target = sum / 2;
       
        boolean[][] dp = new boolean[nums.length + 1][target + 1];  
        dp[0][0] = true;
        for(int j = 1; j <= target; j++){
            dp[0][j] = false;
        }
        for(int i = 1; i <= nums.length; i++){
            dp[i][0] = true;
        }

        for(int i = 1; i < dp.length; i++){
            for(int j = 1; j < dp[0].length; j++){
                if(nums[i - 1] > j){
                    dp[i][j] = dp[i - 1][j];
                }else if(nums[i - 1] <= j){
                    dp[i][j] = (dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]);
                }
            }
        }

        return dp[dp.length - 1][dp[0].length - 1];
    }
}
```
