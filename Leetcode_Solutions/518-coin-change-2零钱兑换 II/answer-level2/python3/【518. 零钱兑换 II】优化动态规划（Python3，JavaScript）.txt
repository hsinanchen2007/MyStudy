## 思路

这个题目和 coin-change 的思路比较类似。

我们还是按照 coin-change 的思路来， 如果将问题画出来大概是这样：

![](https://pic.leetcode-cn.com/938c2818594e6b01de19f4e752552bc21635e61c26a180cbb22bc7cd3eeade0b.jpg)

进一步我们可以对问题进行空间复杂度上的优化（这种写法比较难以理解，但是相对更省空间）

![](https://pic.leetcode-cn.com/cba23c4473317389166b17cda8b185010735c786d1f196ffc1908d8d55bbf5f3.jpg)

> 这里用动图会更好理解， 有时间的话我会做一个动图出来， 现在大家脑补一下吧

## 关键点解析

- 动态规划

- 子问题

用 dp[i] 来表示组成 i 块钱，需要最少的硬币数，那么

1. 第 j 个硬币我可以选择不拿 这个时候， 组成数 = dp[i]

2. 第 j 个硬币我可以选择拿 这个时候， 组成数 = dp[i - coins[j]] + dp[i]

- 和背包问题不同， 硬币是可以拿任意个

- 对于每一个 dp[i] 我们都选择遍历一遍 coin， 不断更新 dp[i]

eg:

```js
if (amount === 0) return 1;

const dp = [Array(amount + 1).fill(1)];

for (let i = 1; i < amount + 1; i++) {
  dp[i] = Array(coins.length + 1).fill(0);
  for (let j = 1; j < coins.length + 1; j++) {
    // 从1开始可以简化运算
    if (i - coins[j - 1] >= 0) {
      // 注意这里是coins[j -1]而不是coins[j]
      dp[i][j] = dp[i][j - 1] + dp[i - coins[j - 1]][j]; // 由于可以重复使用硬币所以这里是j不是j-1
    } else {
      dp[i][j] = dp[i][j - 1];
    }
  }
}

return dp[dp.length - 1][coins.length];
```

- 当我们选择一维数组去解的时候，内外循环将会对结果造成影响

![](https://pic.leetcode-cn.com/aac8f9b98963f2854f65ec08e6161af6c4d4b73d4a075d2086fd3437b4211620.jpg)

eg:

```js
// 这种答案是不对的。
// 原因在于比如amount = 5, coins = [1,2,5]
// 这种算法会将[1,2,2] [2,1,2] [2, 2, 1] 算成不同的

if (amount === 0) return 1;

const dp = [1].concat(Array(amount).fill(0));

for (let i = 1; i < amount + 1; i++) {
  for (let j = 0; j < coins.length; j++) {
    if (i - coins[j] >= 0) {
      dp[i] = dp[i] + dp[i - coins[j]];
    }
  }
}

return dp[dp.length - 1];

// 正确的写法应该是内外循环调换一下, 具体可以看下方代码区
```

## 代码


代码支持：Python3，JavaScript：


JavaSCript Code:

```js
/*
 * @lc app=leetcode id=518 lang=javascript
 *
 * [518] Coin Change 2
 *
 */
/**
 * @param {number} amount
 * @param {number[]} coins
 * @return {number}
 */
var change = function(amount, coins) {
  if (amount === 0) return 1;

  const dp = [1].concat(Array(amount).fill(0));

  for (let j = 0; j < coins.length; j++) {
    for (let i = 1; i < amount + 1; i++) {
      if (i - coins[j] >= 0) {
        dp[i] = dp[i] + dp[i - coins[j]];
      }
    }
  }

  return dp[dp.length - 1];
};
```

Python Code:

```
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1

        for j in range(len(coins)):
            for i in range(1, amount + 1):
                if i >= coins[j]:
                    dp[i] += dp[i - coins[j]]

        return dp[-1]
```


**复杂度分析**
- 时间复杂度：$O(amount * len(coins))$
- 空间复杂度：$O(amount)$

## 扩展

这是一道很简单描述的题目， 因此很多时候会被用到大公司的电面中。

相似问题:

[322.coin-change](https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-you-hua-dong-tai-gui-hua-c-/)

## 附录

Python 二维解法（不推荐，但是可以帮助理解）：

```python
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [[0 for _ in range(len(coins) + 1)] for _ in range(amount + 1)]
        for j in range(len(coins) + 1):
            dp[0][j] = 1

        for i in range(amount + 1):
            for j in range(1, len(coins) + 1):
                if i >= coins[j - 1]:
                    dp[i][j] = dp[i - coins[j - 1]][j] + dp[i][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]
        return dp[-1][-1]
```

**复杂度分析**
- 时间复杂度：$O(amount * len(coins))$
- 空间复杂度：$O(amount * len(coins))$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
