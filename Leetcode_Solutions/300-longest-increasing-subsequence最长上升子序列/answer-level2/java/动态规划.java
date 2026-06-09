### 解题思路
1、dp定义以i为结尾的最大升序子序列长度
2、nums[i] > nums[j]的时候才能更新长度
3、dp[i] = maxValue + 1

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int result = 1;
        for (int i = 1; i < nums.length; i++) {
            int maxValue = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    maxValue = Math.max(maxValue, dp[j]);
                }
            }
            dp[i] = maxValue + 1;
            result = Math.max(result, dp[i]);
        }
        return result;
    }
}
```