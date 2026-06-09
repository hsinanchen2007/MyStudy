### 解题思路
理解题目是关键。这里换一种方式，用旅行的方式来看待问题。

想象你是一个游客，此时站在景点大门外，每一个台阶是一个收费景点，进这个景点就要收费，如果某个景点你认为太贵，你可以跳过，但是作为奖励楼顶这个景点免费。你并不是富二代，你考虑化最少的钱到达楼顶这个景点。

### 算法
动态规划
- i表示编号第i个景点门票费用cost[i]。
- 状态dp[i]表示达到第i个景点总共话费的最少费用。
- 状态转移方程，dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]
- 楼顶景点就是编号为count(cost)的景点，门票为0.

### 代码

```php
class Solution {

    /**
     * @param Integer[] $cost
     * @return Integer
     */
    function minCostClimbingStairs($cost) {
        $dp = [];

        $dp[0] = $cost[0];
        $dp[1] = $cost[1];
        $len = count($cost);
        for ($i = 2; $i < $len; $i++) {
            $dp[$i] = min($dp[$i - 1], $dp[$i - 2]) + $cost[$i];
        }
        return min($dp[$len - 1], $dp[$len - 2]);
    }
}
```

### 算法复杂度
- 时间复杂度: O(N)
- 空间复杂度：O(N)

### 参考
[https://leetcode-cn.com/problems/min-cost-climbing-stairs/solution/dong-tai-gui-hua-by-liweiwei1419-3/](https://leetcode-cn.com/problems/min-cost-climbing-stairs/solution/dong-tai-gui-hua-by-liweiwei1419-3/)
[https://leetcode-cn.com/problems/min-cost-climbing-stairs/comments/13058](https://leetcode-cn.com/problems/min-cost-climbing-stairs/comments/13058)