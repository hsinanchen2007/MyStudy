用动态规划的思路求解，其中dp[i][j]表示用了前i个元素，和为j的组合数目。需要注意的有以下几点：
* 需要结合题目中的总和不超过1000这个条件
* 动态规划的过程中会用到当前位置前面和后面的元素，所以最少需要两行来求解。我们可以交替的使用这两行。（用求余的思想）

```java
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int l = nums.length;
        int ms = 1000;
        if(l == 0){
            return 0;
        }
        if(S > ms){
            return 0;
        }
        int[][] dp = new int[2][ms*2 + 1];
        dp[0][nums[0]+ms] += 1;
        dp[0][-1*nums[0]+ms] += 1;
        // for(int k = 0;k<=ms*2;k++){
        //     System.out.print(dp[0][k]);
        // }
        // System.out.println();
        for(int i =1;i<l;i++){
            int idx = i % 2;
            int pre = 1 - idx;
            for(int j = 0;j<=2*ms;j++){
                dp[idx][j] = 0;
                if(j - nums[i] >= 0){
                    dp[idx][j] += dp[pre][j - nums[i]];
                }
                if(j + nums[i] <= ms * 2){
                    dp[idx][j] += dp[pre][j + nums[i]];
                }
            }
            // for(int k = 0;k<=ms*2;k++){
            //     System.out.print(dp[idx][k] + "   ");
            // }
            // System.out.println();
        }
        return dp[1-l%2][S+ms];
    }
}
```