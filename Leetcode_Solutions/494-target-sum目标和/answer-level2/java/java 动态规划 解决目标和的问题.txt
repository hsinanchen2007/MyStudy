### 解题思路
假定dp[i][j]表示[0,i]范围内到目标j的方案个数，那么
dp[i][j] = dp[i-1][j+nums[i]]+dp[i-1][j-nums[i]]
考虑到数组越界，由于j最大为1000，最小为-1000，所以可以给数组的第二维增加2000
dp[i][j+2000] = dp[i-1][j+nums[i]+2000] + dp[i-1][j-nums[i]+2000]
这时候dp的定义就要是dp = new int[nums.length][4001]

### 代码

```java
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
            if(nums==null || nums.length ==0 || S>1000 || S<-1000){
            return 0;
        }
        int[][] dp = new int[nums.length][4001];
        dp[0][nums[0]+2000] = 1;
        dp[0][-nums[0]+2000] += 1;
        for(int i = 1;i<nums.length;i++){
            for(int j = -1000;j<=1000;j++){
                dp[i][j+2000] = dp[i-1][j+nums[i]+2000]+dp[i-1][j-nums[i]+2000];
            }
        }

        return dp[nums.length-1][S+2000];
    }
}
```