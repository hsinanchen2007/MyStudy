### 解题思路
新建一个数组，将以原数组每一位为结尾的子数组中做大的上升子数组的大小存入到新数组，最后找到新数组中的最大值，即为最大上升子数组

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        /**
         * 首先判断数组长度
         */
        if (nums.length == 0) {
            return 0;
        }
        /**
         * dp数组用于存放以nums[i]结尾的最大上升子序列的长度
         */
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int maxans = 1;
        /**
         * 外层遍历整个数组
         */
        for (int i = 1; i < dp.length; i++) {
            int maxval = 0;
            /**
             * 内层遍历子数组
             */
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