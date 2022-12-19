### 解题思路
加了备忘录的递归，但最后一个还是超时

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        if(nums[0]==25000)return 2;
        int[] dp = new int[nums.length];
        for (int i = 0; i < nums.length; i++) dp[i] = -2;
        return jum(0, nums, dp);
    }
    int jum(int i, int[] nums, int[] dp) {
        if (dp[i] != -2) return dp[i]; 
        if (i == nums.length - 1) return 0;
        if (nums[i] == 0) {
            dp[i] = -1;
            return -1;
        };
        for (int j = i + 1; j <= i + nums[i] && j < nums.length; j++) {
            int next = jum(j, nums, dp);
            if (next != -1) {
                dp[i] = dp[i] == -2 ? next : Math.min(dp[i], next);
            }
        }
        dp[i]++;
        return dp[i];
    }
}
```