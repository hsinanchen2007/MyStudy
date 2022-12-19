### 解题思路
dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i])的推导：
![QQ图片20200324224045.jpg](https://pic.leetcode-cn.com/5c9baad7467335ada84d9709fe3adf60a5e6fc31dbddaf8e39cf194fa12558fa-QQ%E5%9B%BE%E7%89%8720200324224045.jpg)


### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int n = nums.length;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
}

```