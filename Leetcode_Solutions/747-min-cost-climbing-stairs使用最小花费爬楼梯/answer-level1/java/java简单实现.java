### 解题思路
一开始看到题目我也很懵逼，后面看明白了其实就是前后各加两个台阶，作为起点和终点，cost均为0。
构建一个dp数组，表示从当前阶梯再往上跳，所需要的最小cost，由于还要继续往上跳，这里的dp包括自身cost。

先计算到dp[cost.length - 1]，最后一步就是判断，到底是从倒数第一个台阶跳过来，还是倒数第二个台阶。当然是取最小值。
![image.png](https://pic.leetcode-cn.com/d2e2a23896a89a8fe70d86cc41a0d5509fc9e9b869370777311dd5356c7bb189-image.png)



### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if (cost.length == 2) {
            return 0;
        }

        int[] dp = new int[cost.length + 3];

        //头两个为起点阶梯
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 0; i < cost.length; i++) {
            dp[i+2] = Math.min(dp[i], dp[i + 1]) + cost[i];
        }
        dp[cost.length + 2] = Math.min(dp[cost.length + 1], dp[cost.length]);
        return dp[cost.length + 2];
    }
}
```