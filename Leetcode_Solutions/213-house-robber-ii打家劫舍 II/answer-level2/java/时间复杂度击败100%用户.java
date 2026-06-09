### 解题思路
把最后一个排除，算出最大和；
把第一个排除，算出最大和；
两个结果集取最大；
![image.png](https://pic.leetcode-cn.com/21d48359d65cf0594ad340f5d2c2e5f58f653297d0720bbd0de6cecef8e31e38-image.png)

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums==null||nums.length==0) return 0;
        if (nums.length == 1) return nums[0];
        if (nums.length == 2) return Math.max(nums[0], nums[1]);
        int dp[] = new int[nums.length - 1];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length - 1; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int ap[] = new int[nums.length - 1];
        ap[0] = nums[1];
        ap[1] = Math.max(nums[1], nums[2]);
        for (int i = 2; i < nums.length - 1; i++) {
            ap[i] = Math.max(ap[i - 1], ap[i - 2] + nums[i + 1]);
        }
        return Math.max(dp[nums.length - 2], ap[nums.length - 2]);
    }
}
```