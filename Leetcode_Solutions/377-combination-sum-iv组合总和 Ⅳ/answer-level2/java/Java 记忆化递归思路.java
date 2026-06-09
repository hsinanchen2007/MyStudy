### 解题思路

记住要让dp的初值赋值为 -1

刚开始赋值为0，一直超时，后来发现当也需要缓存dp值为0的情况

### 代码

```java
class Solution {
    int[] nums;
    int n;
    int[] dp;
    public int combinationSum4(int[] nums, int target) {
        this.nums = nums;
        this.n = nums.length;
        dp = new int[target + 1];
        Arrays.fill(dp, -1);
        return backtrack(target);      
    }

    int backtrack(int target) {
        if (target < 0) return 0;
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];
        int res = 0;
        for (int i = 0; i < n; i ++) {
            res += backtrack(target - nums[i]);
        }
        dp[target] = res;
        return res;
    }
}
```