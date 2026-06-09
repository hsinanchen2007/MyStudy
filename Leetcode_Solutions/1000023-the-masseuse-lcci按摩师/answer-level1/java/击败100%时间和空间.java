### 解题思路
![image.png](https://pic.leetcode-cn.com/30c99a6e586f84577aa9ca59007efa93a230374f5110ddf423c7d4414fd16bd8-image.png)

打家劫舍那道题，典型的动态规划，滚动数组优化。

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        
        if(nums.length == 1) {
            return nums[0];
        }
        
        int n = nums.length;
        int[] dp = new int[2];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++) {
            dp[i % 2] = Math.max(dp[(i - 1) % 2], dp[(i - 2) % 2] + nums[i]);
        }
        
        return dp[(n - 1) % 2];
    }
}
```