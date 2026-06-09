### 解题思路

dp数组表示一个数能否有nums里面的数字组成

其中0表示还未处理过这个数， 1表示处理过这个数，不能组成

2表示处理过这个数，能组成


### 代码

```java
class Solution {
    int[] dp;
    int[] nums;
    int n;
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int total = 0;
        this.nums = nums;
        this.n = nums.length;
        for (int i = 0; i < nums.length; i ++) {
            total += nums[i];
        }
        
        if (total % 2 == 1) return false;
        total /= 2;
        dp = new int[total + 1];
        return helper(total, 0) == 2;
    }

    int helper(int amount, int start) {
        if (amount < 0) return 1;
        if (amount == 0) return 2;
        if (dp[amount] > 0) return dp[amount];
        int res = 0;
        for (int i = start; i < n; i ++) {
            int ret = helper(amount - nums[i], i + 1);
            if (ret == 2) {
                res = 2;
                break;
            } else if (ret == 1) {
                res = 1;
            }
        }
        return dp[amount] = res;
    }
}
```