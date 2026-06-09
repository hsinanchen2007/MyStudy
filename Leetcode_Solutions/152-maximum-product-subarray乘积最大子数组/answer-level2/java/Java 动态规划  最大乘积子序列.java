### 解题思路
1. 暴力求解

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }

        // 暴力求解
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int max = nums[i];
            int sum = 1;
            // 求出每一个index作为开始的子数组的最大值
            for (int j = i; j< nums.length; j++) {
                sum *= nums[j];
                if (sum > max) {
                    max = sum;
                }
            }
            nums[i] = max;
        }

        int max = nums[0];
        // 遍历找到最大乘积
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }
}
```

### 解题思路
2. 动态规划

### 代码
、、、
class Solution {
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }

        int[][] dp = new int[nums.length][2]; // 考虑正负数的情况，需要dp数组保存一个max和一个min
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.length; i++) {
            // max存放与当前元素相乘之后的最大值
            int max = nums[i] >= 0 ? dp[i - 1][0] * nums[i] : dp[i - 1][1] * nums[i];
            dp[i][0] = Math.max(max, nums[i]); // 最终结果需要和nums[i]进行比较确定是否需要前面的元素

            // min存放与当前元素相乘之后的最小值
            int min = nums[i] >= 0 ? dp[i - 1][1] * nums[i] : dp[i - 1][0] * nums[i];
            dp[i][1] = Math.min(min, nums[i]); // 最终min需要和当前nums[i]进行比较确定是否需要前面的元素

            if (dp[i][0] > result) { // result始终存放当前找到的最大值！！！
                result = dp[i][0];
            }
        }

        return result;
    }
}
、、、