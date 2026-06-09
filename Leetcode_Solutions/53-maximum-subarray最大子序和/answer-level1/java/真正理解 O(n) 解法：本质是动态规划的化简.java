这道题最快、最简洁的题解代码应该是这样的，时间复杂度 $O(n)$：

```Java []
public int maxSubArray(int[] nums) {
    int sum = 0;
    int res = Integer.MIN_VALUE;
    for (int n : nums) {
        if (sum < 0) {
            sum = 0;
        }
        sum += n;
        res = Math.max(res, sum);
    }
    return res;
}
```

这是个贪心算法，我们加点注释来理解一下：

```Java []
public int maxSubArray(int[] nums) {
    int sum = 0; // 记录当前的和
    int res = Integer.MIN_VALUE;
    for (int n : nums) {
        // 如果累加到小于0了，就清零重新累加
        if (sum < 0) {
            sum = 0;
        }
        sum += n; // 累加
        res = Math.max(res, sum);
    }
    return res;
}
```

但是这个贪心算法不是很好理解。这次看会了，下次又忘了，还是做不出来。

好消息是，我们可以用动态规划的方法来理解这段代码。这道题用动态规划的方法同样可以得到时间复杂度 $O(n)$ 的解法，而且代码化简之后，竟然和贪心算法一模一样！

## 动态规划的解法

我们要记住动态规划的解题四步骤：

+ 定义子问题
+ 写出子问题的递推关系
+ 确定 DP 数组的计算顺序
+ 空间优化（可选）

关于四步骤的基础讲解可以参考我在“198. 打家劫舍”问题下的题解：[图解动态规划的解题四步骤](https://leetcode-cn.com/problems/house-robber/solution/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap/)，以经典的打家劫舍问题为例讲解了这四个步骤。

首先，我们定义子问题 $f(k)$ 表示**子数组 `nums[0..k)​`（左闭右开）中以 `num[k-1]` 结尾的最大子数组和**。则原问题为 $\displaystyle \max_{1\le k \le N} f(k)$。

子问题的递推关系：

+ $f(0) = 0$
+ $f(k) = \max \{ f(k-1) + n_{k-1}, n_{k-1}  \} = \max \{ f(k-1), 0 \} + n_{k-1}$

DP 数组从左到右计算即可。

这样我们可以写出题解代码（根据题意，输入数组一定不为空）：

```Java []
public int maxSubArray(int[] nums) {
    // f(k): max subarray sum of nums[0..k), ending with nums[k-1]
    // res = max { f(k) }

    // f(0) = 0
    // f(k) = max{ f(k-1), 0 } + nums[k-1]

    int N = nums.length;
    int[] dp = new int[N+1];
    dp[0] = 0;

    int res = Integer.MIN_VALUE;
    for (int k = 1; k <= N; k++) {
        dp[k] = Math.max(dp[k-1], 0) + nums[k-1];
        res = Math.max(res, dp[k]);
    }
    return res;
}
```

## 动态规划的化简

首先，我们可以做空间优化，不需要保存整个一维 dp 数组，用单个变量保存即可：

```Java []
public int maxSubArray(int[] nums) {
    int dp = 0;
    int res = Integer.MIN_VALUE;
    for (int k = 1; k <= nums.length; k++) {
        dp = Math.max(dp, 0) + nums[k-1];
        res = Math.max(res, dp);
    }
    return res;
}
```

其中的 for 循环还可以下标优化，变成 for-each 循环：

```Java []
public int maxSubArray(int[] nums) {
    int dp = 0;
    int res = Integer.MIN_VALUE;
    for (int n : nums) {
        dp = Math.max(dp, 0) + n;
        res = Math.max(res, dp);
    }
    return res;
}
```

再做点代码上的等价变换，改个变量名：

```Java []
public int maxSubArray(int[] nums) {
    int sum = 0;
    int res = Integer.MIN_VALUE;
    for (int n : nums) {
        if (sum < 0) {
            sum = 0;
        }
        sum += n;
        res = Math.max(res, sum);
    }
    return res;
}
```

妙啊！竟然和上面那个贪心算法的代码一模一样了！
