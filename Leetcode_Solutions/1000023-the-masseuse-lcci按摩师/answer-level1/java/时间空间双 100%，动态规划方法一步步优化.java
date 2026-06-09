这道题和第 198 题 ”打家劫舍“ (House Robber) 是完全相同的题目，只是换了一个场景。

打家劫舍题目我已经写了详细的题解：[图解动态规划的解题四步骤](https://leetcode-cn.com/problems/house-robber/solution/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap/)，以一道题为例子讲了动态规划题目的解题四步骤。因为这道题完全相同，解法我就不赘述了。

那么正式开始我们的代码：

首先是常规的一维 DP 数组解法：

```Java []
public int massage(int[] nums) {
    if (nums.length == 0) {
        return 0;
    }
    // f(k): nums[0..k) 的最优结果
    
    // f(0) = 0
    // f(1) = nums[0]
    // f(k) = max{ f(k-1), f(k-2) + nums[k-1] }
    
    int N = nums.length;
    int[] dp = new int[N+1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int k = 2; k <= N; k++) {
        dp[k] = Math.max(dp[k-1], dp[k-2] + nums[k-1]);
    }
    return dp[N];
}
```

然后我们进行空间优化。这道题和斐波那契数列一样，可以只用两个变量记录中间结果：

```Java []
public int massage(int[] nums) {
    if (nums.length == 0) {
        return 0;
    }
    
    int prev = 0;
    int curr = nums[0];
    for (int k = 2; k <= nums.length; k++) {
        int next = Math.max(curr, prev + nums[k-1]);
        prev = curr;
        curr = next;
    }
    return curr;
}
```

再稍微优化一下数组下标：

```Java []
public int massage(int[] nums) {
    int prev = 0;
    int curr = 0;
    for (int num : nums) {
        int next = Math.max(curr, prev + num);
        prev = curr;
        curr = next;
    }
    return curr;
}
```

OK，一份简洁、高效的题解代码诞生了！

提交结果：

![](https://pic.leetcode-cn.com/18a559217a65a3a78ec90033b964d5cda4ad991d61c2d6504719c509cd5f5231.jpg)

---

如果你觉得本文对你有帮助，欢迎关注我的公众号《面向大象编程》，其中的《LeetCode 例题精讲》系列文章正在写作，不仅有题解，更能让你学会解题的通用思路，举一反三！

![](https://pic.leetcode-cn.com/d43932512708c2dc020640b967f7cecae44ba58562fd1da7deeb6c10c91e0d47.jpg)