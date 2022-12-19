### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int len = nums.length;
        if(len == 0)
            return 0;
        int[] dp = new int[len + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= len; i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[len];
    }

 }

```
以i位置为例，该位置只有两种情况，要么选要么不选。如果选的话，可以加上前i-2的结果，如果不选的话，则选前i-1的结果。
然后比较这两种情况的值，选最大的。