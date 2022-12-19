### 解题思路
此处撰写解题思路
- 这是官方题解，本人的解题思路把所有结果都存了下来。对没看错，将所有结果都记录了
- 自己蠢就蠢在没理解到dp算法的内涵，找最优解，并不是找最快解。记录下给自己提个醒
### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int maxans = 1;
        for (int i = 1; i < dp.length; i++) {
            int maxval = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    maxval = Math.max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
            maxans = Math.max(maxans, dp[i]);
        }
        return maxans;
    }
}
```