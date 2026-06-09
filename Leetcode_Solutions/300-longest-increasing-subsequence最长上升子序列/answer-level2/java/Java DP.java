### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int maxLen = 0;
        int[] dp = new int[nums.length];

        for (int i=0; i<nums.length; ++i) {
            int cnt = 1;
            for (int j=0; j<i; ++j) {
                if (nums[j] < nums[i])
                    cnt = Math.max(dp[j]+1, cnt);
            }
            dp[i] = cnt;
            maxLen = Math.max(cnt, maxLen);
        }
        return maxLen;
    }
}
```