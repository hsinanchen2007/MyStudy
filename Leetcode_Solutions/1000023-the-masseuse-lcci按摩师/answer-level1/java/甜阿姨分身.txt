### 解题思路
今天又是闷头克隆了一遍甜阿姨的脑细胞，什么时候克隆出来个甜阿姨本尊就好了，不求多的，甜阿姨附体也好

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