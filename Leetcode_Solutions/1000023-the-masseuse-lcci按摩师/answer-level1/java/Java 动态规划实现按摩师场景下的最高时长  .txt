### 解题思路
解题思路:动态规划
针对后面某一位的确定分为两种情况，一种选择自己不种是不选择自己。因此有如下转移方程：
f(n) = Math.max(f(n - 1), f(n - 2) + nums[n])
当前位置的结果要么等于前一个位置的结果，要么是倒数第二个位置的结果加上当前位置的结果

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        int[] ans = new int[nums.length];
        ans[0] = nums[0];
        ans[1] = Math.max(nums[0], nums[1]);

        for (int i = 2; i < nums.length; i++) {
            ans[i] = Math.max(ans[i - 1], ans[i - 2] + nums[i]);
        }

        return ans[nums.length - 1];
    }
}
```