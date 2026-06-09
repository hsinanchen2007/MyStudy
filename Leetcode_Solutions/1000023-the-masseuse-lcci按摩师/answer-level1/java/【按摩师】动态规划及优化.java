### 解题思路
这道题算是一道入门级的经典dp题。设$f(i)$为前`i`个请求的最长预约时间，对于第`i`个请求，我们可以：
- **选**，那么第`i - 1`个预约就不能选，此时$f(i)=f(i-2)+nums[i]$
- **不选**，此时$f(i) = f(i-1)$
由于我们无法直接判断上面两种选择哪种更优，所以我们需要取二者较大值，即
$f(i) = max(f(i-1),\ f(i-2)+nums[i])$

基于此，我们最朴素的代码就很容易写出来了。
```java
class Solution {
    public int massage(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[dp.length - 1];
    }
}
```

### 优化
这题的优化主要是空间上的优化，而动态规划在空间上的优化有一个很明显的特征：
> **在状态转移的时候，不需要取遍已求所有dp值**

也就是说，在求解第`i`个问题时，不需要全部用到前`i-1`个问题的结果，比如这道题，状态转移方程为：
`dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i])`
求`dp[i]`的时候，只需要`dp[i - 1]`和`dp[i - 2]`的结果，那么，我们可以只用两个变量保存$f(i-1)$和$f(i-2)$这两个子问题的结果，就可以依次计算出所有的子问题：

```java
class Solution {
    public int massage(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int prev = 0, curr = 0;
        for (int num : nums) {
            // curr 表示 dp[i - 1]，prev 表示 dp[i - 2]
            // dp[i] = max(dp[i - 1], dp[i - 2] + num)
            int temp = Math.max(curr, prev + num);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
}
```