```
class Solution {
    //动态规划：dp[i][j]含义：用nums的[0...i]元素能组成j的个数
    public int findTargetSumWays(int[] nums, int s) {
        //return process(nums, 0, s);
        int sum = 0;
        for(int i : nums) {
            sum += i;
        }
        //这种情况必须考虑，否则数组会越界
        if(s > sum || s < -sum) return 0;
        int rows = nums.length + 1;
        int cols = 2 * sum + 1;
        
        int[][] dp = new int[rows][cols];
        dp[rows - 1][sum] = 1;//0 ~ sum - 1是-sum ~ -1,sum是0,sum + 1 ~ 2*sum + 1是1 ~ sum
        for(int i = rows - 2; i >= 0; i--) {
            for(int j = 0; j < cols; j++) {
                dp[i][j] += j + nums[i] < cols ? dp[i + 1][j + nums[i]] : 0;
                dp[i][j] += j - nums[i] >= 0   ? dp[i + 1][j - nums[i]] : 0;
            }
        }
        return dp[0][s + sum];
        
        
    }
    
    //递归
    public int process(int[] nums, int i, int s) {
        if(i == nums.length) {
            return s == 0 ? 1 : 0;
        }
        int z = process(nums, i + 1, s - nums[i]);
        int f = process(nums, i + 1, s + nums[i]);
        return z + f;
    }
}
```
