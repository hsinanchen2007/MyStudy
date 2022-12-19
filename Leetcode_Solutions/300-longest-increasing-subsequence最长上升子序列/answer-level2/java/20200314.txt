### 解题思路
明人不说暗话，抄的作业，dp还是写的脑瓜子疼

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
     if (nums.length < 1) return 0;
        int[] dp = new int[nums.length];
        int max = 1;
        Arrays.fill(dp, 1);
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
//                max = Math.max(dp[i], max);
            }
            max = Math.max(dp[i], max);
        }
        return max;
    }
}
```