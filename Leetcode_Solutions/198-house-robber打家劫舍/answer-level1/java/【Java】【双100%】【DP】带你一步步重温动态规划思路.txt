### 写在前面：
如果您觉得写得还可以，那就来关注在下的微信公众号吧“张氏文画”，不光有新鲜的 LeetCode 题解（多种思路，包教包会，开拓思维），还有经典的文章及短视频和大家分享，谢谢大家的关注！！！
![qrcode_for_gh_671e52fa1e78_258.jpg](https://pic.leetcode-cn.com/fa6a229fc23d58fb656a375382f96feecd9b6bc043183f36ee0d9ea9ffa3a12e-qrcode_for_gh_671e52fa1e78_258.jpg)

### 思路一：

其实，思考题意，可以发现，合格的小偷永远不会连续放过3个房屋而不偷点东西。

为什么呢？因为合格的小偷总是可以选择偷盗中间的房屋。

**哈哈，接下来进入正题：我们一步步来还原经典的 动态规划 思路**

#### 第 1 步：定义状态

``dp[i]``：区间 [0，i] 里可偷得的最大金额。

#### 第 2 步：定义状态转移方程

可以看到，我们没有限定是否偷盗下标为 i 的这个房屋，因此需要分情况：

- 偷盗当前房屋，那么就一定不会偷盗上一间相邻的房屋，由于状态 ``dp[i - 1]`` 的定义涵盖了偷盗下标为 i - 1 这一间房屋的情况，因此状态只能从下标为 i - 2 的状态转移而来，即：``dp[i - 2] + nums[i]``;
- 不偷盗当前房屋，那么上一间相邻的房屋可以选择偷，也可以不偷，状态从下标为 i - 1 的状态转移而来：``dp[i - 1]``；
- 二者取最大值，因此最终的状态转移方程为：``dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])``

#### 第 3 步：定义相关初始化

观察我们的状态转移方程，下标最小到 i - 2，因此初始化的时候要把 ``dp[0]`` 和 ``dp[1]`` 表示出来，从 ``dp[2]`` 开始计算。
- dp[0]：只有 1 间房屋的时候，作为一名合格的小偷，必须得偷啊，不能空手而归啊，因此 ``dp[0] = nums[0]``；
- dp[1]：当有多于一间房屋的时候，对于前两间，由于不能都偷窃，会触发警告，因此最优值是这两间房屋里现金数量的最大值，即 ``dp[1] = max(nums[0], nums[1])``；

#### 第 4 步：定义输出

鉴于我们定义的状态有前缀性质，并且对于下标为 i 的这间房屋也考虑了被偷与不被偷的情况，因此输出就是最后一间房屋的状态值。

#### 第 5 步：是否可以状态压缩（见 思路二）

其实，观察我们自定义的状态转移方程。**当前状态只与前两个状态相关**，而我们只关心最后一间房屋的状态值，因此可以使用 **「滚动变量」** 的技巧，不过，这样的代码就丢失了可读性。

### 代码：

时间复杂度O(n)，空间复杂度O(n)

```java
class Solution {
    public int rob(int[] nums) {
        // 边界情况处理，养成良好的编码习惯
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int len = nums.length;
        if (len == 1) {
            return nums[0];
        }
        
        int [] dp = new int [len];
        // 初始化
        dp[0] = nums[0];
        dp[1] = Math.max(nums[1], nums[0]);

        for (int i = 2; i < len; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        return dp[len - 1];
    }
}
```

### Result：

Runtime：0ms

Your runtime beats 100% of java submissions.

### 思路二：

接思路一的第五步：是否可以状态压缩，从而能够在O(n)时间复杂度和O(1)额外空间复杂度内解答该题。

```math
dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
```

其实，观察我们自定义的状态转移方程。**当前状态只与前两个状态相关**，而我们只关心最后一间房屋的状态值，因此可以使用 **「滚动变量」** 的技巧，不过，这样的代码就丢失了可读性。

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public int rob(int[] nums) {
        // 边界情况处理，养成良好的编码习惯
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int len = nums.length;
        if (len == 1) {
            return nums[0];
        }
        
        int premax = 0, prepremax = 0;
        for (int i = 0; i < len; i++) {
            int max = Math.max(premax, prepremax + nums[i]);
            prepremax = premax;
            premax = max;
        }
        
        return premax;
    }
}
```

### Result：

Runtime：0ms

Your runtime beats 100% of java submissions.