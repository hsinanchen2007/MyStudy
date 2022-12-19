### 解题思路
java动态规划

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length<=0) return 0;
        int[] dp = new int[nums.length];
        int resmax = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            int t=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) t = Math.max(t,dp[j]);
            }
            dp[i] = t+1;
            resmax = Math.max(resmax,dp[i]);
        }
        return resmax;
    }
}
```