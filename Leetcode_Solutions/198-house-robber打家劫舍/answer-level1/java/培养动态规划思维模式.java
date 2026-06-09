### 解题思路
原来简单的思考只要一个跳一个的加在一起即可，后来考虑到这种用例10,1,1,10，就搞不动了，还是需要动态规划来搞定。
动态规划是一种自底向上的方法，先考虑最简单的，一步步推导出动态规划方程，用for循环迭代计算出结果。

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        if (nums.length == 1) {
            return dp[0];
        }
        dp[1] = Math.max(dp[0], nums[1]);
        if (nums.length == 0 || nums.length == 1) {
            return dp[nums.length];
        }
        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.length - 1];
    }
}
```