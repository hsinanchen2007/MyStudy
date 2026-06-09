### 解题思路
动态规划：
- dp[i] 表示以 nums[i] 结尾的最长子序列的长度
- dp[i] = max{dp[j]}+1，j 取值范围 [0,i-1]
- dp[0]=1

### 代码

```java
public class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        // dp[i] 表示以 nums[i] 结尾的最长子序列的长度
        int[] dp = new int[nums.length];

        // dp[0] 是以 nums[0] 结尾的最长子序列的长度，由于前面没有其他元素，所以是1
        dp[0] = 1;
        int maxans = 1;

        // 从 i=1 开始计算 dp[i]
        for (int i = 1; i < dp.length; i++) {
            int maxval = 0;
            // 当计算 dp[i] 时，对 i 前面任何一个子序列
            // 若 nums[i] > nums[j]，则 dp[i] = dp[j]+1，j可能是 0~i-1中的任何一个
            // 若找不到这样的 j ，则 dp[i]=1
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